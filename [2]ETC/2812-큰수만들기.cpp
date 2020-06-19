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

		// 덱의 맨 마지막 요소가 현재 들어올 data보다 작을 때까지 계속 pop_back 하기
		// 단, K개만 지워야 하므로 그것도 고려해야 한다.
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