# select_client.py
# select 모듈을 이용한 TCP 클라이언트 프로그램
from socket import *
from select import * #접속 소켓 목록
socks = []
sock = socket()
sock.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)

#생성된 소켓을 목록에 추가
socks.append(sock)
sock.connect(('localhost', 2500)) #서버 연결
#이벤트 발생 소켓 조사

while True:
 #읽기 이벤트만 조사. 넌블록킹 모드
     r_sock, w_sock, e_sock = select(socks,[],[], 0)
     if r_sock: #읽기 이벤트 발생?
         for s in r_sock:
             if s == sock: #자신에게 온 데이터인가?
                 msg = sock.recv(1024).decode()
                 print("수신 메시지:", msg)
smsg = input("전송 메시지: ")
sock.sendall(smsg.encode())