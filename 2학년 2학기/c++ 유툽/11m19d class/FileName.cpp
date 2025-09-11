//정수배열 크기가 10이고 0~9까지 초기화
// 좌우키 눌러서 돌리고 오른쪽으로 가면 전체 1씩 증가
// 왼쪽으로 가면 전체 1씩 감소 

#include<iostream>
#include<conio.h>
#include <cstdlib>
#include<Windows.h>
using namespace std;

class cla {
private:
	int a[10];
public:
	void allocate();
	void manage();
};

void cla::allocate() {
	int i;
	for (i = 0; i < 10; i++) {
		a[i] = i;
	}
	for (i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void cla::manage() {
	int ky = _getch();
	while (true) {
		int ky = _getch();
		system("cls");
		if (ky == 75) {
			for (int i = 0; i < 10; i++) {
				if(i==0) a[9] = a[0]+1;
				a[i] -= 1;
				
				cout << a[i] << " ";
			}
			cout << endl;
		}
		else if (ky == 77) {
			for (int i = 0; i < 10; i++) {
				if(i==9) a[0] = a[9];
				a[i]+= 1;
				cout << a[i] << " ";
			}
			cout << endl;
		}
		else if (ky == 27) break;
	}
}

int main() {
	cla nm;
	nm.allocate();
	nm.manage();
	return 0;
}