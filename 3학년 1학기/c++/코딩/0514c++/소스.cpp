#include<iostream>
using namespace std;

class Circle {
private:
	int* radius;  // 반지름 배열
	int num;      // 원의 개수
public:
	Circle(int n) {
		num = n;
		radius = new int[n];  // 동적 할당
	}

	void setRadius() {
		for (int i = 0; i < num; i++) {
			cout << "원 " << i + 1 << "의 반지름: ";
			cin >> radius[i];
		}
	}

	float getArea(int i) {
		return 3.14 * radius[i] * radius[i];
	}

	void countLargeCircle() {
		int count = 0;
		for (int i = 0; i < num; i++) {
			if (getArea(i) > 100)
				count++;
		}
		cout << "면적이 100보다 큰 원은 " << count << "개 입니다." << endl;
	}

	~Circle() {
		delete[] radius;  // 메모리 해제
	}
};

int main() {
	int num;
	cout << "원의 갯수 >> ";
	cin >> num;

	Circle c(num);
	c.setRadius();
	c.countLargeCircle();

	return 0;
}
