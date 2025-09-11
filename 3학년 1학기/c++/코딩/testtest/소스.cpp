//학번: 2100998

//이름: 이수찬

//총점:



//1번
//#include<stdio.h>
//#include<string.h>
//#include<ctype.h>
//#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:6031)
//
//int main() {
//	char pw[100];
//	int has_upper, has_lower, has_digit;
// 
//	while (1) {
//		has_upper = has_lower = has_digit = 0;
//		printf("암호를 입력하세요 (공백없이):");
//		scanf("%100s", pw);
//		
//		for (int i = 0; i < strlen(pw); i++) {
//			if (isupper(pw[i]))has_upper = 1;
//			else if (islower(pw[i]))has_lower = 1;
//			else if (isdigit(pw[i]))has_digit = 1;
//		}
//
//		if (has_upper && has_lower && has_digit) {
//			printf("안전한 암호입니다.\n");
//		}
//		else {
//			printf("암호는 대문자, 소문자, 숫자를 모두 포함해야 한다. 다시 입력하시오\n");
//		}
//	}	
//}


/*정답*/



//2번
//#include<stdio.h>
//#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:6031)
//#pragma warning(disable:4996)  // scanf 보안 경고 무시
//
//typedef struct {
//	char name[20];
//	int ko, en, math;	
//	float avg;
//	int total;
//}STD;
//
//int main() {
//	STD s[4];
//	int i, idx=0;
//	for (i = 0; i < 4; i++) {
//		printf("이름, 국어, 영어 수학 점수를 입력: ");
//		scanf("%s %d %d %d", s[i].name, &s[i].ko, &s[i].en, &s[i].math);
//		 
//		s[i].total = s[i].ko + s[i].en + s[i].math;
//		s[i].avg = (s[i].ko + s[i].en + s[i].math) / 3.0;
//
//		if (s[i].total > s[idx].total) {
//			idx = i;
//		}
//	}
//
//	printf("최우수 학생 정보\n");
//	printf("이름, 국어, 영어, 수학, 총점, 평균:\n");
//	printf("% s, % d, % d, % d, %d,% f", s[idx].name, s[idx].ko, s[idx].en, s[idx].math, s[idx].total, s[idx].avg);
//}


/*정답*/



//3번
//#include<iostream>
//using namespace std;
//
//class Data {
//private:
//	int data[5]= {0};
//public:
//	Data();
//	void printData();
//	void getData();
//	int findMin();
//};
//
//Data::Data() {
//	//cout << "data" << endl;
//}
//void Data::printData() {
//	cout << "data: " << data[0]<< " " << data[1] << " " << data[2] << " " << data[3] << " " << data[4]<<endl;
//}
//void Data::getData() {
//	cout << "5개 정수 입력:";
//	for (int i = 0; i < 5; i++) {
//		cin >> data[i];
//	}
//}
//int Data::findMin() {
//	int tmp = 100000, min;
//	for (int i = 0; i < 5; i++) {
//		if (data[i] < tmp) {
//			tmp = data[i];
//		}
//	}
//	return min = tmp;
//}
//
//int main() {
//	Data data;
//	data.printData();
//	data.getData();
//	data.printData();
//	data.findMin();
//	cout << "최소값: " << data.findMin() << endl;
//}


/*정답*/



//4번

/*정답*/

//#include<iostream>
//using namespace std;
//
//class Box {
//private:
//	int width, height;
//	char a;
//public:
//	Box(int w, int h);
//	void draw();
//	void setSize(int w, int h);
//	void setFill(char b);
//	~Box();
//};
//
//Box::Box(int w, int h) {
//	width = w;
//	height = h;
//	a = '*';
//	cout << "폭" << w << "높이" << h << "문자" << a << "인 박스 생성" << endl;
//}
//void Box::draw() {
//	for (int i = 0; i < height; i++) {
//		for (int k = 0; k < width; k++) {
//			cout << a;
//		}
//		cout << endl;
//	}
//}
//void Box::setSize(int w, int h) {
//	width = w;
//	height = h;
//}
//void Box::setFill(char b) {
//	a = b;
//}
//
//Box::~Box() {
//	cout<< "폭" << width << "높이" << height << "문자" << a << "인 박스 소멸" << endl;
//}
//int main() {
//	Box b(10, 2);
//	cout << endl;
//	b.draw();
//	cout << endl;
//	b.setSize(7, 4);
//	b.setFill('^');
//	b.draw();
//	return 0;
//
//}


//문제 1-2(gpt출제)
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<ctype.h>
////#pragma warning(disable:4996)
//int main() {
//	char std_num[20];
//
//	while(1){
//		printf("학번 입력:");
//		scanf("%s", std_num);
//
//		if (std_num[0] == '2' && std_num[1] == '0') {
//			printf("정상적인 학번입니다.\n");
//			break;
//		}
//		else {
//			printf("잘못된 학번입니다. 다시 입력하세요.");
//		}
//		
//	}
//	return 0;
//}


