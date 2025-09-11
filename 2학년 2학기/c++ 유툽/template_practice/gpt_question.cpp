/*
#include<iostream>
using namespace std;
template<typename T, typename U>
double add(T a, U b) {
	return a + b;
}

int main() {
	int A = 10;
	double B = 20.5;
	cout << add(A, B) << endl;
	cout << add((float)A, B) << endl;
	cout << add(A, (double)B) << endl;

	return 0;
}
*/

#include<iostream>
using namespace std;
template<typename T>
T average(T* arr, int size) {
	T sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum / size;
}

int main() {
	int intArr[] = { 1, 2, 3, 4, 5 };
	double doubleArr[] = { 1.5,2.5,3.5,4.5,5.5 };

	size_t intSize = sizeof(intArr) / sizeof(intArr[0]);
	size_t doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);

	cout << "Average of int array:" << average(intArr, intSize) << endl;
	cout << "Average of double array" << average(doubleArr, doubleSize) << endl;
}