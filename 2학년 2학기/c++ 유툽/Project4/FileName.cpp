/*#include<iostream>
using namespace std;
class number {
private:
	int num1;
public:
	void set_number(int n);
	void print_number();
};

void number::set_number(int n) {
	num1 = n;
}
void number::print_number() {
	cout << num1 << endl;
}

int main() {
	number nm;
	int st;
	cin >> st;
	nm.set_number(st);
	nm.print_number();

	return 0;
}
*/
/*
정수배열 크기가 10짜리가 2개,
처음 배열 변수에 4미만의 난수를 발생하여 집어넣는다. 
집어넣은 결과를 출력

두번째 배열에 첫번째 결과를 집어 넣는데 0은 제외하고 대입하고 
남은 자리에 0을 넣는다
*/
/*
#include<iostream>
using namespace std;
class cla {
private:
	int a[10], b[10] = { 0 };
public:
	void pro_manage();
	void insert();
};
void cla::pro_manage(){
	insert();
};
void cla::insert() {
	int i,idx=0;
	for (i = 0; i < 10; i++) {
		a[i] = rand() % 4;
	}
	for (i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	for (i = 0; i < 10; i++) {
		if (a[i] != 0) {
			b[idx] = a[i];
			idx++;
		}
	}
	for (i = 0; i < 10; i++) {
		cout << b[i] << " ";
	}
}

int main() {
	cla nm;
	nm.pro_manage();
	return 0;
}
*/
/*
//두개의 정수배열, 크기 10 1st 정수 배열 5미만 난수 발생 2nd 3미만의 난수 => 두 배열의 유사도 
//1st, 2nd, 유사도 출력
#include<iostream>
using namespace std;
class cla {
private:
	int a[10], b[10];
public:
	void pro_manage();
	void insert();
};
void cla::pro_manage() {
	insert();
};
void cla::insert() {
	int i, idx = 0;
	srand(time(NULL));
	for (i = 0; i < 10; i++) {
		a[i] = rand() % 5;
	}
	for (i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	for (i = 0; i < 10; i++) {
		b[i] = rand() % 4;
	}
	for (i = 0; i < 10; i++) {
		cout << b[i] << " ";
	}
	for (i = 0; i < 10; i++) {
		if (a[i] == b[i]) {
			idx++;
		}
	}
	cout << idx * 10 << "%";
}

int main() {
	cla nm;
	nm.pro_manage();
	return 0;
}
*/

//정수배열 한 개, 크기 10, 100미만의 난수 생성 후 출력, 출력 후 패 셔플하여 출력(space키(32번) 누르면 셔플이 되고 esc(27번 나오면) 끝)

#include<iostream>
#include<conio.h>
using namespace std;


class cla {
public:
	int a[10];
	void manage();
};

void cla::manage() {
	int i;
	srand(time(NULL));
	for (i = 0; i < 10; i++) {
		a[i] = rand() % 100;
	}
	for (i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	while (true) {
		int key = getch();
		if (key == 27) break;
		else if (key == ' ') {
			for (i = 0; i < 10; i++) {
				a[i] = rand() % 100;
			}
			for (i = 0; i < 10; i++) {
				cout << a[i] << " ";
			}
		}
	}
}

int main() {
	cla nm;
	nm.manage();
	return 0;
}