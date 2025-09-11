#include<iostream>
#include<string>
using namespace std;
//학번:2100998
//이름:이수찬
//총점:

//1번
/*정답*/
class Point3D {
	int a, b, c;
public:
	Point3D(int a = 0, int b = 0, int c = 0) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	void show() {
		cout << "3차원 점의 좌표는" << a << "," << b << "," << c << endl;
	}
};

int main() {
	Point3D p0;
	p0.show();
	Point3D p1(1);
	p1.show();
	Point3D p2(1, 2);
	p2.show();
	Point3D p3(1, 2, 3);
	p3.show();
	return 0;
}



////2번
///*정답*/
//void f(char arr=' ', int size = 1) {
//	for (int j = 0; j < size; j++) {
//		for (int i = 0; i < 10; i++) {
//			cout << arr;
//		}
//		cout << endl;
//	}
//}
//int main() {
//	f();
//	f('%');
//	f('@', 5);
//	return 0;
//}
//
//
//
////3번
///*정답*/
//string getString(string str[], string &first, string &last);
//
//int main() {
//	string str[4], first, last;
//
//	for (int i = 0; i < 4; i++) {
//		cout << i + 1 << "번째 이름 입력:";
//		getline(cin, str[i], '\n');
//	}
//	getString(str, first, last);
//	cout << "제일 앞에 나오는 이름" << first << endl;
//	cout << "제일 뒤에 나오는 이름: " << last << endl;
//	return 0;
//}
//string getString(string str[], string &first, string &last) {
//	last = str[0];
//	first = str[0];
//	for (int i = 0; i < 4; i++) {
//		if (str[i] > last) {
//			last = str[i];
//		}
//	}
//	for (int i = 0; i < 4; i++) {
//		if (str[i] < first) {
//			first = str[i];
//		}
//	}
//	return last, first;
//}
//
//
//
//
////4번
///*정답*/
//class Circle {
//	int radius;
//public:
//	Circle() {
//		cout << "원생성" << endl;
//	}
//	void setRadius(int radius){
//		this->radius=radius;
//	}
//	double getArea() {
//		return radius * radius * 3.14;
//	}
//	~Circle() {
//		cout <<"원 소멸" << endl;
//	}
//};
//int main() {
//	int size;
//	int radius;
//	cout << "생성하고자 하는 원의 갯수";
//	cin >> size;
//	Circle* p=new Circle[size];
//	for (int i = 0; i < size; i++) {
//		cout << "원" << i << "반지름 입력";
//		cin >> radius;
//		p[i].setRadius(radius);
//	}
//	for (int i = 0; i < size; i++) {
//		cout << i << "번째 원의 면적" << p[i].getArea() << endl;
//	}
//	delete[] p;
//}
//
//
//
////5번
///*정답*/
//class Book {
//	char* title;
//	int price;
//public:
//	Book(const char* title, int price) {
//		for(int i=0;i<title.length();i++){
//			this->title[i] = title[i];
//			this->price = price;
//	}
//	Book(Book& b) {
//		for (int i = 0; i < b. i++) {
//
//		}
//
//	}
//	~Book();
//	void set(const char* title, int price);
//	void show() { cout << title << ' ' << price << "원" << endl; }
//};
//
//int main() {
//	Book cpp("명품C++", 10000);
//	Book java = cpp;
//	java.set("명품자바", 12000);
//	cpp.show();
//	java.show();
//	return 0;
//}