////문제 2-1
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//typedef struct {
//	char name[20];
//	int c_s, s_s, o_s,total;
//	float avg;
//}Std;
//
//int main() {
//	Std s[3];
//	int idx=0,i;
//	for (i = 0; i < 3; i++) {
//		printf("이름, C언어, 자료구조, 운영체제 점수를 입력: ");
//		scanf("%s %d %d %d", s[i].name, &s[i].c_s, &s[i].s_s, &s[i].o_s);
//
//		s[i].total = s[i].c_s + s[i].s_s + s[i].o_s;
//		s[i].avg = (s[i].c_s + s[i].s_s + s[i].o_s) / 3.0;
//		if (s[i].total > s[idx].total) {
//			idx = i;
//		}
//	}
//
//	printf("최고 평균 학생 정보\n");
//	printf("%s %d %d %d %d %f", s[idx].name, s[idx].c_s, s[idx].o_s, s[idx].s_s, s[idx].total, s[idx].avg);
//}


//문제2-2
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//typedef struct {
//	char book_name[20];
//	char name[20];
//	int price;
//}Book;
//
//int main() {
//	Book book[5];
//	int idx=0, i;
//	for (i = 0; i < 5; i++) {
//		printf("책 제목, 저자, 가격 입력: ");
//		scanf("%s %s %d", book[i].book_name, book[i].name, &book[i].price);
//		if (book[i].price > book[idx].price) {
//			idx = i;
//		}
//	}
//	printf("가장 비싼 책 정보\n");
//	printf("%s %s %d", book[idx].book_name, book[idx].name, book[idx].price);
//}

//문제 3-1

//#include<iostream>
//using namespace std;
//
//class NumberSet {
//private:
//	int data[5];
//public:
//	NumberSet();
//	void input();
//	void display();
//	int getMax();
//};
//
//NumberSet::NumberSet() {
//
//}
//void NumberSet::input() {
//	cout << "정수 5개 입력:";
//	for (int i = 0; i < 5; i++) {
//		cin >> data[i];
//	}
//}
//void NumberSet::display() {
//	cout << "입력된 수: ";
//	for (int i = 0; i < 5; i++) {
//		cout << data[i]<< " ";
//	}
//}
//int NumberSet::getMax() {
//	int i, idx = 0;
//	for (i = 0; i < 5; i++) {
//		if (data[i] > data[idx]) {
//			idx = i;
//		}
//	}
//	return data[idx];
//}
//
//int main() {
//	NumberSet ns;
//	ns.input();
//	ns.display();
//	cout << "최댓값: " << ns.getMax() << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//class Quad {
//private:
//	int data[4];
//public:
//	Quad();
//	void setData(int a,int b,int c,int d);
//	int sum();
//	float avg();
//};
//
//Quad::Quad() {
//
//}
//
//void Quad::setData(int a, int b, int c, int d) {
//	data[0] = a;
//	data[1] = b;
//	data[2] = c;
//	data[3] = d;
//}
//
//int Quad::sum() {
//	int sum = 0;
//	for (int i = 0; i < 4; i++) {
//		sum += data[i];
//	}
//	return sum;
//}
//
//float Quad::avg() {
//	float avg = sum() / 4.0 ;//(data[0] + data[1] + data[2] + data[3]) / 4.0;
//	return avg;
//}
//int main() {
//	Quad q;
//	q.setData(10, 20, 30, 40);
//	cout << "합계: " << q.sum() << endl;
//	cout << "평균: " << q.avg() << endl;
//	return 0;
//}


//4-1번

//#include<iostream>
//using namespace std;
//class Rectangle {
//private:
//	int width, height;
//	char fillchar;
//public:
//	Rectangle(int w, int h);
//	void draw();
//	void setChar(char f);
//	void setSize(int w, int h);
//};
//
//Rectangle::Rectangle(int w,int h) {
//	width = 5;
//	height = 3;
//	fillchar = '*';
//}
//
//void Rectangle::draw() {
//	for (int i = 0; i < height; i++) {
//		for (int k = 0; k < width; k++) {
//			cout << fillchar;
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//
//void Rectangle::setChar(char f) {
//	fillchar = f;
//}
//
//void Rectangle::setSize(int w, int h) {
//	width = w;
//	height = h;
//}
//
//int main() {
//	Rectangle r(5, 3);
//	r.draw();
//	r.setChar('#');
//	r.setSize(7, 2);
//	r.draw();
//	return 0;
//}


//4-2번
//#include<iostream>
//using namespace std;
//class Triangle {
//private:
//	int height;
//	char fill;
//public:
//	Triangle();
//	void set(int h, char a);
//	void draw();
//};
//
//Triangle::Triangle() {
//	height = 0;
//	fill = '*';
//}
//
//void Triangle::set(int h, char a) {
//	height = h;
//	fill =a;
//}
//
//void Triangle::draw() {
//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j <=i; j++) {
//			cout << fill;
//		}
//		cout << endl;
//	}
//}
//
//int main() {
//	Triangle t;
//	t.set(4, '$');
//	t.draw();
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
 
typedef struct {
	char name[20];
	int ko, en, ma, total;
	float avg;
}S;
int main() {
	S std[4];
	int idx=0;
	for (int i = 0; i < 4; i++) {
		printf("이름, 국어, 영어, 수학점수를 입력: ");
		scanf("%s %d %d %d", std[i].name, &std[i].ko, &std[i].en, &std[i].ma);

		std[i].total = std[i].ko + std[i].en + std[i].ma;
		if (std[i].total > std[idx].total) {
			idx = i;
		}
		std[i].avg = std[i].total / 3;
	}
	printf("최우수 학생 정보\n 이름, 국어, 영어, 수학, 총점, 평균\n %s %d %d %d %d %f",std[idx].name,std[idx].ko,
		std[idx].en, std[idx].ma, std[idx].total, std[idx].avg);
}

