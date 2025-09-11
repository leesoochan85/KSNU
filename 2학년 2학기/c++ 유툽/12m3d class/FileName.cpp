#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;

class cla{
private:
	int a[3][3], i, k, j, m, used[9] = { 0 }, num;
public:
	void move();
	void arrange();
};

void cla::arrange() {
	srand(time(0));
	for (i = 0; i < 3; i++) {
		for (k = 0; k < 3; k++) {
			num = rand() % 9;
			while(used[num]==1){
				num = rand() % 9;
		}
			a[i][k] = num;
			used[num] = 1;
	}
	for (i = 0; i < 3; i++) {
		for (k = 0; k < 3; k++) {
			cout << a[i][k] << " ";
		}cout<<endl;
	}
}
	void cla::move() {
		while (1) {
			int ky = _getch();
			system("cls");
			if (ky == 75) {
				for (i = 0; i < 3; i++) {
					for (k = 0; k < 3; k++) {
						if (a[i][k] == 0) {
							if (k == 0) {
								int tmp = a[i][k]; // 0임시공간
								a[i][k] = a[i][k + 1]; //[0][0]=[0][1]
								a[i][k + 1] = a[i][k + 2]; //[0][1]=[0][2]
								a[i][k + 2] = tmp; // [0][2]=임시공간
							}
							else if (k == 1) {
								int tmp = a[i][k]; // a[i][1]==0임시공간
								a[i][k + 1] = a[i][k];//[0][2]=[0][1]
								a[i][k + 1] = tmp;
							}
						}
					}
				}
			}
			else if (ky == 77) {
				for (i = 0; i < 3; i++) {
					for (k = 0; k < 3; k++) {
						if (a[i][k] == 0) {
							if (k == 2) {
								int tmp = a[i][k]; // 0임시공간
								a[i][k] = a[i][k - 1]; //[0][2]=[0][1]
								a[i][k - 1] = a[i][k - 2]; //[0][1]=[0][2]
								a[i][k - 2] = tmp; // [0][2]=임시공간
							}
							else if (k == 1) {
								int tmp = a[i][k]; // a[i][1]==0임시공간
								a[i][k] = a[i][k - 1];//[0][1]=[0][0]
								a[i][k - 1] = tmp;
							}
						}
					}
				}
			}
			else if (ky == 72) {
				for (i = 0; i < 3; i++) {
					for (k = 0; k < 3; k++) {
						if (a[i][k] == 0) {
							if (i == 2) {
								int tmp = a[i][k]; // 0임시공간
								a[i][k] = a[i - 1][k]; //[2][0]=[1][0]
								a[i - 1][k] = a[i - 2][k]; //[1][0]=[0][0]
								a[i - 2][k] = tmp; // [0][2]=임시공간
							}
							else if (i == 1) {
								int tmp = a[i][k]; // a[i][1]==0임시공간
								a[i][k] = a[i - 1][k];//[1][0]=[0][0]
								a[i - 1][k] = tmp;
							}
						}
					}
				}
			}
			else if (ky == 80) {
				for (i = 0; i < 3; i++) {
					for (k = 0; k < 3; k++) {
						if (a[i][k] == 0) {
							if (i == 0) {
								int tmp = a[i][k]; // 0임시공간
								a[i + 1][k] = a[i + 2][k];//[1][0]=[2][0]
								a[i][k] = a[i + 1][k]; //[0][0]=[1][0]
								a[i + 2][k] = tmp; // [0][2]=임시공간
							}
							else if (i == 1) {
								int tmp = a[i - 1][k]; // a[i][1]==0임시공간
								a[i - 1][k] = a[i][k];//[1][0]=[0][0]
								a[i][k] = tmp;
							}
						}
					}
				}
			}
			for (i = 0; i < 3; i++) {
				for (k = 0; k < 3; k++) {
					cout << a[i][k] << " ";
				}cout << endl;
			}
			if (ky == 27) break;
		}
	}
}

int main() {
	cla nm;
	nm.arrange();
	nm.move();
	return 0;
}