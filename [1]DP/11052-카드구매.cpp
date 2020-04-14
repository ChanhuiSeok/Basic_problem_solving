#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10001];
int dp[10001];

int main() {

	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	// arr[1]�� ī�� 1���� ���Ե� ī������ ����
	// arr[2]�� ī�� 2���� ���Ե� ī������ ����
	// ... �̴�.
	// dp[1] = 1�� ���� �� ����
	dp[1] = arr[1];

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], arr[j] + dp[i-j]);
		}
	}

	printf("%d",dp[N]);

}

