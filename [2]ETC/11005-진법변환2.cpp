#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<char> remVal;
    vector<char>::iterator iter;
    int N, B;
    int remain = 0;

    cin >> N >> B;

    while (1) {       
        if ((N % B) >= 10) {
            remVal.push_back((N % B) + 55);
        }
        else {
            remVal.push_back((N % B) + 48);
        }
        N = N / B;  
        if (N == 0) {
            break;
        }
    }

    // ���͸� �������� ������ ���
    // algorithm ������� reverse �Լ��� ���
    reverse(remVal.begin(), remVal.end());

    // �ƴϸ�, reverse_iterator�� ����ϴ� ����� ����.

    for (int i = 0; i < remVal.size(); i++) {
        cout << remVal[i];
    }
    

    return 0;
}