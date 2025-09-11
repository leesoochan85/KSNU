/*#include <iostream>
#include <Windows.h>
using namespace std;

void animateArray(int arr[], int size, int position);

int main() {
    const int size = 10; // 배열 크기
    int arr[size]; // 크기 10의 정수 배열 생성
    int position = 0; // 1의 초기 위치 설정
    bool movingRight = true; // 이동 방향 (true: 오른쪽, false: 왼쪽)

    while (true) {
        // 애니메이션 함수 호출
        animateArray(arr, size, position);

        // 현재 프레임 표시 후 지연 시간
        Sleep(300);

        // 화면 지우기
        system("cls");

        // 1의 위치 업데이트
        if (movingRight) {
            position++;
            if (position == size - 1) { // 배열의 끝에 도달하면 방향 전환
                movingRight = false;
            }
        }
        else {
            position--;
            if (position == 0) { // 배열의 시작에 도달하면 프로그램 종료
                break;
            }
        }
    }

    return 0;
}

void animateArray(int arr[], int size, int position) {
    // 배열 초기화 (모든 값을 0으로)
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
    // 현재 위치에 1을 할당
    arr[position] = 1;

    // 배열 출력
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
*/


#include<iostream>
#include<Windows.h>
using namespace std;

void aniarray(int arr[], int size, int pos);

int main() {
    const int size = 10;
    int arr[size];
    int pos = 0;
    bool movingRight = true;

    while (true) {
        aniarray(arr, size, pos);

        Sleep (300);
        
        system("cls");

        if (movingRight) {
            pos++;
            if (pos == size - 1)movingRight = false;
        }
        else {
            pos--;
            if (pos == 0)break;
        }
    }
    return 0;
}

void aniarray(int arr[], int size, int pos) {
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
    arr[pos] = 1;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}