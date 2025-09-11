#include<iostream> //입출력 헤더파일
using namespace std; //c++ 이름공간 설정

int main() { // 메인함수 설정
	cout << "저장할 문자열의 크기를 입력하세요:"; // 입력 실수 출력
	int n; //정수 변수 선언
	cin >> n;//입력할 실수 갯수 입력
	cout << endl;
	cout << n << "개의 정수를 입력 하시오.\n";//입력한 실수 출력
	string* a = new string[n];//동적할당 받을 포인터 변수와 크기 선언
	if (!a) {//오류확인
		cout << "메모리부족"; //메모리 부족하면 오류메시지 출력
		return -1;//오류시 프로그램 종료
	}
	int temp=0;// 임시 변수 선언
	for (int i = 0; i < n; i++) {//반복문 확인
		cin >> a[i];//실수 입력
		if (a[i] > a[temp]) {
			a[temp] = a[i];
		}
	}
	cout << "최대값은 " <<a[temp]<< "입니다."; //최대값 구한 후 출력

	delete a;// 동적 할당 반환
}