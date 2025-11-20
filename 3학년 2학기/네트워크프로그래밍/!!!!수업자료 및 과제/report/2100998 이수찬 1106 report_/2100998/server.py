
from socket import *
import threading

class TemperatureServer:
    ECHO_PORT = 2500
    BUFSIZE = 1024

    def __init__(self, host: str = "", port: int = 2500):
        self.host = host
        self.port = port
        self.sock = socket(AF_INET, SOCK_STREAM)
        self.sock.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
        self.sock.bind((self.host, self.port))
        self.sock.listen(10)
        print(f"[SERVER] Listening on {self.host or '0.0.0.0'}:{self.port}")

    def start(self):
        while True:
            conn, (remotehost, remoteport) = self.sock.accept()
            print("[SERVER] connected by", remotehost, remoteport)
            t = threading.Thread(
                target=self.handle_client,
                args=(conn, remotehost, remoteport),
                daemon=True
            )
            t.start()

    def handle_client(self, conn: socket, remotehost: str, remoteport: int):
        try:
            while True:
                data = conn.recv(self.BUFSIZE)
                if not data:
                    break
                c = float(data.decode().strip())     
                f = 9.0 / 5.0 * c + 32.0
                resp = f"{f:.1f}"
                conn.send(resp.encode())            
        finally:
            conn.close()
            print(f"[SERVER] client closed: {remotehost}:{remoteport}")

if __name__ == "__main__":
    TemperatureServer().start()
