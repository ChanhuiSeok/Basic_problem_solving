#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000001
#include <iostream>
#include <cstdio>

using namespace std;

int dp[301] = { 0, };
int stair[301];
int visit[301];

int MAX(int a, int b) {
	if (a >= b)
		return a;
	else
		return b;
}

int func(int x) {

	if (dp[x] != 0) {
		return dp[x];
	}

	dp[x] = MAX(func(x - 1) + stair[x], func(x - 2) + stair[x]);

}

int main() {

	int N, sum = 0;
	scanf("%d", &N);


	for (int i = 0; i < N; i++) {
		scanf("%d", &stair[i+1]);
		visit[i] = false;
	}

	dp[0] = 0;
	dp[1] = stair[1];

	// ����� �� ���� �� ��� Ȥ�� �� ��ܾ� ������ ����
	// ���� �� ����� ���� �� ����
	// �ݵ�� ���� ����� ��ƾ� ��

	func(N);


}