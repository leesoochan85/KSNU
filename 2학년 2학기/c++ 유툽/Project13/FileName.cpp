// 정수배열 크기 10 
// 0을 쭉 깔고 특정 두 위치에 하나는 1 하나는 2와 3을 내려놓음. 
//나머지 칸에는 0이 채워짐
//1이 이동하는데 2,3을 마주치면 2,3을 같이 밀어서 움직임
// 1번이 양 벽 밖으로 움직이지 않음.

#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

class cla {
private:
    int a[10];  // 배열 선언
public:
    cla();      // 생성자 선언
    void manage();
    void pri();
    ~cla(); // 소멸자 선언
};

// 생성자 정의
cla::cla() {
    // 배열을 0으로 초기화
    fill_n(a, 10, 0);

    // 1, 2, 3의 위치를 무작위로 지정
    srand(time(NULL));
    int first = rand() % 10;
    int sec = rand() % 10;
    while (first == sec && first>sec &&sec<9) {
        sec = rand() % 10;
    }

    a[first] = 1;
    a[sec] = 2;
    a[sec+1] = 3;

    cout << "초기 배열 상태: ";
   /* for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;*/
}

// 관리 메서드
void cla::manage() {
    int key;
    while (true) {
        // 배열 상태 출력
        for (int i = 0; i < 10; i++) {
            cout << a[i] << " ";
        }
        cout << endl;

        system("cls");

        // 키 입력 받기
        key = _getch();
        if (key == 77) {  // 오른쪽 방향키
            for (int i = 0; i < 10; i++) {
                if (a[i] == 1) {
                    // `1`이 이동할 수 있는지 검사
                    if (i + 1 < 10 && a[i + 1] == 0) {  // 다음 칸이 비어 있을 때
                        a[i] = 0;
                        a[i + 1] = 1;
                    }
                    /*else if (i + 1 < 10) {
                        if (i + 2 < 10) {
                            a[i] = 0;
                            a[i + 2] = a[i+1];
                            a[i + 1] = 1;
                        }
                    }*/
                    else if (i + 1 < 10 && i + 2 < 10 && a[i + 1] == 2) {
                        if (i + 3 < 10) { 
                        a[i + 3] = a[i + 2];
                        a[i + 2] = a[i + 1];
                            a[i + 1] = a[i];
                            a[i] = 0;
                        }
                    }
                    else if (i + 1 < 10 && i+2<10 && a[i + 2]==3&&) {
                        a[i + 2] = a[i + 1];
                        a[i + 1] = a[i];
                        a[i] = 0;
                    }
                    else if (i + 1 < 10 && i + 2 >9) {
                        //a[i + 2] = a[i + 1];
                        a[i + 1] = a[i];
                        a[i] = 0;
                    }
                    break;  // 첫 번째 `1`을 이동시키고 나면 반복문 종료
                }
            }
        }
        else if (key == 27) {  // ESC 키
            break;
        }
    }
}

// 소멸자 정의
cla::~cla() {
    cout << "프로그램을 종료합니다." << endl;
}


int main() {
    cla nm;
    nm.manage();
    return 0;
}
