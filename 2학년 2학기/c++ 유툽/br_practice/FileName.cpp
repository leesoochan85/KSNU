#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
using namespace std;

class br {
private:
	int back[3];
	int bx; // 이동객체 위치
	int ob; // 이동객체
	char ky;
public:
	br();
	void bman();
	void blef();
	void brig();
	void bpri();
	~br();
};
br::br() {
	ob = 1;
	bx = 0;
	for (int i = 0; i < 3; i++) {
		if (i == 0) back[i] = ob;
		else back[i] = 0;
	}
}
void br::bman() {
	bpri();
	ky = 0;
	while (ky != 27) {
		ky = _getch();
		switch (ky) {
		case 75: blef();
			break;
		case 77:brig();
			break;
		}
		system("cls");
		bpri();
	}
}
void br::blef() {
	if (bx >= 1) {
		--bx;
		back[bx] = ob;
		back[bx + 1] = 0;
	}
}
void br::brig() {
	if (bx < 2) {
		++bx;
		back[bx - 1] = 0;
		back[bx] = ob;
	}
}
void br::bpri() {
	for (int i = 0; i < 3; i++) {
		cout << back[i] << " ";
	}
}
br::~br() {
	cout << endl << "good bye" << endl;
}
int main() {
	br br;
	br.bman();
	return 0;
}