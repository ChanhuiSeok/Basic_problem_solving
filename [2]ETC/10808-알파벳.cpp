#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;
int arr[29];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		arr[s[i] - 97]++;
	}

	for (int i = 0; i<26; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}