// 스노우 프로그램 1

#include<iostream>
#include<stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;


class CLA {
private:
	int gox, goy;
public:
	CLA();
	void SCR_Manage();
	void ScreenXY();
	void Star_Print();
};

CLA::CLA()
{
	cout << "스노우 좌표 프로그램입니다." << endl;
	Sleep(10000);
	system("cls");
}
void CLA::SCR_Manage()
{
	srand(time(0));
	int x1,x2,x3, y;
	char ch;
	for(int k=0;k<3;k++)
	for (int i = 0; i < 5; i++) {
		x1[i] = rand() % 80;
	}
	x2[i] = rand() % 80;
	x3[i] = rand() % 80;

	while (true) {
		for (y = 1; y <= 10; y++) {
			Sleep(400);
			system("cls");
			gox = x1, goy = y;  // 화면 좌표

			ScreenXY();
			Star_Print();
		}
	}
	ch = _getch(); // 문자 입력 시 종료
}
void CLA::ScreenXY()  // 좌표 이동
{
	COORD Pos = { gox, goy };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}

void CLA::Star_Print()
{
	cout << "*";   // 눈 출력
}
int main()
{
	CLA nm;

	nm.SCR_Manage();

	return 0;
}
