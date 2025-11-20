import sys
from socket import *
import threading

ECHO_PORT = 2500
BUFSIZE =1024

def start_server():
    s=socket(AF_INET, SOCK_STREAM)
    s.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
    s.bind(('',ECHO_PORT))
    s.listen(10)
    print("Waiting for connection from client")
    
   

    while True:
        conn, (remotehost, remoteport)=s.accept()
        print('connected by', remotehost, remoteport)
        client_thread = threading.Thread(target=handle_client, args=(conn, remotehost, remoteport))
        client_thread.daemon = True  
        client_thread.start()

def handle_client(conn, remotehost, remoteport):
    while True:
        data=conn.recv(BUFSIZE)
        if not data:
            break
        
        data=float(data.decode())
        
        data=9.0/5.0*data+32.0
        data='{:.1f}'.format(data)
        
        conn.send(data.encode())
        
    conn.close()

