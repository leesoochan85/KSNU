import socket
import threading

def recv_worker(sock):
    try:
        while True:
            data = sock.recv(1024)
            if not data:
                print("\n[서버가 연결을 종료]")
                break
            print("\n[받음]", data.decode())
            print("Sending message: ", end="", flush=True)
    except:
        pass
    finally:
        try: sock.shutdown(socket.SHUT_RDWR)
        except: pass
        sock.close()

sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)

svrIP =input(("Server IP(default: 127.0.0.1): "))
if svrIP =='':
    svrIP ='127.0.0.1'

port = input('port(default: 2500): ')
if port == '':
    port=2500
else:
    port = int(port)

sock.connect((svrIP,port))
print('Connected to'+ svrIP)

cThread = threading.Thread(target=recv_worker, args=(sock,), daemon=True)
cThread.start()

while True:
    msg=input("Sending message: ")
    if msg == 'q':
        break
    if not msg:
        continue
    try:
        sock.send(msg.encode())
    except:
        print("연결 종료")
        break
    
try: sock.shutdown(socket.SHUT_WR)
except: pass

sock.close()
