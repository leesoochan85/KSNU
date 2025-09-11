#include<iostream>
#include<stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

class backr {
private:
	int back[3];
	int bx;
	int ob;
	int ky;
public:
	backr();
	void b_manage();
	void b_left();
	void b_right();
	void b_print();
	~backr();
};
backr::backr() {
	ob = 1;
	bx = 0;
	for (int i = 0; i < 3; i++) {
		if (i == 0)back[i] = ob;
		else back[i] = 0;
	}
}
void backr::b_manage() {
	b_print();
	while (ky != 27) {
		ky = _getch();
		switch (ky) {
		case 75: b_left();
			break;
		case 77:b_right();
			break;
		}
		system("cls");
		b_print();
	}
}
void backr::b_left() {
	if (bx >= 1) {
		--bx;
		back[bx] = ob;
		back[bx + 1] = 0;
	}
}
void backr::b_right() {
	if (bx < 2) {
		++bx;
		back[bx - 1] = 0;
		back[bx] = ob;
	}
}
void backr::b_print() {
	for (int i = 0; i < 3; i++) {
		cout << back[i] << " ";
	}
}
backr::~backr() {
	cout << endl << "good bye" << endl;
}
int main() {
	backr br;
	br.b_manage();
	return 0;
}