
//#include<iostream>
//#include<winsock2.h>
//
//SOCKET servsoc;
//servsoc = socket(AF_INET, SOCK_STREAM, 0);
//
//int bind(SOCKET s/*서버 소켓에 사용될 소켓*/,
//	const struct sockaddr FAR name/*현재 소켓과 연결된 정보를 가지고 있는 
//	 sockaddr_in구조체*/,
//	int namelen/*구조체 크기*/);
//
//sockaddr_in serverAddress;
//serverAddress.sin_family = AF_INET;
//serverAddress.sin_port = htons(PORT);
//serverAddress.sin_addr.addr = htonl(inaddr_any);
//bind(servsoc, (sockaddr*)&serverAddress, sizeof(serverAddress));
//
//int listen(SOCKET s/*bind를 실행한 서버 소켓 대입*/,
//	int backlog/*대기 클라이언트 수*/);
//
//listen(servsoc, SOMAXCONN);
//SOCKET accept(SOCKET s/*서버 소켓*/, struct sockaddr FAR* addr/*클라이언트 정보를 받기 위하여 sockaddr_in구조체 사용*/,
//	int* addrlen/*addr의 크기가 저장*/);
//
//SOCKET clisoc;
//clisoc = accept(servsoc, NULL, NULL);
//
//int recv(SOCKET s/*클라이언트와 연결된 소켓*/,
//	char FAR* buf/*메시지를 넣을 장소*/,
//	int len/*메시지 크기*/,
//	int flags/*메세지를 읽어 들일 때에 옵션*/);
//
//int connect(socket)

#include<iostream>
#include<iostream>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

#define PORT 5500
#defing BUFFER_SIZE 100

int main() {

}