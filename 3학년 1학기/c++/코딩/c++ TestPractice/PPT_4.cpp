
#include<iostream>
using namespace std;
//ppt
//4-1 과제2
class Triangle {
	int width, height;
public:
	void setWidth(int w) { width = w; }
	void setHeight(int h) { height = h; }
	double getArea() { return 0.5 * width * height; }
};

int main() {
	Triangle tri;
	tri.setWidth(3);
	tri.setHeight(5);
	cout << "triArea: " << tri.getArea() << endl;
	return 0;
}




//4-1 과제3
class Triangle {
	int width, height;
public:
	Triangle() {
		width = 1;
		height = 1;
	}
	Triangle(int width) {
		this->width = width;
		height = 1;
	}
	Triangle(int width, int height) {
		this->height = height;
		this->width = width;
	}
	double getArea() { return 0.5 * width * height; }
};

int main() {
	Triangle tri1; // 밑변=높이=1로 초기화
	cout << "삼각형의 면적은 " << tri1.getArea() << endl;
	Triangle tri2(10); // 밑변=10,높이=1로 초기화
	cout << "삼각형의 면적은 " << tri2.getArea() << endl;
	Triangle tri3(10, 2); // 밑변=10,높이=2로 초기화
	cout << "삼각형의 면적은 " << tri3.getArea() << endl;

	return 0;
}




4-1장 과제4
class Triangle {
	int width, height;
public:
	Triangle() {
		width = height= 1;
	}
	void setopt(int num) {
		width = height = num;
	}
	double getArea() { return 0.5 * width * height; }
};
int main() {
	Triangle tri[3];
	int num[3] = { 2,4,6 };
	for (int i = 0; i < 3; i++) {
		tri[i].setopt(num[i]);
		cout<<i<<"Area: "<<tri[i].getArea()<<endl;
	}
}




//4-1장 과제5
class Triangle {
	int width, height;
public:
	Triangle() {
		width = 1;
		height = 1;
	}
	Triangle(int width) {
		this->width = width;
		height = 1;
	}
	Triangle(int width, int height) {
		this->height = height;
		this->width = width;
	}
	double getArea() { return 0.5 * width * height; }
};

int main() {
	Triangle* tri1 = new Triangle(); // 밑변=높이=1로 초기화
	cout << "삼각형의 면적은 " << tri1->getArea() << endl;
	Triangle* tri2 = new Triangle(10); // 밑변=10,높이=1로 초기화
	cout << "삼각형의 면적은 " << tri2->getArea() << endl;
	Triangle* tri3 = new Triangle(10, 2); // 밑변=10,높이=2로 초기화
	cout << "삼각형의 면적은 " << tri3->getArea() << endl;

	return 0;
}




//4-2장 과제2
int main() {
    int num;
    int sum = 0;
    cout << "enter int";
    cin >> num;             
    int* arr = new int[num];
    cout << num << "개 정수 입력";
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    double avg = sum / num;
    cout << "avg" << avg;

    delete[]arr;
}



//4-2장 과제3
int main() {
	int num;
	double big;
	cout << "num of double: ";
	cin >> num;
	double* arr = new double[num];
	cout << "enter double:";
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		if (arr[i] > arr[0]) {
			big = arr[i];
		}
	}
	cout << "big: " << big;
	delete[]arr;
}





////4-2장 과제4*************
int main() {
	int num;
	cout << "length of num";
	cin >> num;
	cin.ignore(); // 엔터(개행 문자) 제거

	char* str = new char[num];

	cout << "enter String";
	cin.getline(str,num);
	cout << str[num];
	delete[] str;
}

//4-3장 과제2
class Circle {
	int radius;
public:
	Circle(int radius) {
		this->radius = radius;
	}
	double getArea() {
		return radius * radius * 3.14;
	}
};
int main() {
	int radius;
	while (true) {
		cout << "반지름 입력(음수이면 종료)>>";
		cin >> radius;
		if (radius < 0)break;
		Circle* p = new Circle(radius);
		cout << "원의 면적: " << p->getArea() << endl;
		delete p;
	}
}


//4-3장 과제3
class Circle {
	int radius;
public:
	double getArea() {
		return radius * radius * 3.14;
	}
};
int main() {
	Circle* pArray = new Circle[3];
	for (int i = 0; i < 3; i++) {
		cout << pArray[i].getArea() << '\n';
	}
	delete[] pArray;
}


//4-3장 과제4 ***********
class Triangle {
	int width, height;
public:
	Triangle(int num ) {
		width = num;
		height = num;
		cout << "w:" << width << " h: " << height << " Tri 생성" << endl;
	}
	double getArea() { return 0.5 * width * height; }

	~Triangle() {
		cout << "w:" << width << " h: " << height << " Tri 소멸" << endl;
	}
};
int main() {  
	Triangle* tri = new Triangle[3]{ Triangle(1),Triangle(2),Triangle(4) };
	
	for (int i = 0; i < 3; i++) {
		cout<<i<<"Area: "<<tri[i].getArea()<<endl;
	}
	delete[] tri;
}



