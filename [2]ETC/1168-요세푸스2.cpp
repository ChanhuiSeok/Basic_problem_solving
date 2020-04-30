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
        // iterator�� ����ص� �ǳ�, �̷��� �ᵵ �����ϴ�.
        // begin() ���� Idx��ŭ ������ ���� �����.

        Idx = Idx + (K - 1);

        // ���� �� Idx�� origin ũ�⸦ �Ѿ������ �� �ǹǷ�
        if (Idx >= origin.size())
            Idx = Idx % (origin.size());
    }

    return 0;
}