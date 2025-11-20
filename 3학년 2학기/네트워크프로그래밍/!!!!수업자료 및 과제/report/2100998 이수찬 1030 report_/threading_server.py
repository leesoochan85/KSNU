import socket
import threading
#데이터를 수신하여 모든 클라이언트에게 다시 전송하는 함수
#연결이 종료된 소켓은 연결 소켓 목록에서 제거

connections = []
lock = threading.Lock()

def handler(c, a): #c: 소켓, a: 주소
    global connections # 연결 소켓 목록

    while True:
        try:
            data = c.recv(1024)
            if not data:
                with lock:
                    if c in connections:
                        connections.remove(c)
                c.close()
                break
        except Exception:
            with lock:
                if c in connections:
                    connections.remove(c)
            try:
                c.close()
            except:
                pass
            print("[!] recv error, closed:")
            break

        # ★ 브로드캐스트는 복사본으로 안전하게 순회
        with lock:
            targets = connections.copy()
        for connection in targets:
            try:
                connection.send(data)
            except Exception:
                # 전송 실패한 소켓은 정리
                with lock:
                    if connection in connections:
                        connections.remove(connection)
                try:
                    connection.close()
                except:
                    pass

# 메인 함수
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(("", 2500))
sock.listen(10)
print("Waiting for clients")

#연결 요청을 수락하고 데이터 송수신을 서브스레드로 실행
while True:
    c, a = sock.accept()

 #스레드 객체를 생성하고 실행
    cThread = threading.Thread(target=handler, args=(c,a))
    cThread.daemon = True #서브스레드가 종료되면 메인 스레드도 종료
    cThread.start()

 # 새 클라이언트를 목록에 추가
    connections.append(c)
    print("연결된 클라이언트: ",connections)