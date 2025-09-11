// 첫 숫자가 양의 실수를 받고 소수점이하가 있으면 소수점 이하를 받고 없으면 정수로 출력
// 연속적으로 더하는데 처음 수에 실수가 있으면 실수값으로 나오게 하고 없으면 정수로 출력하는데 이걸 템플릿으로 만들기


#include<iostream>
using namespace std;

template<typename T>
T sum(T num) {
    T answer = num;
    T n;
    char ch = ' ';
    while (ch != '=') {
        cin >> ch;
        if (ch != '=')
            cin >> n;
        answer += n;
    }
    return answer;
}
int main() {
    double a, b, c, result;
    cin >> a;
    result = sum(a);
    b = (int)result;
    c = result - b;
    if (c > 0) cout << c << endl;
    else cout << b << endl;
    return 0;
}