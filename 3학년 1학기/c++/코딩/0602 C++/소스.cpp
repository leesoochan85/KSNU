#include<iostream>
using namespace std;

string combine(string &text1, string &text2, string &text3) {
    return text3 = text1 + text2 ;
}

int main() {
    string text1(" I love you "), text2("very much");
    string text3;
    combine(text1, text2, text3);
    cout << text3;

}



//#include<iostream>
//using namespace std;
//
//class Circle {
//	int radius;
//public:
//	Circle(int r) { radius = r; }
//	int getRadius() { return radius; }
//	void setRadius(int r) { radius = r; }
//	void show() { cout << "반지름이 " << radius << "인 원" << endl; }
//};
//
//void increase