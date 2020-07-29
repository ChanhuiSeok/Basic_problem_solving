#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
typedef long long ll;

using namespace std;

ll arr[100001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	ll N, M; // N은 레슨의 수, M은 블루레이의 갯수
	cin >> N >> M;

	ll sum = 0, low = -1;

	for(int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
		//low = max(low, arr[i]);
	}

	ll high = sum;
	ll answer = 0;

	low = 0;

	while (low <= high) {
		ll cnt = 0;
		ll tempSum = 0;
		ll mid = (low + high) / 2;

		for (int i = 0; i < N; i++) {
			if (tempSum + arr[i] > mid) {
				tempSum = 0;
				cnt += 1; // 블루레이 갯수 1 증가
			}
			tempSum += arr[i];
		}
		if (tempSum != 0) cnt += 1;
		// 새로 블루레이 갯수를 미처 1 증가시키지 못했을 경우

		// 갯수가 M 이하일 때는, high 값을 줄여본다.
		if (cnt <= M) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	cout << low;	
	return 0;
}