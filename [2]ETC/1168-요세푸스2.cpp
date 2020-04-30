#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

int main() {

    int N, K;

    int Idx;
    int tempN;

    vector<int> origin;

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        origin.push_back(i);
    }

    Idx = K - 1;
    tempN = N;

    cout << "<";

    for (int i = 0; i < N; i++) {
        cout << origin[Idx];

        if (i == N - 1) {
            cout << ">";
            break;
        }
        else
            cout << ", ";

        origin.erase(origin.begin() + Idx);
        // iterator를 사용해도 되나, 이렇게 써도 무방하다.
        // begin() 부터 Idx만큼 떨어진 곳을 지운다.

        Idx = Idx + (K - 1);

        // 만일 이 Idx가 origin 크기를 넘어버리면 안 되므로
        if (Idx >= origin.size())
            Idx = Idx % (origin.size());
    }

    return 0;
}