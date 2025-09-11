// **********************************************
// 제 목 :  과제3
// 날 짜 : 2025년 3월 5일
// 작성자 : 2100998 이수찬
// ********************************************** 
#define _CRT_SECURE_NO_WARNINGS //보안오류방지
#pragma warning(disable:6031) //리턴값관련 경고 방지
#include <stdio.h> //printf,scanf함수선언이 들어있는 stdio.h파일포함
int main(void) // 메인함수 선언
{// 메인함수 시작
	char name[10]; // 이름 넣기 위해 문자형 변수 선언 후 메모리 확보
	char blood_type; // 혈액형 넣기 위해 문자형 변수 선언
	printf("이름을 입력하시오 :"); // 이름 입력하는 곳 알려주기 위한 출력
	scanf(" %s", name); // 이름 작성 하기 위한 코드
	printf("혈액형을 입력하시오 :"); // 혈액형 입력위치 알려주는 코드
	scanf(" %c", &blood_type); // 혈액형 작성하기 위한 코드
	printf("이름: %s\n", name); // 작성한 이름 출력 
	printf("혈액형: %c\n", blood_type); // 작성한 혈액형 출력
	return 0; // 0반환 후 함수 종료
} // 메인함수 종료
