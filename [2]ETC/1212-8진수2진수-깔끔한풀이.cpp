#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
string map[8] = { "000","001","010","011","100","101","110","111" };

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int idx = 0;

    string s;
    string answer = "";
    cin >> s;

    if (s == "0")
        answer = "0";

    else {
        for (int i = 0; i < s.size(); i++) {
            answer += map[s[i] - '0'];
        }
        // 처음으로 1이 나타나는 곳을 찾기
        while (answer[idx] != '1') {
            idx++;
        }
        answer = answer.substr(idx);
    }

    return 0;
}