# client_class.py
from socket import *
import threading
from tkinter import *  

class TemperatureClient:
    def __init__(self, host: str = "localhost", port: int = 2500):
        # 소켓
        self.sock = socket(AF_INET, SOCK_STREAM)
        self.sock.connect((host, port))

        # GUI
        self.root = Tk()
        self.root.title("C → F 변환 클라이언트")

        self.message_label = Label(self.root, text="Enter a temperature (C)", font=("Verdana", 16))
        self.entry1         = Entry(self.root, font=("Verdana", 16), width=5)

        self.recv_label     = Label(self.root, text="Temperature in F", font=("Verdana", 16))
        self.entry2         = Entry(self.root, font=("Verdana", 16), width=5)

        self.calc_button    = Button(self.root, text="전송", font=("Verdana", 12), command=self.calculate)

        # 배치 (grid)
        self.message_label.grid(row=0, column=0, sticky=W)
        self.recv_label.grid(  row=1, column=0, sticky=W)
        self.entry1.grid(      row=0, column=1)
        self.entry2.grid(      row=1, column=1)
        self.calc_button.grid( row=0, column=2, padx=10, pady=10)

        # 수신 스레드 시작
        t = threading.Thread(target=self.recv_worker, daemon=True)
        t.start()

        # 창 닫기
        self.root.protocol("WM_DELETE_WINDOW", self.on_close)

    def calculate(self):
        text = self.entry1.get()
        try:
            self.sock.send(text.encode())
        except OSError:
            pass

    def recv_worker(self):
        try:
            while True:
                try:
                    r_msg = self.sock.recv(1024)
                    if not r_msg:
                        break
                except OSError:
                    break

                text = r_msg.decode().strip()  
                self.entry2.delete(0, END)
                self.entry2.insert(0, text)
                self.entry1.delete(0, END)
        finally:
            try:
                self.sock.close()
            except OSError:
                pass

    def on_close(self):
        try:
            self.sock.shutdown(SHUT_RDWR)
        except OSError:
            pass
        try:
            self.sock.close()
        except OSError:
            pass
        self.root.destroy()

    def run(self):
        self.root.mainloop()

if __name__ == "__main__":
    TemperatureClient().run()
