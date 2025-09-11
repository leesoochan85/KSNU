//6x6 임의의 위치에 a,b가 동시에 나타나고 a가 상하좌우로 랜덤이동 하고 a가 b의 위치로 가면 프로그램 종료 (문제 1)

//맵에서 원 하나가 움직이면서 벽에 부딛히면 튕겨나오도록 설계 (문제2)

#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;

class cla {
private:

protected:
	char map[6][6],i,j,k;
public:
	void move();
	void move2();
};


void cla::move() {
	int i, j, k, l,a,b, ky;
	char map[6][6], tmp;
	srand(time(0));

	for (a = 0; a < 6; a++) {
		for (b = 0; b < 6; b++) {
			map[a][b] = ' ';
		}
	}

	i = rand() % 6;
	j = rand() % 6;
	map[i][j] = 97;

	k = rand() % 6;
	l = rand() % 6;
	map[k][l] = 98;

	while (map[i][j] != map[k][l]) {
		system("cls");
		for (a = 0; a < 6; a++) {
			for (b = 0; b < 6; b++) {
				cout << map[a][b] << " ";
			}
			cout << endl;
		}
		Sleep(500);
		ky = rand() % 4; //0=d, 1=u, 2=l, 3=r
		tmp = 97;
		if (ky == 0&&j!=0) {
			j -= 1;
			map[i][j] = tmp;
			map[i][j + 1] = ' ';
		}
		else if (ky == 1&&j!=5) {
			j += 1;
			map[i][j] = tmp;
			map[i][j - 1] = ' ';
		}
		else if (ky == 2&&j!=0) {
			i -= 1;
			map[i][j] = tmp;
			map[i+1][j] = ' ';
		}
		else if (ky == 3&&j!=5) {
			i += 1;
			map[i][j] = tmp;
			map[i-1][j] = ' ';
		}

		else map[i][j] = map[i][j];
	}
}

void cla::move2() {
	int k, l, e, a, b;
	char map[6][6],tmp;
	map[k][l] = 97;

	while (map[i][j] != map[k][l]) {
		system("cls");
		for (a = 0; a < 6; a++) {
			for (b = 0; b < 6; b++) {
				cout << map[a][b] << " ";
			}
			cout << endl;
		}
		Sleep(500);
		e = rand() % 8; // 0=d 1=u 2=l 3=r 4=dl 5=dr 6=ul 7=ur
		tmp = '○';
		if (e == 0 && j == 0) { // d
			while (j != 5) {
				j -= 1;
				map[i][j] = tmp;
				map[i][j + 1] = ' ';
			}
		}
		else if (e == 1 && j == 5) {
			while (j != 0) {
				j += 1;
				map[i][j] = tmp;
				map[i][j - 1] = ' ';
			}
		}
		else if (e == 2 && j == 0) {
			while (i != 5) {
				i -= 1;
				map[i][j] = tmp;
				map[i + 1][j] = ' ';
			}
		}
		else if (e == 3 && j == 5) {
			while (j != 0) {
				i += 1;
				map[i][j] = tmp;
				map[i - 1][j] = ' ';
			}
		}
		else if (e == 4 && i == 0) { //dl
			while (i != 5) {
				i += 1;
				j -= 1;
				map[i][j] = tmp;
				map[i - 1][j + 1] = ' ';
				if (j == 0) { //dr
					while (j += 1) {
						i += 1;
						j += 1;
						map[i][j] = tmp;
						map[i - 1][j - 1] = ' ';
					}
				}
			}
		}
		else if (e == 5 && i == 0) { // dr
			while (i != 5) {
				i += 1;
				j += 1;
				map[i][j] = tmp;
				map[i - 1][j - 1] = ' ';
				if (j == 5) { //dl
					while (i != 5) {
						i += 1;
						j -= 1;
						map[i][j] = tmp;
						map[i - 1][j + 1] = ' ';
					}
				}
			}
		}
		else if (e == 6 && i == 5) { //ul
			while (i != 0) {
				i -= 1;
				j -= 1;
				map[i][j] = tmp;
				map[i + 1][j + 1] = ' ';
			}
		}
		else if (e == 7 && i == 5) {//ur{ }
			while (i != 0) {
				i -= 1;
				j += 1;
				map[i][j] = tmp;
				map[i + 1][j - 1] = ' ';
			}
		}
	}
}

int main() {
	cla nm;
	nm.move();
	return 0;
}