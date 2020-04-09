#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int dp[100001];

int main() {

	int N;
	scanf("%d", &N);
	
	dp[1] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j*j<=i ; j++) {

			dp[j] = 
		}
	}

}