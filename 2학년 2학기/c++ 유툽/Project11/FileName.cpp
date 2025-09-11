// 정수배역 크기 10 
// 0을 쭉 깔고 특정 두 위치에 하나는 1 하나는 2와 3을 내려놓음. 
//나머지 칸에는 0이 채워짐
//1이 이동하는데 2,3을 마주치면 2,3을 같이 밀어서 움직임
// 1번이 양 벽 밖으로 움직이지 않음.


#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;	

class cla {
private:
	int a[10] = { 0 };
public:
	void manage();
};

void cla::manage() {
	srand(time(NULL));
	int first = rand() % 10;
	int sec = rand() % 10;
	while (first == sec) {
		sec = rand() % 10;
	}
	int third = rand() % 10;
	while (first == third || sec == third) {
		third = rand() % 10;
	}

	a[first] = 1;
	a[sec] = 2;
	a[third] = 3;

	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	int _getch(),key;
	while (true) {
		system("cls");
		key = _getch();
		if (key == 77) {
			for (int i = 0; i < 10; i++) {
				if (a[i] != 1);
				else if (a[i] == 1) {
					a[i + 1] = a[i];
					a[i] = 0;
					if (a[i + 1] == 2) {
						a[i + 2] = a[i + 1];
						if (a[i + 2] == 3) {
							a[i + 3] = a[i + 2];
							if (i + 3 > 9) {
								a[i + 3] = a[i + 2];
								a[i + 2] = a[i + 1];
								a[i + 1] = a[i];
							}
						}
					}
				}
			}
		}
		else if (key == 27)break;
	}
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}

int main() {
	cla nm;
	nm.manage();
	return 0;
}