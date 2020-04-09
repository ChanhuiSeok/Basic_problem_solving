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
	scanf("%d", &N);

	vector<int> v;

	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		v.push_back(input);
	}

	for (int i = 0; i < N; i++) {
		
		for (int j = 0; j < i; j++) {

			if (v[j] > v[i]) {

			}
		}

	}

	printf("%d", maxV);

}