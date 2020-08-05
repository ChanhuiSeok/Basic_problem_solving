#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>

#define top 1
#define bottom 6

typedef long long ll;
using namespace std;

int profit[16][2];
int cache[16];
int N;

int find_max(int l, int r) {
	int max = 0;
	if (l > N) return 0;

	for (int k = l; k <= r; k++) {
		if (max <= cache[k]) {
			max = cache[k];
		}
	}
	return max;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	int T, P;
	int maxValue = -1;

	for (int i = 1; i <= N; i++) {
		cin >> T >> P;
		profit[i][0] = T;
		profit[i][1] = P;
	}

	// 일마다의 최대 profit값을 저장해 둔다.
	for (int i = N; i >= 1; i--) {
		
		if (i + profit[i][0] <= N + 1) 
			cache[i] = profit[i][1];
		
		int addDay = profit[i][0];
		int addValue = find_max(i + addDay, N);
		cache[i] += addValue;
	}

	sort(cache, cache + (N+1));

	cout << cache[N];
	
	return 0;
}