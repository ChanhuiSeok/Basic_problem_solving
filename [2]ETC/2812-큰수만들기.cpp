#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>

using namespace std;

deque<int> stk;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	int tempK = 0;
	string input;
	cin >> N >> K;
	tempK = K;
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		int data = input[i] - '0';

		// ���� �� ������ ��Ұ� ���� ���� data���� ���� ������ ��� pop_back �ϱ�
		// ��, K���� ������ �ϹǷ� �װ͵� ����ؾ� �Ѵ�.
		while (K != 0 && !stk.empty() && stk.back() < data) {
			stk.pop_back();
			K -= 1;
		}

		stk.push_back(data);
	}

	for (int j = 0; j < N- tempK; j++) {
		cout << stk[j];
	}
	

	return 0;
}