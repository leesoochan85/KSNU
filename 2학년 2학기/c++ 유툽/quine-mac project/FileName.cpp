#include<iostream>
#include<vector>
#include<conio.h>
#include<string>
using namespace std;

class quine {
private:
    int binary[16][4] = { 0 }, current_num[16], number[16],
        reminder, share, count, zero_num, one_num,
        zero = 0, one = 0, two = 0, three = 0, four = 0, start = 0, start1 = 0, start2 = 0, start3 = 0,

        merge1_row, merge2_row, merge3_row, merge4_row,
        merge2_2row, merge2_3row, merge2_4row,
        merge3_3row, merge3_4row;

    vector<int> zero_idx, one_idx, two_idx, three_idx, four_idx;
    vector<vector<string>> compact_merge1;
    vector<vector<string>> compact_merge2;
    vector<vector<string>> compact_merge3;
    vector<vector<string>> compact_merge4;

    vector<vector<string>> compact_merge1_2;
    vector<vector<string>> compact_merge2_2;
    vector<vector<string>> compact_merge3_2;
    vector<vector<string>> compact_merge4_2;
   
    vector<vector<int>> merge1_component[4][2];
    vector<vector<int>> merge1_component2[24][2];
    vector<vector<int>> merge1_component3[24][2];
    vector<vector<int>> merge1_component4[4][2];


public:
    quine();
    void num_to_binary(); // 10진수 2진수로 변경
    void choice_the_number(); // 15개 수 중 선택
    void merging(); // 파티션 5개에서 다른 부분이 한 개일 때
    void merging2(); // 파티션 4개
    void merging3();
    void merging4();
    ~quine();
};

quine::quine() {};
quine::~quine() {};

void quine::num_to_binary() {
    int i, k;
    for (i = 0; i < 16; i++) { // 2진수 만든 후 1의 갯수 세서 알맞은 변수 카운팅
        share = i;
        for (k = 0; k < 4; k++) {  // 10진수 2진수 만들기
            reminder = share % 2;
            share = share / 2;
            binary[i][3 - k] = reminder;
        }
        current_num[i] = i; // 0~15까지 순차적으로 배열
    }
}

void quine::choice_the_number() { // 0 or 1로 2진수 선택 
    int select[16],i,k;

    for (i = 0; i < 16; i++) {
        cin >> select[i];
        if (select[i] == 1) { // 1입력 된 것 확인 후 출력
            for (k = 0; k < 4; k++) {
                cout << binary[i][k] << " ";
                if (binary[i][k] == 1) count++;
            }
            cout << endl;
            one_num++;
        }
        else if (select[i] == 0) { // 0입력 
            zero_num++;
        }

        number[i] = count;  // 0~15까지 수에 1이 몇개인지 배열에 넣어 확인하기
        if (number[i] == 0) zero_idx.push_back(i), zero++;  //1의 갯수가 0개 인 것을 카운트 하기
        else if (number[i] == 1) one_idx.push_back(i), one++; // 1의 갯수가 1개 "
        else if (number[i] == 2) two_idx.push_back(i), two++; // 1의 갯수가 2개 "
        else if (number[i] == 3) three_idx.push_back(i), three++; // 1의 갯수가 3개 "
        else if (number[i] == 4) four_idx.push_back(i), four++; // 1의 갯수가 4개 "
        count = 0;
    }
    cout << "스페이스바 " << endl;
    if (_getch() == 32) merging();
}

