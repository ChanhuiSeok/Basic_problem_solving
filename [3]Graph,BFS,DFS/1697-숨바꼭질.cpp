#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<int,int>> q;
bool visit[100001];
int N, K, result;

bool valid(int n) {
	if (n < 0 || n > 100000 || visit[n])
		return false;
	return true;
}

void bfs(int n) {

	while (!q.empty()) {

		// ť���� ���ϱ�
		int data = q.front().first;
		int depth = q.front().second;

		q.pop();
		if (data == K) {
			result = depth;
			break;
		}
		if (valid(data - 1)){ 
			visit[data - 1] = true;
			q.push({ data - 1, depth+1 });
		}
		if (valid(data + 1)) {
			visit[data + 1] = true;
			q.push({ data + 1, depth+1 });
		}
		if (valid(data * 2)) {
			visit[data * 2] = true;
			q.push({ data * 2, depth+1 });
		}
	}

}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	q.push({ N, 0 });
	visit[N] = true;
	bfs(N);

	cout << result;

	return 0;
}