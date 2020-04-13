#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>


int dp[201][201];

int main() {

	int N, K;

	scanf("%d %d", &N, &K);

	//1번더해 N이 되는 경우의 수는 1이다.
	for (int i = 0; i <= N; i++) {
		dp[1][i] = 1;
	}

	for (int k = 2; k <= K; k++) {
		for (int n = 0; n <= N; n++) {
			for (int i = 0; i <= n; i++) {
				dp[k][n] = (dp[k][n] + dp[k - 1][i]) % 1000000000;
			}
		}
	}

	printf("%d", dp[K][N]);

}

