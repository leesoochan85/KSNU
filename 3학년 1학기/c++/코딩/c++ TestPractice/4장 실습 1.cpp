#include<iostream>
using namespace std;
class color {
	int red, green, blue;
public:
	color() { red = green = blue = 0; }
	color(int r, int g, int b) { red = r; green = g; blue = b; }
	void setcolor(int r, int g, int b) {red = r; green = g; blue = b;}
	void show() {cout << red << ' ' << green << ' ' << blue << endl;}
};

int main() {
	color screencolor(255, 0, 0);
	color* p;
	p = &screencolor;
	p->show();//p와 show()를 이용하여 screencolor 색 출력
	color colors[3]; // color의 일차원 배열 colors 선언, 원소는 3개
	p = colors; //p가 colors의 배열을 가리키도록 코드 작성
	p->setcolor(255, 0, 0);//p와 setcolor()를 이용하여 colors[0],colors[1],colors[2]가 각각 빨강, 초록, 파랑을 가지도록 코드 작성
	(p + 1)->setcolor(0, 255, 0);
	(p + 2)->setcolor(0, 0, 255);

	for (int i = 0; i < 3; i++) {
		(p + i)->show();//p와 show()를 이용하여 colors 배열의 모든 객체의 색 출력. for문 이용
	}
	return 0;
}