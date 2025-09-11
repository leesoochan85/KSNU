#include <iostream>
#include <string>
using namespace std;

// 함수 정의
string GetLastString(string names[], int size) {
    string maxStr = names[0]; // 첫 번째 값을 기준으로 시작
    for (int i = 1; i < size; i++) {
        if (names[i] > maxStr) { // 사전식 비교
            maxStr = names[i];
        }
    }
    return maxStr;
}

int main() {
    string names[5];
    for (int i = 0; i < 5; i++) {
        cout << "이름 >> ";
        getline(cin, names[i], '\n');
    }

    // 함수 호출
    string res = GetLastString(names, 5);
    cout << "사전에서 가장 뒤에 나오는 문자열은 " << res << endl;

    return 0;
}
