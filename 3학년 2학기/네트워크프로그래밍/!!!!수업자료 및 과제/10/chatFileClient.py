# client.py
from socket import *
from threading import Thread
from tkinter import *
from tkinter.scrolledtext import ScrolledText
from tkinter import filedialog, messagebox
import os
import time

# 프로토콜은 서버와 동일:
# 텍스트: b"MSG|<len>|<sender>\n" + <payload>
# 파일:   b"FILE|<len>|<filename>|<sender>\n" + <payload>

class ChatClient:
    def __init__(self, ip='127.0.0.1', port=2500):
        self.server_ip = ip
        self.server_port = port
        self.sock = None
        self.recv_thread = None

        # GUI 구성
        self.root = Tk()
        self.root.title("멀티 채팅 (텍스트/파일 전송)")
        self.build_gui()

        # 소켓 연결
        self.connect_socket()

        # 수신 스레드 시작
        self.recv_thread = Thread(target=self.receiver_loop, daemon=True)
        self.recv_thread.start()

        self.root.protocol("WM_DELETE_WINDOW", self.on_close)
        self.root.mainloop()

    def build_gui(self):
        fr = [Frame(self.root) for _ in range(5)]
        for f in fr:
            f.pack(fill=BOTH, padx=4, pady=2)

        # 0행: 이름
        Label(fr[0], text='사용자 이름').pack(side=LEFT)
        self.name_entry = Entry(fr[0], width=20)
        self.name_entry.pack(side=LEFT, padx=5)
        self.name_entry.insert(0, "User")

        # 1행: 수신 라벨
        Label(fr[1], text='수신 메시지:').pack(side=LEFT)

        # 2행: 수신 창
        self.chat_area = ScrolledText(fr[2], height=20, width=70)
        self.chat_area.pack(side=LEFT, padx=2, pady=2)
        self.chat_area.config(state='disabled')

        # 3행: 송신 라벨 + 전송 버튼 + 파일 전송 버튼
        Label(fr[3], text='송신 메시지:').pack(side=LEFT)
        self.send_btn = Button(fr[3], text='전송', command=self.send_text)
        self.send_btn.pack(side=RIGHT, padx=5)
        self.file_btn = Button(fr[3], text='파일 보내기', command=self.send_file)
        self.file_btn.pack(side=RIGHT, padx=5)

        # 4행: 송신 입력창
        self.input_area = ScrolledText(fr[4], height=5, width=70)
        self.input_area.pack(side=LEFT, padx=2, pady=2)
        self.input_area.bind("<Control-Return>", lambda e: self.send_text())

        # 다운로드 폴더
        self.download_dir = os.path.join(os.getcwd(), "downloads")
        os.makedirs(self.download_dir, exist_ok=True)

    def connect_socket(self):
        self.sock = socket(AF_INET, SOCK_STREAM)
        self.sock.connect((self.server_ip, self.server_port))
        self.log_local(f"[시스템] 서버({self.server_ip}:{self.server_port})에 연결되었습니다.")

    def log_local(self, text):
        self.chat_area.config(state='normal')
        self.chat_area.insert(END, text + "\n")
        self.chat_area.see(END)
        self.chat_area.config(state='disabled')

    def send_text(self):
        sender = self.name_entry.get().strip() or "User"
        msg = self.input_area.get(1.0, END).strip()
        if not msg:
            return 'break'
        payload = msg.encode('utf-8')
        header = f"MSG|{len(payload)}|{sender}\n".encode('utf-8')
        try:
            self.sock.sendall(header)
            self.sock.sendall(payload)
        except Exception as e:
            messagebox.showerror("전송 오류", f"메시지 전송 실패: {e}")
            return 'break'

        # 내 화면에도 표시
        self.log_local(f"{sender}: {msg}")
        self.input_area.delete(1.0, END)
        return 'break'

    def send_file(self):
        sender = self.name_entry.get().strip() or "User"
        path = filedialog.askopenfilename(title="전송할 파일 선택")
        if not path:
            return
        try:
            filesize = os.path.getsize(path)
            filename = os.path.basename(path)
            with open(path, 'rb') as f:
                data = f.read()
            if len(data) != filesize:
                raise IOError("파일 크기 불일치")
            header = f"FILE|{filesize}|{filename}|{sender}\n".encode('utf-8')
            self.sock.sendall(header)
            self.sock.sendall(data)
        except Exception as e:
            messagebox.showerror("전송 오류", f"파일 전송 실패: {e}")
            return

        self.log_local(f"[파일 송신] {filename} ({filesize} bytes) 전송 완료")

    # ---- 수신측 유틸 ----
    def recv_line(self, sock):
        buf = bytearray()
        while True:
            ch = sock.recv(1)
            if not ch:
                return None
            buf += ch
            if ch == b'\n':
                return bytes(buf)

    def recv_exact(self, sock, nbytes):
        buf = bytearray()
        while len(buf) < nbytes:
            chunk = sock.recv(min(4096, nbytes - len(buf)))
            if not chunk:
                return None
            buf += chunk
        return bytes(buf)

    def receiver_loop(self):
        try:
            while True:
                header_line = self.recv_line(self.sock)
                if not header_line:
                    self.log_local("[시스템] 서버와의 연결이 종료되었습니다.")
                    break

                parts = header_line.decode('utf-8', 'ignore').rstrip('\n').split('|')
                kind = parts[0] if parts else ''
                if kind == 'MSG':
                    if len(parts) != 3:
                        self.log_local(f"[시스템] 잘못된 MSG 헤더: {parts}")
                        break
                    length = int(parts[1])
                    sender = parts[2]
                    payload = self.recv_exact(self.sock, length)
                    if payload is None:
                        self.log_local("[시스템] 메시지 수신 실패")
                        break
                    text = payload.decode('utf-8', 'ignore')
                    self.log_local(f"{sender}: {text}")

                elif kind == 'FILE':
                    if len(parts) != 4:
                        self.log_local(f"[시스템] 잘못된 FILE 헤더: {parts}")
                        break
                    length = int(parts[1])
                    filename = parts[2]
                    sender = parts[3]
                    data = self.recv_exact(self.sock, length)
                    if data is None:
                        self.log_local("[시스템] 파일 수신 실패")
                        break

                    # 파일 저장 (이름 충돌 시 타임스탬프 부여)
                    save_name = filename
                    base, ext = os.path.splitext(filename)
                    idx = 1
                    while os.path.exists(os.path.join(self.download_dir, save_name)):
                        save_name = f"{base}_{idx}{ext}"
                        idx += 1

                    save_path = os.path.join(self.download_dir, save_name)
                    with open(save_path, 'wb') as f:
                        f.write(data)

                    self.log_local(f"[파일 수신] {sender} -> {save_name} 저장됨: {save_path}")

                else:
                    self.log_local(f"[시스템] 알 수 없는 패킷 종류: {parts}")
                    break

        except Exception as e:
            self.log_local(f"[시스템] 수신 스레드 예외: {e}")
        finally:
            try:
                self.sock.close()
            except:
                pass

    def on_close(self):
        try:
            self.sock.shutdown(SHUT_RDWR)
        except:
            pass
        try:
            self.sock.close()
        except:
            pass
        self.root.destroy()


if __name__ == "__main__":
    # 실행 시 입력창 없이 바로 127.0.0.1:2500 접속
    ChatClient(ip='127.0.0.1', port=2500)
