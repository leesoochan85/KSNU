//5-1장 과제2
#include<iostream>
#include<string>
using namespace std;
string GetLatterString(string str1, string str2);

int main() {
	string s1("hello");
	string s2("world");
	string res;
	res = GetLatterString(s1, s2);
	cout << "사전에서 뒤에 나오는 문자열은 " << res << "입니다";
}
string GetLatterString(string str1, string str2) {
	if (str1 > str2) return str1;
	else return str2;
}


//5-1장 과제3
string GetLatterString(string *str1, string *str2);

int main() {
	string s1("hello");
	string s2("world");
	string res;
	res = GetLatterString(&s1, &s2);
	cout << "사전에서 뒤에 나오는 문자열은 " << res << "입니다";
}

string GetLatterString(string *str1, string *str2) {
	return (*str1 > *str2) ? *str1 : *str2;
}

////5-1장 과제4
void SwapString(string* s1, string* s2);

int main() {
	string s1("hello");
	string s2("world");
	cout << "호출전 s1 : " << s1 << " s2 : " << s2 << endl;
	SwapString(&s1,&s2); // 함수 호출
	cout << "호출후 s1 : " << s1 << " s2 : " << s2 << endl;
}

void SwapString(string* s1, string* s2) {
	string tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

////5-1장 과제5 *******
string StringLatter(string str[],int n);
int main() {
	string names[5];
	for (int i = 0; i < 5; i++) {
		cout << "이름 >> ";
		getline(cin, names[i], '\n');
	}
	string res = StringLatter(names, 5);
	cout << "사전에서 가장 뒤에 나오는 문자열은 " << res << endl;
}

string StringLatter(string str[],int n) {
	string tmp;
	for (int i = 0; i < n;i++) {
		if (str[i] > str[0]) str[0] = str[i];
	}
	return str[0];
}


//5-2장 과제2 
void add2(int &value);
int main(void)
{
	int number;
	cout << "정수를 입력하세요 : ";
	cin >> number;
	add2(number);
	cout << "2만큼 증가한 값 :" << number << endl;
	return 0;
}
void add2(int &value)
{
	//int& numbe = value;
	value += 2;
}


//5-2장 과제3
void Swap(int& num1, int& num2);
int main() {
	int num1, num2;
	cout << "정수입력1";
	cin >> num1;
	cout << "정수입력2";
	cin >> num2;
	cout << "Swap함수 호출 전: " << " n1: " << num1 << " n2: " << num2 << endl;
	Swap(num1, num2);
	cout << "Swap함수 호출 후: " << " n1: " << num1 << " n2: " << num2 << endl;
}
void Swap(int& num1, int& num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}


//5-2장 과제4 *********
/*double get_parts(double num) {
	return num - (int)num;

}
int main() {
	double num1;

	cout << "실수 입력";
	cin >> num1;
	double d=get_parts(num1);
	cout << "정수부: " << (int)(num1 / 1);
	cout << "실수부: " << d;
}*/

//void get_parts(double num1, int& i, double& d);
//
//int main() {
//	double num1;
//	int i;
//	double d;
//	cout << "실수 입력";
//	cin >> num1;
//	get_parts(num1, i, d);
//	cout << "정수부: " << i << endl;
//	cout << "실수부: " << d;
//}
//
//void get_parts(double num1, int& i, double& d) {
//	i = (int)num1;
//	d = num1 - i;
//}

////5-3장 과제2***
void Uppercase(string &str);

int main() {
	string s1("hello");
	cout << "변환전 문자열" << s1 << endl;
	Uppercase(s1);
	cout << "변환후 문자열" << s1 << endl;
	return 0;
}

void Uppercase(string &str) {
	for (int i = 0; i < str.length(); i++) {
		str[i]=toupper(str[i]);
	}
}



//5-3장 과제3

void SwapString(string& str1, string& str2);

int main() {
	string s1("hello");
	string s2("world");
	cout << "교환전 문자열" << s1 <<' ' << s2 << endl;
	SwapString(s1, s2);
	cout << "교환후 문자열" << s1 <<' ' << s2 << endl;
	return 0;
}

void SwapString(string& str1, string& str2) {
	string tmp = str1;
	str1 = str2;
	str2 = tmp;
}


//5-4장 과제2*******
//예제 5-11에서 문자열 저장을 위하여 char 배열을 사용하는데
// 이것을 string 클래스를 이용한 코드로 변경 하시오.
//멤버변수, 멤버함수 수정이 필요한 곳을 모두 변경할 것
// string 클래스를 이용하면 문자열크기를 자동으로 조절하므로
// 동적할당을 사용할 필요가 없으므로 깊은 복사생성자를 작성할 필요 없음
class Person {
	string name;//char* name;
	int id;
public:
	Person(int id, const string& name);
	Person(Person& person);
	~Person();
	void changeName(const string& name);
	void show() { cout << id << ',' << name << endl; }
};

Person::Person(int id, const string& name){//  const char* name => const string& name
	this->id = id;
	//int len = strlen(name);
	this->name = name;//= new char[len + 1]=>name;
	//strcpy(this->name, name);
}
/*Person::Person(Person& person) {
	this->id = person.id;
	int len = strlen(person.name);
	this->name = new char[len + 1];
	strcpy(this->name, person.name);
	cout << "복사 생성자 실행. 원본 객체의 이름" << this->name << endl;
}

Person::~Person() {
	if (name) delete[] name;
}*/ 
void Person::changeName(const string& name) {
	if (name.length() > this->name.length())return; //if (strlen(name) > strlen(this->name)) return;
	this->name = name;//strcpy(this->name, name);
}
int main() {
	Person father(1, "Kitae");
	Person daughter(father);

	cout << "daughter 객체 생성 직후" << endl;
	father.show();
	daughter.show();
	daughter.changeName("Grace");

	cout << "daughter 이름을 Grace로 변경한 후" << endl;
	father.show();
	daughter.show();
	return 0;
 }


//5-4장 과제3 (1),(2),(3)
class Book {
	char* title;
	int price;
public:
	Book(const char* title, int price);
	~Book();
	void set(char* title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(const char* title, int price) {
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
	this->price = price;
}

Book::Book(const Book& other) {
	int len = strlen(other.title);
	title = new char[len + 1];
	strcpy(title, other.title);
	price = other.price;
}

Book::~Book() {
	if (title)delete[] title;
}
void Book::set(char* title, int price) {
	if (this->title)delete[] this->title;
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
	this->price = price;
}
int main() {
	Book cpp("명품C++", 10000);
	/*Book(const Book& other)
		:title(other),price(other.price){}*/ //컴파일러가 삽입하는 디폴트 복사 생성자 코드.
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}

////5-4장 과제3 (4)*****
class Book {
	string title;
	int price;
public:
	Book(const string& title, int price) :title(title), price(price) {}
	void set(const string& title, int price) {
		this->title = title;
		this->price = price;
	}
	void show() { cout << title << ' ' << price << "원" << endl; }
};

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}


//5-5장 과제1 (1)
class Circle {

};
void Swap(Circle &c1,Circle&c2) {
	Circle tmp = c1;
	c1 = c2;
	c2 = tmp;
}
int main() {
	Circle c1, c2;
	Swap(c1, c2);

}



////5-5장 과제1 (2)
double half(double &d) {
	return d=d / 2.0;
}

int main() {
	double n = 20;
	half(n);
	cout << n;
}



//5-5장 과제1(3)
void combine(string s1, string s2,string &s3) {
	s3 = s1 + s2;
}
int main() {
	string text1("I love you"), text2("very much");
	string text3;
	combine(text1, text2, text3);
	cout << text3;
}

////5-5장 과제1 (4) ***
bool bigger(int a, int b, int& big) {
	if (a == b) return true;
	if (a > b) big = a;
	else big = b;
	return false;
}

int main() {
	int a, b, big;
	bool b;
	b = bigger(a, b, big); 
	if (b)
		cout << "same" << endl;
	else
		cout << "큰 수는 " << big << endl;
}

//5-5장 과제1 (5)
class Circle {
	int radius;
public:
	Circle(int r) { radius = r; }
	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { cout << "반지름이 " << radius << "인 원 " << endl; }
};

void increaseBy(Circle &a, Circle b) {
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
}

int main() {
	Circle x(10), y(5);
	increaseBy(x, y);
	x.show();
}