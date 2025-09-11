//TBH에서 H가 4방향 중 하나를 잡고 움직이는데 B는 H의 전 위치, T는 B의 전 위치, 만약 직선구간에서 이동반대방향으로 움직이면 H 또는 T이 깔려서 사라진다
// . 그러다가 결국 머리만 남게된다.

#include<iostream>
#include<Windows.h>
#include<conio.h>

using namespace std;

class cla {
private:
	int map[8][8] = // 변수
	{
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1}
	},t,b,h;

public:
	void move();
};

void cla::move() {
	map[1][1] = 'T';
	t = map[1][1];

	map[1][2] = 'B';
	b = map[1][2];
	
	map[1][3] = 'H';
	h = map[1][3];

	int ky = _getch();
	while (true) {
		system("cls");
		if (ky == 75 && h != 1) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					t = b;
					b = h;
					h = map[i][j - 1];
				}
			}
			
		}
		else if (ky == 77 && h != 1) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					t = b;
					b = h;
					h = map[i][j + 1];
				}
			}
		}
		else if (ky == 80 && h != 1) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					t = b;
					b = h;
					h = map[i + 1][j];
				}
			}
		}
		else if (ky == 72 && h != 1) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					t = b;
					b = h;
					h = map[i - 1][j - 1];
				}
			}
		}
	}
}