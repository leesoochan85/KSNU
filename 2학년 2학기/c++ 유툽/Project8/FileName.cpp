/*
#include<iostream>
#include<Windows.h>
#include<conio.h>

using namespace std;

class number {
private:
	int map[8][8] = // 맵 변수
	{
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1}
	};

public:
	void move();
	void print();
};

void number::move() {
	int _getch(), i, j;
		srand(time(NULL));
        i = rand() % 8;
        j = rand() % 8;

        while(map[i][j]!=0){
		i = rand() % 8;
		j = rand() % 8;
        }

		map[i][j] = 2;

	while (i<7||j<7||i>=0||j>=0&&map[i][j]==0) {
		system("cls");
        print();
		cout << "방향키를 누르시오" << endl;

        map[i][j] == 3;

		int key = _getch();
		if (key == 75) {	
			map[i][j-1] = map[i][j];
			j -= 1;
		}
		if (key == 77) {
			map[i][j+1] = map[i][j];
			 j+= 1;
		}
		if (key == 80) {
			map[i+1][j] = map[i][j];
			i += 1;
		}
		if (key == 72) {
			map[i -1][j] = map[i][j];
			i -= 1;
		}
		if (key == 27)break;
    }map[i][j] == 2;
}
void number::print() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
            if (map[i][j] == 1)cout << "@";
            if (map[i][j] == 2) cout << "★";
            if (map[i][j] == 3)cout << "★";
		}
		cout << endl;
	}
}

int main() {
	number t;
	t.move();
	return 0;
}
*/
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

class number {
private:
    int map[8][8] = // 맵 변수 초기화
    {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}
    };

    int i, j; // 현재 별 위치

public:
    number() {
        srand(time(NULL));
        i = rand() % 8;
        j = rand() % 8;

        // 시작 위치가 벽(1)이 아닌 곳으로 설정
        while (map[i][j] != 0) {
            i = rand() % 8;
            j = rand() % 8;
        }
        map[i][j] = 2; // 현재 위치에 별 표시
    }

    void move();
    void print();
};

void number::move() {
    while (true) {
        system("cls");
        print();
        cout << "방향키를 누르시오 (종료: Esc)" << endl;

        int key = _getch();

        // 현재 위치를 경로로 변경
        map[i][j] = 3; // 이동 전 위치에 경로 표시

        // 방향키에 따라 위치 이동
        if (key == 75 && j > 0 && map[i][j - 1] == 0) { // 왼쪽
            j -= 1;
        }
        else if (key == 77 && j < 7 && map[i][j + 1] == 0) { // 오른쪽
            j += 1;
        }
        else if (key == 80 && i < 7 && map[i + 1][j] == 0) { // 아래쪽
            i += 1;
        }
        else if (key == 72 && i > 0 && map[i - 1][j] == 0) { // 위쪽
            i -= 1;
        }
        else if (key == 27) { // Esc 키로 종료
            break;
        }

        // 새로운 위치에 별 표시
        map[i][j] = 2;
    }
}

void number::print() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (map[i][j] == 1)
                cout << "■ "; // 벽
            else if (map[i][j] == 2)
                cout << "★ "; // 현재 위치
            else if (map[i][j] == 3)
                cout << "@ "; // 경로
            else
                cout << ". "; // 빈 공간
        }
        cout << endl;
    }
}

int main() {
    number t;
    t.move();
    return 0;
}