//4-3장 과제5
class Sphere {
	int radius;
public:
	void setRadius(int radius) {
		this -> radius = radius;
	}
	double getVolume() {
		return radius * radius * radius * (4.0 / 3.0)*3.14;
	}
};
int main() {
	int radius;
	int num;
	cout << "num of sphere";
	cin >> num;
	Sphere* sph = new Sphere[num];
	for (int i = 0; i < num; i++) {
		cout << "구 " << i+1 << ' ';
		cin >> radius;
		sph[i].setRadius(radius);
	}
	for (int i = 0; i < num; i++) {
		cout << "sphere volume: " << sph[i].getVolume()<<endl;
	}
	delete[]sph;
}


//4-4장 과제2
#include<string>
int main() {
	string str;
	do {
		cout << "문자열 입력: ";
		getline(cin, str);
		if (str != "quit") cout << "입력된 문자열: " << str << endl;
	} while (str != "quit");
}


////4-4장 과제3
int main() {
	string str, str1=" ";
	do {
		cout << "문자열 입력: ";
		getline(cin ,str);
		if (str != "quit") {
			str1.append(str);
			str1.append(" ");
			cout << "이어진 문자열: " << str1<<endl;
		}
	} while (str != "quit");
}

//4-4장 과제4
int main() {
	string str;
	int count = 0;
	cout << "문자열 입력";
	getline(cin, str);
	for (int i = 0; i < str.length();i++) {
		if(str[i]=='a') count++;
	}
	cout << count;
}



//연습문제
4-2
int main() {
	int space;
	float sum = 0;

	cin >> space;
	if (space <= 0)return 0;
	int* p = new int[space];
	cout << "입력한 정수만큼 입력: ";
	for (int i = 0; i < space; i++) {
		cin >> p[i];
		sum += p[i];
	}
	cout << "평균: " << sum / 5;
}


//4-3(1)
#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	int count = 0;
	
	cout << "문자열 입력";
	getline(cin, str);
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'a') {
			count++;
		}
	}
	cout<<"갯수:"<<count;
}

//4-4
#include<iostream>
using namespace std;

class Sample {
	int* p;
	int size;
public:
	Sample(int n) {
		size = n;
		p = new int[n];
	}
	void read() {
		for (int i = 0; i < size; i++) {
			cin >> p[i];
		}
	}
	void write() {
		for (int i = 0; i < size; i++) {
			cout << p[i] << ' ';
		}
	}
	int big() {
		int num;
		for (int i = 0; i < size; i++) {
			if (p[i] > p[0]) {
				num=p[i];
			}
		}
		return num;
	}
	~Sample() {}
};

int main() {
	Sample s(10);
	s.read();
	s.write();
	cout << "big" << s.big() << endl;
}

//4-6
#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	char tmp;
	for (int i = 0; i < str.length() / 2; i++) {
		tmp = str[i];
		str[i] = str[str.length() - i - 1];
		str[str.length() - i - 1] = tmp;
	}
	cout << str;
}




//4-7

class Circle {
	int radius;
public:
	Circle() {
		radius = 1;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
	double getArea() {
		return radius * radius * 3.14;
	}
};

int main() {
	Circle circle[3];
	int radius, count = 0;
	for (int i = 0; i < 3; i++) {
		cout <<"원 " << i << " 반지름>>>" ;
		cin >> radius;
		circle[i].setRadius(radius);
		if (circle[i].getArea() > 100) {
			count++;
		}		
	}
	cout << "100up " << count;
}

//4-8
class Circle {
	int radius;
public:
	Circle() {
		radius = 1;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
	double getArea() {
		return radius * radius * 3.14;
	}
};

int main() {
	int n;
	cout << "원의 갯수>>";
	cin >> n;
	Circle *circle=new Circle[n];
	int radius, count = 0;
	for (int i = 0; i < n; i++) {
		cout << "원 " << i << " 반지름>>>";
		cin >> radius;
		circle[i].setRadius(radius);
		if (circle[i].getArea() > 100) {
			count++;
		}
	}
	cout << "100up " << count;
}

//4-9 <미완>
//class Person {
//	string name;
//	string tel;
//public:
//	Person();
//	string getName() { return name; }
//	string getTel() { return tel; }
//	void set(string name, string tel) {
//		this->name = name;
//		this->tel = tel;
//	}
//};
//
//int main() {
//	string name, tel;
//	Person person[3];
//	for (int i = 0; i < 3; i++) {
//		cout << i<< "name, tel";
//		cin >> name >> tel;
//		person->set(name, tel);
//	}
//	cout << "all people";
//	for (int i = 0; i < 3; i++) {
//		cout << person->getName();
//	}
//	cout << "이름 입력";
//	for (int i = 0; i < 3; i++) {
//		if () {
//
//		}
//		else {
//
//		}
//	}
//}




//#include<iostream>
//using namespace std;
//
//class MyMath {
//public:
//	static int GetMax(int arr[], int b) {
//		int max = arr[0];
//		for (int i = 0; i < b; i++) {
//			if (arr[i] > max)max = arr[i];
//		}
//	}
//	static int GetMin(int arr[], int b) {
//		int min = arr[0];
//		for (int i = 0; i < b; i++) {
//			arr[i] < min ? min : arr[i];
//		}
//	}
//};
//
//int main() {
//	int x[5] = { 20, 30, -5, 2, -30 };
//	cout << "최대값은 :" << MyMath::GetMax(x, 5) << endl;
//	cout << "최소값은 :" << MyMath::GetMin(x, 5) << endl;
//	return 0;
//}
