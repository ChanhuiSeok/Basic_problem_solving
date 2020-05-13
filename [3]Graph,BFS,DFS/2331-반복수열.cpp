#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map <int, int> maps;

int cal(string s, int P) {

    int len = s.size();
    int result = 0;

    for (int i = 0; i < len; i++) {
        int num = s[i]-'0';
        int mul = s[i]-'0';
        for (int k = 0; k < P - 1; k++)
            num = num * mul;
        result += num;
    }
    return result;
}

int main() {

    string A;
    int P, result;
    int cnt = 0;

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> P;

    // 자릿수의 숫자를 P번 곱한 수로 계산하여 map에 계속 넣어준다.
    maps[stoi(A)]++;
    string from = A;
    while (1) {
        result = cal(from, P);
        maps[result]++;
        from = to_string(result);

        if (maps[result] >= 3) break;
    }

    // 1인 값만 고르기
    map<int, int>::iterator iter;
    for (iter = maps.begin(); iter != maps.end(); iter++) {
        if (iter->second == 1)
            cnt++;
    }

    printf("%d", cnt);

    return 0;
}