import socket
import select

class SelectDeviceServer:
    def __init__(self, host: str = "", port: int = 2500, registered=None):
        self.host = host
        self.port = port
        registered = registered or {"MOTOR1", "LAMP_A", "FAN_01"}
        self.status = {name: "OFF" for name in registered}

        self.listener = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.listener.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.listener.bind((self.host, self.port))
        self.listener.listen(100)
        self.listener.setblocking(False)

        self.socks = [self.listener]
        self.buffers = {}   # per-socket receive buffer (bytearray)

        print(f"[SERVER] listening on {self.host or '0.0.0.0'}:{self.port}")

    def serve_forever(self):
        try:
            while True:
                rlist, _, elist = select.select(self.socks, [], self.socks, 1.0)

                for s in rlist:
                    if s is self.listener:
                        self._accept_new()
                    else:
                        self._recv_and_process(s)

                for s in elist:
                    self._close_socket(s)
        finally:
            for s in list(self.socks):
                self._close_socket(s)
            print("[SERVER] shutdown")

    def _accept_new(self):
        try:
            conn, addr = self.listener.accept()
            conn.setblocking(False)
            self.socks.append(conn)
            self.buffers[conn] = bytearray()
            print(f"[SERVER] connected: {addr}")
        except Exception as e:
            print("[SERVER] accept error:", e)

    def _close_socket(self, s: socket.socket):
        if s in self.socks:
            self.socks.remove(s)
        if s in self.buffers:
            del self.buffers[s]
        try:
            peer = s.getpeername()
        except Exception:
            peer = "?"
        try:
            s.close()
        except:
            pass
        print(f"[SERVER] closed: {peer}")

    def _recv_and_process(self, s: socket.socket):
        try:
            data = s.recv(4096)
        except Exception as e:
            print("[SERVER] recv error:", e)
            self._close_socket(s)
            return

        if not data:
            self._close_socket(s)
            return

        buf = self.buffers[s]
        buf += data

        while True:
            nl = buf.find(b"\n")
            if nl < 0:
                break
            line = buf[:nl]
            del buf[:nl+1]

            req = line.decode("utf-8", "ignore").strip()
            resp = self._handle_line(req)
            try:
                s.sendall((resp + "\n").encode("utf-8"))
            except Exception as e:
                print("[SERVER] send error:", e)
                self._close_socket(s)
                return

    def _handle_line(self, line: str) -> str:
        parts = line.split("|")
        if not parts:
            return "ERROR|BAD_REQUEST"

        cmd = parts[0].upper()
        if cmd == "SET" and len(parts) == 3:
            dev, state = parts[1], parts[2].upper()
            if state not in ("ON", "OFF"):
                return f"ERROR|BAD_STATE|{state}"
            if dev in self.status:
                self.status[dev] = state
                return f"STATUS|{dev}|{self.status[dev]}"
            else:
                return f"ERROR|NOT_REGISTERED|{dev}"

        elif cmd == "GET" and len(parts) == 2:
            dev = parts[1]
            if dev in self.status:
                return f"STATUS|{dev}|{self.status[dev]}"
            else:
                return f"ERROR|NOT_REGISTERED|{dev}"

        return "ERROR|BAD_REQUEST"


if __name__ == "__main__":
    SelectDeviceServer(port=2500, registered={"MOTOR1", "LAMP_A", "FAN_01"}).serve_forever()
