#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>

typedef unsigned long long ll;

using namespace std;

ll arr[1000001];
queue<ll> q;

int main() {

	int N;
	cin >> N;
	
	for (ll i = 0; i <= 9; i++) {
		q.push(i);
	}

	int idx = 0;

	while (!q.empty()) {
		ll num = q.front();
		arr[idx++] = num;
		q.pop();

		if (idx > 1023) break;

		for (ll j = 0; j <= 9; j++) {
			if (num % 10 > j) { // 큐에서 꺼낸 숫자의 일의자리 숫자가 j보다 크면
				ll temp = num * 10 + j; // 그 숫자에서 감소하는 수를 만들어 낸다.
				q.push(temp);
			}
		}
	}

	if (N > 1022) cout << -1;
	else cout << arr[N];

	return 0;
}
