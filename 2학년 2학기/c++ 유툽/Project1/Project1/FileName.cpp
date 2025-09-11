//정수배열 크기 5
//10 미만의 난수 
// 인덱스 순서에 12345 차례대로 넣기 였지만 추가를 한다면 12345가 아니고 54321로 삽입 
//
// 2번
// 12345를 아무렇게나 넣어도 되는데 중복이 없이 12345를 넣어라

#include<iostream>
using namespace std;

void rand_num(int a[], int size) {
   srand(time(NULL));
   int i,tmp,j=0;
   for (i = 0; i < size; i++) {
       tmp = rand() % 10 + 1;
       while (a[i] > 6){
   while (a[i] != a[j]) {
              if (j < 5) {
                  j++;
              }
          }
         tmp = rand() % 10;
         a[i] = tmp;
         }
   }   
}

int main() {
   int size = 5;
   int arr[5];
   rand_num(arr, size);

   for (int i = 0; i <size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
   return 0;
}
/*
#include <iostream>
#include <cstdlib> // for rand and srand
#include <ctime>   // for time

using namespace std;

int main() {
    int a[5];
    int tmp, cn = 0;
    srand(time(NULL));

    while (cn < 5) {
        int num1 = rand() % 5 + 1;
        tmp = 0;

        for (int i = 0; i < 5; i++) {
            if (a[i] == num1) ++tmp;
        }

        if (tmp == 0) {
            a[cn] = num1;
            ++cn;
        }
    }


    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
*/