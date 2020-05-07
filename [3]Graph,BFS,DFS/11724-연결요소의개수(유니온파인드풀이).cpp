#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int arr[1001][1001];
int N, M;
bool visit[1001];
bool conn = false;
int result;

void dfs(int V) {

	if (arr[V][V] == 1) {
		visit[V] = true;
		conn = true;
	}

	for (int i = 1; i <= N; i++) {
		if (arr[V][i] == 1 && visit[i] == false) {
			visit[V] = true; visit[i] = true;
			conn = true;
			dfs(i);
		}
	}
}

int main() {

	int V; // 탐색 시작 번호
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		dfs(i);
		if (conn) result += 1;
		conn = false;
	}

	for (int i = 1; i <= N; i++) {
		if (visit[i] == false) {
			result += 1;
		}
	}

	printf("%d", result);
	return 0;
}