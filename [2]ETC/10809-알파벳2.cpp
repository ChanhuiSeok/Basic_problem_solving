#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;
int exist[26];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;

	cin >> s;

	for (int i = 0; i < 26; i++) {
		exist[i] = -1; // -1로 초기화
	}

	for (int i = 0; i < s.length(); i++) {
		if (exist[s[i] - 97] == -1) {
			exist[s[i] - 97] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << exist[i] << " ";
	}

	return 0;
}