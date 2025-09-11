// 정상공간 하나 
// 정상공간이 1또는 0으로 나오고 좌우키를 눌러 -+가 되는 수는 정상공간 아래에 차례로 나타낸다
// 본인은 1 
// 1이 다른 쪽으로 가면 정상공간은 0이 되어야 한다.
// 좌우키 눌러서 1을 움직이고 밑에 변경값을 출력함 
// 오른쪽으로 가면 ++1 왼쪽으로 가면 --1
// but 정상공간을 0으로 놓고 계속해서 오른쪽으로 가면 가는 동안 반복하여 +1 or -1을 시키지만 정상공간을 향해 올때는 +-1을 시키지 않는다.
// but 오른쪽이나 왼쪽으로 가서 +-1이 된 수가 정상공간을 향하여 갈때는 -+1이 되지 않지만 중간에 다시 경로를 바꿔 오른쪽이나 왼쪽으로 갈 때는 +-1을 해준다.
// 정상공간을 기준으로 오른쪽은 1,2,3,4,5... 왼쪽은 -1,-2,-3,-4,-5... 가 된다.
// 그러나 0은 정상공간을 나타내므로 1이 정상공간을 벗어나며 왼쪽으로 이동하면 0이 아닌 -1이 된다. 



#include<iostream>
#include<conio.h>
#include<Windows.h>

using namespace std;

class cla {
private:
	int a, rightmove, leftmove, br, totalmove, i,num;
public:
	cla();
	void manage();
	void clearstatus();  // god gpt
	void printstatus(int status);  // god gpt
	~cla();
};

cla::cla() {
	rightmove = 0;
	leftmove = 0;
	totalmove = rightmove - leftmove;
}

void  cla::clearstatus() {
	system("cls");
}
void cla::printstatus(int status) {
	clearstatus();
	cout << status << endl;
}

void cla::manage() {
	printstatus(1);
	while (true) {
		int ky = _getch();
		if (ky == 77) {
			++rightmove;
			totalmove = rightmove - leftmove; // 놓친부분
			if (totalmove != 0 && totalmove > 0) {  //정상공간보다 오른쪽에 있을 때 우측 키 누르면 +1
				cout << rightmove << endl;
				printstatus(0);
			}
			else if (totalmove != 0 && totalmove < 0) { //정상공간보다 왼쪽에 있지만 우측 키 눌렀을 때 변화 없음.
				cout << -leftmove << endl; 
				printstatus(0);
			}
			else if (totalmove == 0) { // 정상공간보다 좌측에 있다가 우측 키 눌러 정상공간에 왔을 때 
				br = -leftmove;
				leftmove = 0;
				rightmove = 0;
				cout << "정상공간에 존재 " << br << endl;
				printstatus(1);
			}
		}
		
		else if (ky == 75) {
			++leftmove;
			totalmove = rightmove - leftmove;  // 놓친부분
			if (totalmove != 0 && totalmove < 0) { //정상공간보다 좌측에 있어서 좌측키 누르면 -1씩 발생
				cout << -leftmove << endl;
				printstatus(0);
			}
			else if (totalmove != 0 && totalmove > 0) { // 정상공간보다 우측에 있는 상태에서 좌측키 눌렀을 때 
				cout << rightmove << endl;
				printstatus(0);
			}
			else if (totalmove == 0) { // 정상공간보다 우측에 있는 상태에서 좌측 키를 눌러 정상공간으로 돌아왔을 때
				br = rightmove;
				leftmove = 0;
				rightmove = 0;
				cout << "정상공간에 존재 "<< br << endl;
				printstatus(1);
			}
		}
		
		
		else if (ky == 27) {
			cout << "bye" << endl;
			break;
		}	
		//int num = totalmove;
}
cla::~cla() {
	;
}

int main() {
	cla nm;
	nm.manage();
	return 0;
}


