#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int E, S, M;
	cin >> E >> S >> M;

	int sE = 1, sS = 1, sM = 1;
	int cnt = 1;

	if (E == 1 && S == 1 && M == 1) {
		cout << cnt;
		return 0;
	}

	while (1) {

		if (sE < 15) sE++;
		else sE = 1;

		if (sS < 28) sS++;
		else sS = 1;

		if (sM < 19) sM++;
		else sM = 1;

		cnt++; // 1³β Αυ°‘

		if (sE == E && sS == S && sM == M)
			break;
	}

	cout << cnt;

}