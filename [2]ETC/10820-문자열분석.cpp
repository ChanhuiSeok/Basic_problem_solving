#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;
int arr[26];
int exist[26];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;

	// 공백을 포함한 입력 한 줄을 통째로 받는 방법
	// 문자를 입력받지 않을 때까지 계속 입력받는다.
	while (getline(cin, s)) {
		int so = 0, dae = 0, num = 0, blk = 0;
		
		for (int i = 0; i < s.length(); i++) {

			if (s[i] >= 'A' && s[i] <= 'Z') {
				dae++;
			}
			else if (s[i] >= 'a' && s[i] <= 'z') {
				so++;
			}
			else if (s[i] == ' ') {
				blk++;
			}
			else {
				num++;
			}
		}

		cout << so << " " << dae << " " << num << " " << blk << '\n';
		so = 0, dae = 0, num = 0, blk = 0;
	}


	return 0;
}