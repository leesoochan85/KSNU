
#include <iostream>
#include <conio.h>
#include <random>
#include <ctime>

using namespace std;

class cla {
private:
    int a[10];
public:
    void manage();
    void shuf(int arr[],int size);
};

void cla::manage() {
    int i;
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        a[i] = rand() % 100;
    }
    for (i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    while (true) {
        int key = _getch();
        if (key == 27) break; 
        else if (key == 32) { 
            for (i = 0; i < 10; i++) {
                shuf(a,10);
            }
            for (i = 0; i < 10; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
}
/*
void cla::shuf() {
    random_device rd; 
    mt19937 g(rd());  
    shuffle(a, a + 10, g); 
}*/
/*
void cla::shuf(int arr[],int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}*/

int main() {
    cla nm;
    nm.manage();
    return 0;
}


/*
#include <iostream>
#include<conio.h>
#include <windows.h>

using namespace std;

class cla {
private:
    int a[10];
public:
    void manage();
};

void cla::manage() {
    int i, a[10] = { 1,1,1,0,0,0,0,0,0,0 };
    
    while (true) {
        system("cls");

        for (i = 0; i < 10; i++) {
            if (a[i] == 1) {
                cout << "1";
            }
            else {
                cout << "0";
            }
        }
        cout << endl;
        
        int key = _getch();
        if (key == 77) {
            int temp = a[9];
            for (i = 9; i > 0; i--) {
                a[i] = a[i - 1];
            }
            a[0] = temp;

        
        }
        else if (key == 75) {
            int first = a[0];
            for (i = 1; i < 10; i++) {
                a[i - 1] = a[i];
            }
            a[9] = first;
        }
        for (i = 0; i < 10; i++) {
            cout << a[i] << " ";
        }
    }
}

int main() {
    cla nm;
    nm.manage();
    return 0;
}*/

/*
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

class cla {
private:
    int a[10]; // 클래스 내의 배열
public:
    void manage();
};

void cla::manage() {
    int i;
    int a[10] = { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 }; 

    while (true) {
        system("cls");

        for (i = 0; i < 10; i++) {
            if (a[i] == 1) {
                cout << "1 ";
            }
            else {
                cout << "0";
            }
        }
        cout << endl;

        int key = _getch();
        if (key == 77) { 
            int last = a[9];
            for (i = 9; i > 0; i--) {
                a[i] = a[i - 1];
            }
            a[0] = last;
        }
        else if (key == 75) { 
            int first = a[0];
            for (i = 0; i < 9; i++) {
                a[i] = a[i + 1];
            }
            a[9] = first;
        }
    }
}

int main() {
    cla nm;
    nm.manage();
    return 0;
}*/

