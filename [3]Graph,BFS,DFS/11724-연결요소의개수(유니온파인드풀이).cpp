#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <set>

using namespace std;
typedef pair<int, int> pi;

int parents[1001];
int N, M;

int finds(int num) {
	if (parents[num] == num) return num;
	return parents[num] = finds(parents[num]);
}

void unions(int a, int b) {
	int root_a = finds(a);
	int root_b = finds(b);

	if (root_a < root_b) {
		parents[root_b] = root_a;
	}
	else {
		parents[root_a] = root_b;
	}
}

int main() {

	int result = 0;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		parents[i] = i; // 일단 자기 자신의 부모는 자기 자신으로 초기화

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		unions(a, b);
	}

	for (int i = 1; i <= N; i++) {
		if (parents[i] == i)
			result += 1;
	}

	printf("%d", result);
	return 0;
}