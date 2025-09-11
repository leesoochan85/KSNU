#include<iostream> //입출력 헤더파일 
using namespace std;//이름공간선언

class Sphere {//클래스 선언
private://접근지정자
	int radius, num; //정수변수 선언
public://접근지정자
	float getArea();//구 부피 매개함수
	void setRadius(int r);//반지름설정
};

float Sphere::getArea() {//면적 매개함수
	return (4.0/3.0)*3.14*radius*radius*radius;//부피값 리턴
}

void Sphere::setRadius(int r) {
	radius = r;//생성자 반지름선언
}

int main() {
	cout << "생성하고자 하는 구의 갯수: ";
	int num,radius;
	cin >> num;
	Sphere *s = new Sphere[num]; // 동적할당 받기위한 포인터 변수 선언
	if (!s) {//메모리 오류 체크
		cout << "메모리부족";
		return -1;
	}
	for (int i = 1; i < num+1; i++) { 
		cout << "구" << i<<"의 반지름: ";
		cin >> radius;
		s[i - 1].setRadius(radius); // 반지름 설정
	}

	for (int i = 0; i < num; i++) {
		cout << s[i].getArea() << endl; //부피 구하기
	}

	delete []s;//각 메모리공간 해제
}