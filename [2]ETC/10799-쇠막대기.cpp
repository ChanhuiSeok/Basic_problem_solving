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

			// 바로 직전이 ( 였으면 () 가 되므로 레이저임
			if (s[i - 1] == '(')
				slice = slice + stk.size();
			// 아니면 파이프 맨 끝
			else
				slice = slice + 1;
		}

	}

	printf("%d", slice);
	
}