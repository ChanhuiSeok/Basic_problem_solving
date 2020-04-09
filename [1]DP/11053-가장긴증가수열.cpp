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
	

	/* ������ �Ʒ�ó�� �Ųٷ� ���� Ʋ�ȴٰ� ���´�. �����غ� ����*/
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

		// �� �κп��� �ִ� �񱳸� i=0���Ͱ� �ƴ� i=1���� �ϰ� �Ǿ�
		// Ʋ�ȴٰ� ������ �� �ϴ�. �ٱ����� ���� 0���� ��� �˻��ϸ�,
		// �� �Ʒ� �ڵ嵵 �¾ҽ��ϴٰ� ���.
		if (maxDP < dp[i]) {
			maxDP = dp[i];
		}
	}
	*/

	printf("%d", maxDP);

}