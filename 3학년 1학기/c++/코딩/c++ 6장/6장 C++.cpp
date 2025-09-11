#include<iostream>
#include<string>
using namespace std;

//6-3장 과제2
class MyMath {
public:
	static int GetMax(int arr[], int size) {
		for (int i = 0; i < size; i++) {
			if (arr[i] > arr[0]) {
				arr[0] = arr[i];
			}
		}
		return arr[0];
	}
	static int GetMin(int arr[], int size) {
		for (int i = 0; i < size; i++) {
			if (arr[i] < arr[0]) {
				arr[0] = arr[i];
			}
		}
		return arr[0];
	}
};

int main() {
	int x[5] = { 20, 30, -5, 2, -30 };
	cout << "최대값은 :" << MyMath::GetMax(x, 5) << endl;
	cout << "최소값은 :" << MyMath::GetMin(x, 5) << endl;
	return 0;
}

//6-3장 과제3******

class Triangle {
	static int numOfTriangle;
public:
	Triangle() {
		numOfTriangle++;
	}
	~Triangle() {
		numOfTriangle--;
	}
	static int getNumofTriangle() {
		return numOfTriangle;
	}
};

int Triangle::numOfTriangle = 0;

int main() {
	Triangle* tri1 = new Triangle[5];
	cout << "생성된 삼각형의 개수 :" << Triangle::getNumofTriangle() << endl;
	delete[] tri1;
	Triangle tri2[15];
	cout << "생성된 삼각형의 개수 :" << Triangle::getNumofTriangle() << endl;
	return 0;
}



//6-3장 과제4 (1)-1***

int add(int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}
int add(int arr[], int size, int arr2[]) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i]+arr2[i];
	}
	return sum;
}

int main() {
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int c = add(a, 5);
	int d = add(a, 5, b);
	cout << c << endl;
	cout << d << endl;
}


//6-3장 과제4 (1)- 2 ****
int add(int arr[], int size,int arr2[]=nullptr) {
	int sum = 0;
	if (arr2 == nullptr) {
		for (int i = 0; i < size; i++) {
			sum += arr[i];
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			sum += arr[i] + arr2[i];
		}
	}
	return sum;
}

int main() {
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int c = add(a, 5);
	int d = add(a, 5, b);
	cout << c << endl;
	cout << d << endl;
}


//6-3장 과제4 (2)-2
class Person {
	int id;
	double weight;
	string name;
public:
	void show() { cout << id << ' ' << weight << ' ' << name << endl; }
	Person(int id = 1, string name = " ", double weight = 20.5) {
		this->id = id;
		this->name = name;
		this->weight = weight;
	}
};


int main() {
	Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
	grace.show();
	ashley.show();
	helen.show();
}

//6-3장 과제3 (2)-1
class Person {
	int id;
	double weight;
	string name;
public:
	void show() { cout << id << ' ' << weight << ' ' << name << endl; }
	Person(int id, string name, double weight) {
		this->id = id;
		this->name = name;
		this->weight = weight;
	}
	Person(int id, string name) {
		this->id = id;
		this->name = name;
		this->weight = 20.5;
	}
	Person() {
		this->id = 1;
		this->name = "grace";
		this->weight = 20.5;
	}
};


int main() {
	Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
	grace.show();
	ashley.show();
	helen.show();
}

//6-3장 과제4 (3)-1
int big(int a, int b) {
	int big = a;
	if (a > b) {
		if (a < 100) big = a;
		else big = 100;
	}
	else {
		if (b < 100) big = b;
		else big = 100;
	}
	return big;
}
int big(int a, int b,int c) {
	int big = a;
	if (a > b &&a>c) {
		if(a<50) big = a;
		else {
			big = 50;
		}
	}
	else if (a < b && c < b) {
		if (b < 50)big = b;
		else {
			big = 50;
		}
	}
	else if (a < c && b < c) {
		if (c < 50)big = c;
		else {
			big = 50;
		}
	}
	return big;
}
int main() {
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << endl;
}

//6-3장 과제4 (3)-2 ******
int big(int a, int b, int c=NULL) {
	if (c == NULL) {
		int big = (a > b) ? a : b;
		return (big < 100) ? big : 100;
	}
	else {
		int big = a;
		if (big < b)big = b;
		if (big < c)big = c;
		return big > 50 ? 50 : big;
	}
}
int main() {
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << endl;
} 


//6-3 과제4 (4)
class MyVector {
	int* mem;
	int size;
public:
	MyVector(int n = 100, int val = 0) {
		mem = new int[n];
		size = n;
		for (int i = 0; i < size; i++) mem[i] = val;
	}
	~MyVector() { delete[]mem; }
};

//6-3장 과제4 (5)************
class ArrayUtility {
public:
	static void intToDouble(int source[], double dest[], int size); // int 배열을 double 배열로 변환
	static void doubleToInt(double source[], int dest[], int size); // double 배열을 int 배열로 변환
};

void ArrayUtility::intToDouble(int source[], double dest[], int size) {
	for (int i = 0; i < size; i++)
		dest[i] = (double)source[i];
}

void ArrayUtility::doubleToInt(double source[], int dest[], int size) {
	for (int i = 0; i < size; i++)
		dest[i] = (int)source[i];
}

int main() {
	int x[] = { 1,2,3,4,5 };
	double y[5];
	double z[] = { 9.9, 8.8, 7.7, 6.6, 5.6 };

	ArrayUtility::intToDouble(x, y, 5); // x[] -> y[]
	for (int i = 0; i < 5; i++) cout << y[i] << ' ';
	cout << endl;

	ArrayUtility::doubleToInt(z, x, 5); // z[] -> x[]
	for (int i = 0; i < 5; i++) cout << x[i] << ' ';
	cout << endl;
}