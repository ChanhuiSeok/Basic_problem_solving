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

	ll N, M; // N�� ������ ��, M�� ��緹���� ����
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
				cnt += 1; // ��緹�� ���� 1 ����
			}
			tempSum += arr[i];
		}
		if (tempSum != 0) cnt += 1;
		// ���� ��緹�� ������ ��ó 1 ������Ű�� ������ ���

		// ������ M ������ ����, high ���� �ٿ�����.
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