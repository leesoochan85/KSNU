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