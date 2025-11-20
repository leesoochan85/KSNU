# server.py
from socket import *
from threading import Thread

# 간단한 패킷 프로토콜:
# 텍스트:  b"MSG|<len>|<sender>\n" + <payload utf-8 bytes>
# 파일:    b"FILE|<len>|<filename>|<sender>\n" + <raw bytes>
# 주의: <len> 바이트를 정확히 읽어야 함.

class MultiChatServer:
    def __init__(self, host='', port=2500):
        self.host = host
        self.port = port
        self.server_sock = socket(AF_INET, SOCK_STREAM)
        self.server_sock.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
        self.server_sock.bind((self.host, self.port))
        self.server_sock.listen(100)

        self.clients = []  # (sock, addr)

        print(f"[서버] {self.host}:{self.port}에서 클라이언트 대기 중 ...")
        self.accept_thread = Thread(target=self.accept_clients, daemon=True)
        self.accept_thread.start()

        # 메인 스레드가 종료되지 않도록 대기
        try:
            while True:
                pass
        except KeyboardInterrupt:
            print("\n[서버] 종료 중 ...")
        finally:
            for s, _ in self.clients:
                s.close()
            self.server_sock.close()

    def accept_clients(self):
        while True:
            c_sock, addr = self.server_sock.accept()
            print(f"[서버] {addr} 연결")
            self.clients.append((c_sock, addr))
            Thread(target=self.client_loop, args=(c_sock, addr), daemon=True).start()

    def recv_line(self, sock):
        # '\n'까지 읽기 (헤더 라인)
        buf = bytearray()
        while True:
            ch = sock.recv(1)
            if not ch:
                return None
            buf += ch
            if ch == b'\n':
                return bytes(buf)

    def recv_exact(self, sock, nbytes):
        # 정확히 nbytes 만큼 읽기
        buf = bytearray()
        while len(buf) < nbytes:
            chunk = sock.recv(min(4096, nbytes - len(buf)))
            if not chunk:
                return None
            buf += chunk
        return bytes(buf)

    def broadcast(self, sender_sock, header: bytes, payload: bytes):
        # 모든 다른 클라이언트에게 전송
        to_remove = []
        for s, addr in self.clients:
            if s is sender_sock:
                continue
            try:
                s.sendall(header)
                if payload:
                    s.sendall(payload)
            except Exception:
                print(f"[서버] {addr} 전송 실패 -> 제거")
                to_remove.append((s, addr))
        for item in to_remove:
            self.clients.remove(item)
            try:
                item[0].close()
            except:
                pass

    def client_loop(self, c_sock, addr):
        try:
            while True:
                header_line = self.recv_line(c_sock)
                if not header_line:
                    print(f"[서버] {addr} 연결 종료")
                    break

                # header_line 예: b"MSG|12|Alice\n"  or b"FILE|102400|cat.png|Alice\n"
                try:
                    parts = header_line.decode('utf-8').rstrip('\n').split('|')
                except Exception:
                    print(f"[서버] 잘못된 헤더 수신(디코딩 실패): {header_line!r}")
                    break

                if not parts:
                    continue

                kind = parts[0]
                if kind == 'MSG':
                    if len(parts) != 3:
                        print(f"[서버] 잘못된 MSG 헤더: {parts}")
                        break
                    length = int(parts[1])
                    sender = parts[2]
                    payload = self.recv_exact(c_sock, length)
                    if payload is None:
                        print(f"[서버] {addr} 페이로드 수신 실패")
                        break
                    print(f"[서버][MSG] {sender}: {payload.decode('utf-8', 'ignore')}")
                    self.broadcast(c_sock, header_line, payload)

                elif kind == 'FILE':
                    if len(parts) != 4:
                        print(f"[서버] 잘못된 FILE 헤더: {parts}")
                        break
                    length = int(parts[1])
                    filename = parts[2]
                    sender = parts[3]
                    payload = self.recv_exact(c_sock, length)
                    if payload is None:
                        print(f"[서버] {addr} 파일 페이로드 수신 실패")
                        break
                    print(f"[서버][FILE] {sender} -> {filename} ({length} bytes)")
                    self.broadcast(c_sock, header_line, payload)

                else:
                    print(f"[서버] 알 수 없는 종류: {kind}")
                    break

        except Exception as e:
            print(f"[서버] 예외 {addr}: {e}")
        finally:
            try:
                c_sock.close()
            except:
                pass
            # 목록에서 제거
            for item in list(self.clients):
                if item[0] is c_sock:
                    self.clients.remove(item)
                    break
            print(f"[서버] 클라이언트 종료: {addr}")


if __name__ == "__main__":
    MultiChatServer(host='', port=2500)
