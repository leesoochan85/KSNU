#include<iostream>
using namespace std;

class Triangle {//클래스 생성
private://접근지정자
	int width, height;//멤버변수 생성
public://접근지정자
	Triangle();//생성자 생성
	int setWidth(int w);//멤버함수 선언
	int setHeight(int h);//멤버함수 선언
	double getArea();//멤버함수 선언
};//클래스 생성 종료


Triangle::Triangle() {
	;
}
int Triangle::setWidth(int w) {
	return width = w;
}

int Triangle::setHeight(int h) {
	return height = h;
}

double Triangle::getArea() {
	return 0.5 * width * height;
}

int main() {
	Triangle tri;
	Triangle* t;
	t = &tri;

	// 객체포인터변수 선언 및 초기화 코드 추가
	t->setWidth(3); // 객체포인터 표현으로 변경
	t->setHeight(5); // 객체포인터 표현으로 변경
	cout << "삼각형의 면적은" << t->getArea() << endl; //포인터표현으로 변경
	return 0;
}
