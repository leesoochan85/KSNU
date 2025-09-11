/*
정수배열 크기가 10이고 2 미만 난수 발생
예시 :
0101110000
0
4
6
10개 수열값 출력 (완료)
어떤 값이 가장 긴가
구간의 길이가 얼마 (완료)
그 구간의 시작 인덱스를 출력
*/
#include<iostream>
using namespace std;

class cla {
private:
	int a[10];
	int plus[10]={0}, idx = 0,b;
public:
	void manage();
	void assign();
	void count();
	void compare();
};

void cla::manage() {
	void assign();
	void compare();
	void count();
}
void cla::assign() {
	srand(time(NULL));
	for(int i=0;i<10;i++){
		a[i] = rand() % 2;
		cout << a[i] << " ";
	}
	cout << endl;
}
void cla::count() {
	int plus[10] = { 0 }; // 같은 수가 아닐 때 배열 위치를 옮기면서 카운트 하기 위해 0으로 초기화
	int idx = 0; // 인덱스 초기화 
	int b = 1; // 인덱스 시작
	for (int i = 0; i < 10; i++) {
		if (a[i] == a[i - 1]) {
			plus[idx]++; //동일 수 카운트
			
		}
		else if(a[i] != a[i - 1]){
			idx++; // 인덱스 ++
			b += plus[idx]; // restart idx 만들기
		}
	}
}
void cla::compare() {
	int first = 0;
	while(true)
	if (plus[idx] < plus[idx + 1]) {
		first = plus[idx + 1]; // 길이가 최대인 값 찾기
		idx++;
	}
	cout << "최댓값: "<<first<<endl; // 최댓값
	cout << "인덱스: "<< b - 1<<endl; // 인덱스
	cout << "길이: " << 10 - b + 1; // 처음 시작부터 길이
}

int main() {
	cla nm;
	void manage();
	return 0;
}