#include<iostream>
using namespace std;

template<typename T>
T abs(T value);
int main() {
	int intval = 10;
	double douval = -123.456;
	cout << abs(intval) << endl;
	cout << abs(douval) << endl;
	return 0;
}

template<typename T>
T abs(T value) {
	if (value < 0)
		return -value;
	else
		return value;
}
