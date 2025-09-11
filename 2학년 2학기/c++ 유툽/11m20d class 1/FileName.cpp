#include<iostream>
using namespace std;

class cla {
private:
	int nm1,nm2;
public:
	void setnum(int a,int b);
	void sum();
};

void cla::setnum(int a,int b) {
	nm1 = a;
	nm2 = b;
}

void cla::sum() {
	cout << nm1 + nm2 << endl;
}

int main() {
	cla* c1 = new cla;
	int a,b;
	cin >> a >> b;
	c1->setnum(a, b);
	cla c2(*c1);
	c2.sum();
	return 0;
}