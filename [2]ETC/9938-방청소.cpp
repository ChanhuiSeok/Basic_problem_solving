#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
typedef long long ll;

using namespace std;

int link[300001];
bool visit[300001];

int find(int v) {
	if (link[v] == v) return v;
	return link[v] = find(link[v]);
}

void unite(int a, int b) {
	// 먼저 a와 b의 대푯값을 찾는다.
	a = find(a);
	b = find(b);

	// 인자에 a의 부모를 b로 삼는다.
	if (a != b) {
		link[a] = b;
	}
	cout << "LADICA" << '\n';
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, L;
	cin >> N >> L;
	
	// 초기화
	for (int i = 1; i <= L; i++) {
		link[i] = i;
	}

	int a, b;
	// input이 1 2 이런 형태로 들어온다.
	// 1순위는 1번 서랍에 넣고, 1번이 찼으면 2번 서랍에 넣어라 이런 뜻이다.
	// 즉, 1번의 부모를 2번으로 둔다.
	// 2순위에 적힌 값이 1순위의 부모가 된다.
	// 서랍들에 대한 방문 배열을 둬서, 방문하지 않은 서랍에 대해서만 담을 수 있게 한다.
	// 즉 그래프를 쭉 따라가서 루트까지 따라가면서 빈 서랍이 있었을 경우 거기에 담고,
	// 최종적으로는 1순위 서랍의 루트와 2순위 서랍의 루트가 합쳐져 1순위 서랍 루트 부모는 2순위 서랍 루트 부모가
	// 되는 그림이 그려진다.
	for (int i = 0; i < N; i++) {
		cin >> a >> b;

		if (!visit[a]) {
			visit[a] = true;
			unite(a, b);
		}
		else if (!visit[b]) {
			visit[b] = true;
			unite(b, a);
		}
		else if (!visit[find(link[a])]) {
			visit[find(link[a])] = true;
			unite(a, b);
		}
		else if (!visit[find(link[b])]) {
			visit[find(link[b])] = true;
			unite(b, a);
		}
		else {
			cout << "SMECE" << '\n';
		}
	}

	
	return 0;
}