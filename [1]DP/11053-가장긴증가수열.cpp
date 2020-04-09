#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int dp[1001];

int main() {

	int N, input;
	int sum = 0;
	int max = 0;
	int maxDP = -100;
	scanf("%d", &N);

	vector<int> v;

	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		v.push_back(input);
	}

	
	for (int i = 0; i < N; i++) {
		max = 0;

		for (int j = 0; j < i; j++) {
			if (v[i] > v[j] && max < dp[j]) {
				max = dp[j];
			}
		}
		dp[i] = max + 1;

		if (maxDP <= dp[i]) {
			maxDP = dp[i];
		}
	}
	

	/* 순서가 아래처럼 거꾸로 가니 틀렸다고 나온다. 생각해볼 문제*/
	/*
	dp[0] = 1;
	for (int i = 1; i < N; i++) {		
		max = 0;

		for (int j = i-1; j >= 0; j--) {
			if (v[i] > v[j] && max < dp[j]) {
					max = dp[j];
			}
		}
		dp[i] = max + 1;

		// 이 부분에서 최댓값 비교를 i=0부터가 아닌 i=1부터 하게 되어
		// 틀렸다고 나오는 듯 하다. 바깥으로 빼서 0부터 모두 검사하면,
		// 이 아래 코드도 맞았습니다가 뜬다.
		if (maxDP < dp[i]) {
			maxDP = dp[i];
		}
	}
	*/

	printf("%d", maxDP);

}