void quine::merging() { // 0개와 1개, 1개와 2개, 2개와 3개, 3개와 4개의 합병
    compact_merge1.clear(), compact_merge2.clear(), compact_merge3.clear(), compact_merge4.clear();
    compact_merge1.resize(one_idx.size(), vector<string>(4, "0"));
    compact_merge2.resize(two_idx.size(), vector < string>(4, "0"));
    compact_merge3.resize(three_idx.size(), vector<string>(4, "0"));
    compact_merge4.resize(four_idx.size(), vector<string>(4, "0"));
    int i, q = 0, p;


    while (q < zero_idx.size()) {
        p = 0; start = 0;
        while (p < one_idx.size()) {
            if (binary[zero_idx.at(q)][0] != binary[one_idx.at(p)][0] && binary[zero_idx.at(q)][1] == binary[one_idx.at(p)][1] && binary[zero_idx.at(q)][2] == binary[one_idx.at(p)][2] && binary[zero_idx.at(q)][3] == binary[one_idx.at(p)][3]) {
                for (i = 0; i < 4; i++) {
                    if (i == 0) compact_merge1[p][i] = " - ";
                    else compact_merge1[p][i] = to_string(binary[one_idx.at(p)][i]);
                }
                cout << "(" << zero_idx.at(q) << ", " << one_idx.at(p) << ")";

                merge1_component[start][0].push_back({ zero_idx.at(q) }); // 0번째 부분에 zero_idx 저장
                merge1_component[start][1].push_back({ one_idx.at(p) });
                start++;
            }


            else if (binary[zero_idx.at(q)][0] == binary[one_idx.at(p)][0] && binary[zero_idx.at(q)][1] != binary[one_idx.at(p)][1] && binary[zero_idx.at(q)][2] == binary[one_idx.at(p)][2] && binary[zero_idx.at(q)][3] == binary[one_idx.at(p)][3]) {
                for (i = 0; i < 4; i++) {
                    if (i == 1) compact_merge1[p][i] = " - ";
                    else compact_merge1[p][i] = to_string(binary[one_idx.at(p)][i]);
                }
                cout << "(" << zero_idx.at(q) << ", " << one_idx.at(p) << ")";

                merge1_component2[start][0].push_back({ zero_idx.at(q) }); // 0번째 부분에 zero_idx 저장
                merge1_component2[start][1].push_back({ one_idx.at(p) });
                start++;
            }
            else if (binary[zero_idx.at(q)][0] == binary[one_idx.at(p)][0] && binary[zero_idx.at(q)][1] == binary[one_idx.at(p)][1] && binary[zero_idx.at(q)][2] != binary[one_idx.at(p)][2] && binary[zero_idx.at(q)][3] == binary[one_idx.at(p)][3]) {
                for (i = 0; i < 4; i++) {
                    if (i == 2) compact_merge1[p][i] = " - ";
                    else compact_merge1[p][i] = to_string(binary[one_idx.at(p)][i]);
                }
                cout << "(" << zero_idx.at(q) << ", " << one_idx.at(p) << ")";

                merge1_component3[start][0].push_back({ zero_idx.at(q) }); // 0번째 부분에 zero_idx 저장
                merge1_component3[start][1].push_back({ one_idx.at(p) });
                start++;
            }
            else if (binary[zero_idx.at(q)][0] == binary[one_idx.at(p)][0] && binary[zero_idx.at(q)][1] == binary[one_idx.at(p)][1] && binary[zero_idx.at(q)][2] == binary[one_idx.at(p)][2] && binary[zero_idx.at(q)][3] != binary[one_idx.at(p)][3]) {
                for (i = 0; i < 4; i++) {
                    if (i == 3) compact_merge1[p][i] = " - ";
                    else compact_merge1[p][i] = to_string(binary[one_idx.at(p)][i]);
                }
                cout << "(" << zero_idx.at(q) << ", " << one_idx.at(p) << ")";

                merge1_component4[start][0].push_back({ zero_idx.at(q) }); // 0번째 부분에 zero_idx 저장
                merge1_component4[start][1].push_back({ one_idx.at(p) });
                start++;
            }
            for (i = 0; i < 4; i++) {
                cout << compact_merge1[p][i] << " ";
            }
            cout << endl;
            p++;
        }
        q++;
    }
    merge1_row = sizeof(compact_merge1) / sizeof(compact_merge1[0]);


    while (q < one_idx.size()) {
        p = 0; start = 0;
        while (p < two_idx.size()) {
            if (binary[one_idx.at(q)][0] != binary[two_idx.at(p)][0] && binary[one_idx.at(q)][1] == binary[two_idx.at(p)][1] && binary[one_idx.at(q)][2] == binary[two_idx.at(p)][2] && binary[one_idx.at(q)][3] == binary[two_idx.at(p)][3]) {
                for (i = 0; i < 4; i++) {
                    if (i == 0) compact_merge2[p][i] = " - ";
                    else compact_merge2[p][i] = to_string(binary[two_idx.at(q)][i]);
                }        
                cout << "(" << one_idx.at(q) << ", " << two_idx.at(p) << ")";
                merge1_component2[start][0].push_back({ one_idx.at(q) }); // 0번째 부분에 one_idx
                merge1_component2[start][1].push_back({ two_idx.at(p) });
                start++;
            }
            else if (binary[one_idx.at(q)][0] == binary[two_idx.at(p)][0] && binary[one_idx.at(q)][1] != binary[two_idx.at(p)][1] && binary[one_idx.at(q)][2] == binary[two_idx.at(p)][2] && binary[one_idx.at(q)][3] == binary[two_idx.at(p)][3]) {
                for (i = 0; i < 4; i++) {
                    if (i == 1) compact_merge2[p][i] = " - ";
                    else compact_merge2[p][i] = to_string(binary[two_idx.at(q)][i]);
                }
                cout << "(" << one_idx.at(q) << ", " << two_idx.at(p) << ")";
                merge1_component2[start][0].push_back({ one_idx.at(q) }); // 0번째 부분에 one_idx
                merge1_component2[start][1].push_back({ two_idx.at(p) });
                start++;
            }
            else if (binary[one_idx.at(q)][0] == binary[two_idx.at(p)][0] && binary[one_idx.at(q)][1] == binary[two_idx.at(p)][1] && binary[one_idx.at(q)][2] != binary[two_idx.at(p)][2] && binary[one_idx.at(q)][3] == binary[two_idx.at(p)][3]) {
                for (i = 0; i < 4; i++) {
                    if (i == 2) compact_merge2[p][i] = " - ";
                    else compact_merge2[p][i] = to_string(binary[two_idx.at(q)][i]);
                }
                cout << "(" << one_idx.at(q) << ", " << two_idx.at(p) << ")";
                merge1_component2[start][0].push_back({ one_idx.at(q) }); // 0번째 부분에 one_idx
                merge1_component2[start][1].push_back({ two_idx.at(p) });
                start++;
            }
            else if (binary[one_idx.at(q)][0] == binary[two_idx.at(p)][0] && binary[one_idx.at(q)][1] == binary[two_idx.at(p)][1] && binary[one_idx.at(q)][2] == binary[two_idx.at(p)][2] && binary[one_idx.at(q)][3] != binary[two_idx.at(p)][3]) {
                for (i = 0; i < 4; i++) {
                    if (i == 3) compact_merge2[p][i] = " - ";
                    else compact_merge2[p][i] = to_string(binary[two_idx.at(q)][i]);
                }
                cout << "(" << one_idx.at(q) << ", " << two_idx.at(p) << ")"; 
                merge1_component2[start][0].push_back({ one_idx.at(q) }); // 0번째 부분에 one_idx
                merge1_component2[start][1].push_back({ two_idx.at(p) });
                start++;
            }
            for (i = 0; i < 4; i++) {
                cout << compact_merge2[p][i] << " ";
            }
            cout << endl;
            p++;
        }q++;
    }
    merge2_row = sizeof(compact_merge2) / sizeof(compact_merge2[0]);


    while (q < two_idx.size()) {
        p = 0; start =0;
        while (p < three_idx.size()) {
            if (binary[zero_idx.at(q)][0] != binary[two_idx.at(p)][0] && binary[three_idx.at(q)][1] == binary[two_idx.at(p)][1] && binary[three_idx.at(q)][2] == binary[two_idx.at(p)][2] && binary[three_idx.at(q)][3] == binary[one_idx.at(p)][3]) {
                for (i = 0; i < 4; i++) {
                    if (i == 0) compact_merge3[p][0] = "-";
                    else compact_merge3[p][i] = binary[three_idx.at(p)][i];
                }
                cout << "(" << two_idx.at(q) << ", " << three_idx.at(p) << ")";
                merge1_component3[start][0].push_back({ two_idx.at(q) }); // 0번째 부분에 one_idx
                merge1_component3[start][1].push_back({ three_idx.at(p) });
                start++;
            }
            else if (binary[zero_idx.at(q)][0] == binary[two_idx.at(p)][0] && binary[three_idx.at(q)][1] != binary[two_idx.at(p)][1] && binary[three_idx.at(q)][2] == binary[two_idx.at(p)][2] && binary[three_idx.at(q)][3] == binary[one_idx.at(p)][3]) {
                for (i = 0; i < 4; i++) {
                    if (i == 1) compact_merge3[p][0] = "-";
                    else compact_merge3[p][i] = binary[three_idx.at(p)][i];
                }
                cout << "(" << two_idx.at(q) << ", " << three_idx.at(p) << ")"; 
                merge1_component3[start][0].push_back({ two_idx.at(q) }); // 0번째 부분에 one_idx
                merge1_component3[start][1].push_back({ three_idx.at(p) });
                start++;
            }
            else if (binary[zero_idx.at(q)][0] == binary[two_idx.at(p)][0] && binary[three_idx.at(q)][1] == binary[two_idx.at(p)][1] && binary[three_idx.at(q)][2] != binary[two_idx.at(p)][2] && binary[three_idx.at(q)][3] == binary[one_idx.at(p)][3]) {
                for (i = 0; i < 4; i++) {
                    if (i == 2) compact_merge3[p][0] = "-";
                    else compact_merge3[p][i] = binary[three_idx.at(p)][i];
                }
                cout << "(" << two_idx.at(q) << ", " << three_idx.at(p) << ")"; 
                merge1_component3[start][0].push_back({ two_idx.at(q) }); // 0번째 부분에 one_idx
                merge1_component3[start][1].push_back({ three_idx.at(p) });
                start++;
            }
            else if (binary[zero_idx.at(q)][0] == binary[two_idx.at(p)][0] && binary[three_idx.at(q)][1] == binary[two_idx.at(p)][1] && binary[three_idx.at(q)][2] == binary[two_idx.at(p)][2] && binary[three_idx.at(q)][3] != binary[one_idx.at(p)][3]) {
                for (i = 0; i < 4; i++) {
                    if (i == 3) compact_merge3[p][0] = "-";
                    else compact_merge3[p][i] = binary[three_idx.at(p)][i];
                }
                cout << "(" << two_idx.at(q) << ", " << three_idx.at(p) << ")"; 
                merge1_component3[start][0].push_back({ two_idx.at(q) }); // 0번째 부분에 one_idx
                merge1_component3[start][1].push_back({ three_idx.at(p) });
                start++;
            }
            for (i = 0; i < 4; i++) {
                cout << compact_merge3[p][i];
            } cout << endl;
            p++;
        }q++;
    }
    merge3_row = sizeof(compact_merge3) / sizeof(compact_merge3[0]);


    while (q < three_idx.size()) {
        p = 0; start = 0;
        while (p < four_idx.size()) {
            if (binary[three_idx.at(q)][0] != binary[four_idx.at(p)][0] && binary[three_idx.at(q)][1] == binary[four_idx.at(p)][1] && binary[three_idx.at(q)][2] == binary[four_idx.at(p)][2] && binary[three_idx.at(q)][3] == binary[four_idx.at(p)][3]) {
                for (i = 0; i < 4; i++) {
                    if (i == 0) compact_merge4[p][0] = "-";
                    else compact_merge4[p][i] = binary[four_idx.at(p)][i];
                }
                cout << "(" << three_idx.at(q) << ", " << four_idx.at(p) << ")";
                merge1_component4[start][0].push_back({ three_idx.at(q) }); // 0번째 부분에 one_idx
                merge1_component4[start][1].push_back({ four_idx.at(p) });
                start++;
            }
            else if (binary[three_idx.at(q)][0] == binary[four_idx.at(p)][0] && binary[three_idx.at(q)][1] != binary[four_idx.at(p)][1] && binary[three_idx.at(q)][2] == binary[four_idx.at(p)][2] && binary[three_idx.at(q)][3] == binary[four_idx.at(p)][3]) {
                for (i = 0; i < 4; i++) {
                    if (i == 0) compact_merge4[p][0] = "-";
                    else compact_merge4[p][i] = binary[four_idx.at(p)][i];
                }
                cout << "(" << three_idx.at(q) << ", " << four_idx.at(p) << ")";
                merge1_component4[start][0].push_back({ three_idx.at(q) }); // 0번째 부분에 one_idx
                merge1_component4[start][1].push_back({ four_idx.at(p) });
                start++;
            }
            else if (binary[three_idx.at(q)][0] == binary[four_idx.at(p)][0] && binary[three_idx.at(q)][1] == binary[four_idx.at(p)][1] && binary[three_idx.at(q)][2] != binary[four_idx.at(p)][2] && binary[three_idx.at(q)][3] == binary[four_idx.at(p)][3]) {
                for (i = 0; i < 4; i++) {
                    if (i == 0) compact_merge4[p][0] = "-";
                    else compact_merge4[p][i] = binary[four_idx.at(p)][i];
                }
                cout << "(" << three_idx.at(q) << ", " << four_idx.at(p) << ")";
                merge1_component4[start][0].push_back({ three_idx.at(q) }); // 0번째 부분에 one_idx
                merge1_component4[start][1].push_back({ four_idx.at(p) });
                start++;
            }
            else if (binary[three_idx.at(q)][0] == binary[four_idx.at(p)][0] && binary[three_idx.at(q)][1] == binary[four_idx.at(p)][1] && binary[three_idx.at(q)][2] == binary[four_idx.at(p)][2] && binary[three_idx.at(q)][3] != binary[four_idx.at(p)][3]) {
                for (i = 0; i < 4; i++) {
                    if (i == 0) compact_merge4[p][0] = "-";
                    else compact_merge4[p][i] = binary[four_idx.at(p)][i];
                }
                cout << "(" << three_idx.at(q) << ", " << four_idx.at(p) << ")";
                merge1_component4[start][0].push_back({ three_idx.at(q) }); // 0번째 부분에 one_idx
                merge1_component4[start][1].push_back({ four_idx.at(p) });
                start++;
            }
            for (i = 0; i < 4; i++) {
                cout << compact_merge4[p][i];
            }cout << endl;
            p++;
        }q++;
    }
    merge4_row = sizeof(compact_merge4) / sizeof(compact_merge4[0]);
    
    cout << "스페이스바";
    if(_getch()==32) merging2();
}

