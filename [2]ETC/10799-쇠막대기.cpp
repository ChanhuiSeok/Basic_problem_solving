#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	stack<char> stk;
	int slice = 0;

	cin >> s;

	for (int i = 0; i < s.length(); i++) {

		if (s[i] == '(') {
			stk.push('(');
		}
		else if (!stk.empty() && s[i] == ')') {
			stk.pop();

			// �ٷ� ������ ( ������ () �� �ǹǷ� ��������
			if (s[i - 1] == '(')
				slice = slice + stk.size();
			// �ƴϸ� ������ �� ��
			else
				slice = slice + 1;
		}

	}

	printf("%d", slice);
	
}