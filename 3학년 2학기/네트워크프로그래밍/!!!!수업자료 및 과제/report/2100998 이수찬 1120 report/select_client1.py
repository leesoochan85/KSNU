import socket
import select
import threading

class SelectDeviceClient:
    def __init__(self, host="127.0.0.1", port=2500):
        self.host = host
        self.port = port
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.connect((self.host, self.port))
        self.sock.setblocking(False)
        print(f"[CLIENT] connected to {self.host}:{self.port}")
        self._running = True
        self._buf = bytearray()

    def start(self):
        t = threading.Thread(target=self._receiver, daemon=True)
        t.start()

        try:
            while True:
                line = input("CMD (SET|dev|ON/OFF, GET|dev, QUIT): ").strip()
                if not line:
                    continue
                if line.upper() == "QUIT":
                    break
                self._send_line(line)
        finally:
            self._running = False
            try:
                self.sock.shutdown(socket.SHUT_RDWR)
            except:
                pass
            self.sock.close()
            print("[CLIENT] closed")

    def _send_line(self, line: str):
        try:
            self.sock.sendall((line + "\n").encode("utf-8"))
        except Exception as e:
            print("[CLIENT] send error:", e)

    def _receiver(self):
        try:
            while self._running:
                rlist, _, _ = select.select([self.sock], [], [], 0.5)
                if not rlist:
                    continue
                try:
                    data = self.sock.recv(4096)
                except BlockingIOError:
                    continue
                if not data:
                    print("[CLIENT] server closed")
                    break
                self._buf += data
                while b"\n" in self._buf:
                    line, _, self._buf = self._buf.partition(b"\n")
                    print("[SERVER]", line.decode("utf-8", "ignore").strip())
        except Exception as e:
            print("[CLIENT] recv loop error:", e)