void quine::merging2() {
    compact_merge1_2.clear(), compact_merge2_2.clear(), compact_merge3_2.clear(), compact_merge4_2.clear();
    compact_merge1_2.resize(merge2_row, vector<string>(4, "0"));
    compact_merge2_2.resize(merge3_row, vector < string>(4, "0"));
    compact_merge3_2.resize(merge4_row, vector<string>(4, "0"));
    compact_merge4_2.resize(merge4_row, vector<string>(4, "0"));

    int i = 0, k, p;
    while (i < merge1_row) {
        k = 0;
        while (k < merge2_row) {
            if (compact_merge1[i][0] != compact_merge2[k][0] && compact_merge1[i][1] == compact_merge2[k][1] && compact_merge1[i][2] == compact_merge2[k][2] && compact_merge1[i][3] == compact_merge2[k][3]) {
                for (p = 0; p < 4; p++) {
                    if (p == 0) compact_merge2_2[k][p] = " - ";
                    else compact_merge2_2[k][p] = compact_merge2[k][p];
                }
  
              // cout << "(" << merge1_component[i][1] << ", " << merge1_component[i][2] << ", " << merge1_component2[k][1] << "," << merge1_component2[k][2] << ")";
            }
            else if (compact_merge1[i][0] == compact_merge2[k][0] && compact_merge1[i][1] != compact_merge2[k][1] && compact_merge1[i][2] == compact_merge2[k][2] && compact_merge1[i][3] == compact_merge2[k][3]) {
                for (p = 0; p < 4; p++) {
                    if (p == 1) compact_merge2_2[k][p] = " - ";
                    else compact_merge2_2[k][p] = compact_merge2[k][p];
                }
               // cout << "(" << merge1_component[i][1] << ", " << merge1_component[i][2] << ", " << merge1_component2[k][1] << "," << merge1_component2[k][2] << ")";
            }
            else if (compact_merge1[i][0] == compact_merge2[k][0] && compact_merge1[i][1] == compact_merge2[k][1] && compact_merge1[i][2] != compact_merge2[k][2] && compact_merge1[i][3] == compact_merge2[k][3]) {
                for (p = 0; p < 4; p++) {
                    if (p == 2) compact_merge2_2[k][p] = " - ";
                    else compact_merge2_2[k][p] = compact_merge2[k][p];
                }
               // cout << "(" << merge1_component[i][1] << ", " << merge1_component[i][2] << ", " << merge1_component2[k][1] << "," << merge1_component2[k][2] << ")";
            }
            else if (compact_merge1[i][0] == compact_merge2[k][0] && compact_merge1[i][1] == compact_merge2[k][1] && compact_merge1[i][2] == compact_merge2[k][2] && compact_merge1[i][3] != compact_merge2[k][3]) {
                for (p = 0; p < 4; p++) {
                    if (p == 3) compact_merge2_2[k][p] = " - ";
                    else compact_merge2_2[k][p] = compact_merge2[k][p];
                }
               // cout << "(" << merge1_component[i][1] << ", " << merge1_component[i][2] << ", " << merge1_component2[k][1] << "," << merge1_component2[k][2] << ")";
            }
            for (p = 0; p < 4; p++) {
                cout << compact_merge2_2[k][p];
            }cout << endl;
            k++;
        }i++;
    }
    merge2_2row = sizeof(compact_merge2) / sizeof(compact_merge2[0]);

    while (i < merge2_row) {
        k = 0;
        while (k < merge3_row) {
            if (compact_merge2[i][0] != compact_merge3[k][0] && compact_merge2[i][1] == compact_merge3[k][1] && compact_merge2[i][2] == compact_merge3[k][2] && compact_merge2[i][3] == compact_merge3[k][3]) {
                for (p = 0; p < 4; p++) {
                    if (p == 0) compact_merge3_2[k][p] = " - ";
                    else compact_merge3_2[k][p] = compact_merge3[k][p];
                }
               // cout << "(" << merge1_component2[i][1] << ", " << merge1_component2[i][2] << ", " << merge1_component3[k][1] << "," << merge1_component3[k][2] << ")";
            }
            else if (compact_merge2[i][0] == compact_merge3[k][0] && compact_merge2[i][1] != compact_merge3[k][1] && compact_merge2[i][2] == compact_merge3[k][2] && compact_merge2[i][3] == compact_merge3[k][3]) {
                for (p = 0; p < 4; p++) {
                    if (p == 1) compact_merge3_2[k][p] = " - ";
                    else compact_merge3_2[k][p] = compact_merge3[k][p];
                }
               // cout << "(" << merge1_component2[i][1] << ", " << merge1_component2[i][2] << ", " << merge1_component3[k][1] << "," << merge1_component3[k][2] << ")";
            }

            else if (compact_merge2[i][0] == compact_merge3[k][0] && compact_merge2[i][1] == compact_merge3[k][1] && compact_merge2[i][2] != compact_merge3[k][2] && compact_merge2[i][3] == compact_merge3[k][3]) {
                for (p = 0; p < 4; p++) {
                    if (p == 2) compact_merge3_2[k][p] = " - ";
                    else compact_merge3_2[k][p] = compact_merge3[k][p];
                }
              //  cout << "(" << merge1_component2[i][1] << ", " << merge1_component2[i][2] << ", " << merge1_component3[k][1] << "," << merge1_component3[k][2] << ")";
            }

            else if (compact_merge2[i][0] == compact_merge3[k][0] && compact_merge2[i][1] == compact_merge3[k][1] && compact_merge2[i][2] == compact_merge3[k][2] && compact_merge2[i][3] != compact_merge3[k][3]) {
                for (p = 0; p < 4; p++) {
                    if (p == 3) compact_merge3_2[k][p] = " - ";
                    else compact_merge3_2[k][p] = compact_merge3[k][p];
                }
               // cout << "(" << merge1_component2[i][1] << ", " << merge1_component2[i][2] << ", " << merge1_component3[k][1] << "," << merge1_component3[k][2] << ")";
            }
            for (p = 0; p < 4; p++) {
                cout << compact_merge3_2[k][p];
            } cout << endl;
            k++;
        }i++;

    }
    merge2_3row = sizeof(compact_merge3) / sizeof(compact_merge3[0]);

    while (i < merge2_row) {
        k = 0;
        while (k < merge3_row) {
            if (compact_merge3[i][0] != compact_merge4[k][0] && compact_merge3[i][1] == compact_merge4[k][1] && compact_merge3[i][2] == compact_merge4[k][2] && compact_merge3[i][3] == compact_merge4[k][3]) {
                for (p = 0; p < 4; p++) {
                    if (p == 3) compact_merge4_2[k][p] = " - ";
                    else compact_merge4_2[k][p] = compact_merge4[k][p];
                }
                //cout << "(" << merge1_component3[i][1] << ", " << merge1_component3[i][2] << ", " << merge1_component4[k][1] << "," << merge1_component4[k][2] << ")";
            }
            else if (compact_merge3[i][0] == compact_merge4[k][0] && compact_merge3[i][1] != compact_merge4[k][1] && compact_merge3[i][2] == compact_merge4[k][2] && compact_merge3[i][3] == compact_merge4[k][3]) {
                for (p = 0; p < 4; p++) {
                    if (p == 3) compact_merge4_2[k][p] = " - ";
                    else compact_merge4_2[k][p] = compact_merge4[k][p];
                }
              // cout << "(" << merge1_component3[i][1] << ", " << merge1_component3[i][2] << ", " << merge1_component4[k][1] << "," << merge1_component4[k][2] << ")";
            }
            else if (compact_merge3[i][0] == compact_merge4[k][0] && compact_merge3[i][1] == compact_merge4[k][1] && compact_merge3[i][2] != compact_merge4[k][2] && compact_merge3[i][3] == compact_merge4[k][3]) {
                for (p = 0; p < 4; p++) {
                    if (p == 3) compact_merge4_2[k][p] = " - ";
                    else compact_merge4_2[k][p] = compact_merge4[k][p];
                }
                //cout << "(" << merge1_component3[i][1] << ", " << merge1_component3[i][2] << ", " << merge1_component4[k][1] << "," << merge1_component4[k][2] << ")";
            }
            else if (compact_merge3[i][0] == compact_merge4[k][0] && compact_merge3[i][1] == compact_merge4[k][1] && compact_merge3[i][2] == compact_merge4[k][2] && compact_merge3[i][3] != compact_merge4[k][3]) {
                for (p = 0; p < 4; p++) {
                    if (p == 3) compact_merge4_2[k][p] = " - ";
                    else compact_merge4_2[k][p] = compact_merge4[k][p];
                }
                //cout << "(" << merge1_component3[i][1] << ", " << merge1_component3[i][2] << ", " << merge1_component4[k][1] << "," << merge1_component4[k][2] << ")";
            }
            for (p = 0; p < 4; p++) {
                cout << compact_merge4_2[k][p];
            }cout << endl;
            k++;
        }i++;
    }
    merge2_4row = sizeof(compact_merge4) / sizeof(compact_merge4[0]);
}
// 
//void quine::merging3() {
//    int ky = _getch();
//  //  vector<vector<int>> compact_merge1(this->merge1_row, vector<int>(4));
//    vector<vector<int>> compact_merge2(this->merge2_2row, vector<int>(4));
//    vector<vector<int>> compact_merge3(this->merge2_3row, vector<int>(4));
//    vector<vector<int>> compact_merge4(this->merge2_4row, vector<int>(4));
//    if (ky == 32) {
//        for (i = 0; i < merge2_2row; i++) {
//            for (k = 0; k < merge2_3row; k++) {
//                if (compact_merge2[i][0] != compact_merge3[k][0] && compact_merge2[i][1] == compact_merge3[k][1] && compact_merge2[i][2] == compact_merge3[k][2] && compact_merge2[i][3] == compact_merge3[k][3]) {
//                    compact_merge3[k][0] = '-';
//                }
//                else if (compact_merge2[i][0] == compact_merge3[k][0] && compact_merge2[i][1] != compact_merge3[k][1] && compact_merge2[i][2] == compact_merge3[k][2] && compact_merge2[i][3] == compact_merge3[k][3]) {
//                    compact_merge3[k][1] = '-';
//                }
//                else if (compact_merge2[i][0] == compact_merge3[k][0] && compact_merge2[i][1] == compact_merge3[k][1] && compact_merge2[i][2] != compact_merge3[k][2] && compact_merge2[i][3] == compact_merge3[k][3]) {
//                    compact_merge3[k][2] = '-';
//                }
//                else if (compact_merge2[i][0] == compact_merge3[k][0] && compact_merge2[i][1] == compact_merge3[k][1] && compact_merge2[i][2] == compact_merge3[k][2] && compact_merge2[i][3] != compact_merge3[k][3]) {
//                    compact_merge3[k][3] = '-';
//                }
//                else;
//            }
//        }merge3_3row = sizeof(compact_merge3) / sizeof(compact_merge3[0]);
//
//        for (i = 0; i < merge2_3row; i++) {
//            for (k = 0; k < merge2_4row; k++) {
//                if (compact_merge3[i][0] != compact_merge4[k][0] && compact_merge3[i][1] == compact_merge4[k][1] && compact_merge3[i][2] == compact_merge4[k][2] && compact_merge3[i][3] == compact_merge4[k][3]) {
//                    compact_merge4[k][0] = '-';
//                }
//                else if (compact_merge3[i][0] == compact_merge4[k][0] && compact_merge3[i][1] != compact_merge4[k][1] && compact_merge3[i][2] == compact_merge4[k][2] && compact_merge3[i][3] == compact_merge4[k][3]) {
//                    compact_merge4[k][1] = '-';
//                }
//                else if (compact_merge3[i][0] == compact_merge4[k][0] && compact_merge3[i][1] == compact_merge4[k][1] && compact_merge3[i][2] != compact_merge4[k][2] && compact_merge3[i][3] == compact_merge4[k][3]) {
//                    compact_merge4[k][2] = '-';
//                }
//                else if (compact_merge3[i][0] == compact_merge4[k][0] && compact_merge3[i][1] == compact_merge4[k][1] && compact_merge3[i][2] == compact_merge4[k][2] && compact_merge3[i][3] != compact_merge4[k][3]) {
//                    compact_merge4[k][3] = '-';
//                }
//                else;
//            }
//        }merge3_4row = sizeof(compact_merge4) / sizeof(compact_merge4[0]);
//    }
//}
//void quine::merging4() {
//    int ky = _getch();
//    //  vector<vector<int>> compact_merge1(this->merge1_row, vector<int>(4));
//   // vector<vector<int>> compact_merge2(this->merge2_2row, vector<int>(4));
//    vector<vector<int>> compact_merge3(this->merge3_3row, vector<int>(4));
//    vector<vector<int>> compact_merge4(this->merge3_4row, vector<int>(4));
//    if (ky == 32) {
//        for (i = 0; i < merge3_3row; i++) {
//            for (k = 0; k < merge3_4row; k++) {
//                if (compact_merge3[i][0] != compact_merge4[k][0] && compact_merge3[i][1] == compact_merge4[k][1] && compact_merge3[i][2] == compact_merge4[k][2] && compact_merge3[i][3] == compact_merge4[k][3]) {
//                    compact_merge4[k][0] = '-';
//                }
//                else if (compact_merge3[i][0] == compact_merge4[k][0] && compact_merge3[i][1] != compact_merge4[k][1] && compact_merge3[i][2] == compact_merge4[k][2] && compact_merge3[i][3] == compact_merge4[k][3]) {
//                    compact_merge4[k][1] = '-';
//                }
//                else if (compact_merge3[i][0] == compact_merge4[k][0] && compact_merge3[i][1] == compact_merge4[k][1] && compact_merge3[i][2] != compact_merge4[k][2] && compact_merge3[i][3] == compact_merge4[k][3]) {
//                    compact_merge4[k][2] = '-';
//                }
//                else if (compact_merge3[i][0] == compact_merge4[k][0] && compact_merge3[i][1] == compact_merge4[k][1] && compact_merge3[i][2] == compact_merge4[k][2] && compact_merge3[i][3] != compact_merge4[k][3]) {
//                    compact_merge4[k][3] = '-';
//                }
//                else;
//            }
//        }
//    }
//}


int main() {
    quine nm;
   nm.num_to_binary();
   nm.choice_the_number();
   nm.merging();
  // nm.merging2();
  // nm.merging3();
  // nm.merging4();
    cout << " ";
   return 0;
}