#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321

using namespace std;
vector<pair<int, int>> input;

int adj[501][501];
int dist[501][501];
int in[501];
int out[501];
int result[501];

int main() {

	int N, M;
	int a, b;
	int resultCnt = 0;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		input.push_back({ a,b }); // a < b 라는 의미
	}

	for (int i = 0; i < input.size(); i++) {
		int from = input[i].first;
		int to = input[i].second;
		adj[from][to] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) dist[i][j] = 0;
			else if (adj[i][j]) dist[i][j] = adj[i][j];
			else dist[i][j] = INF;
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	// 특정 노드에서 시작하여 갈 수 있는 개수 정리
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] != 0 && dist[i][j] != INF) {
				out[i] += 1;
			}
		}
	}

	// 특정 노드까지 올 수 있는 개수 정리
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] != 0 && dist[i][j] != INF) {
				in[j] += 1;
			}
		}
	}

	for (int i = 1; i <= N; i++) 
		result[i] = in[i] + out[i];
	
	for (int i = 1; i <= N; i++) {
		if (result[i] == N - 1) {
			resultCnt += 1;
		}
	}

	printf("%d", resultCnt);

	return 0;

}