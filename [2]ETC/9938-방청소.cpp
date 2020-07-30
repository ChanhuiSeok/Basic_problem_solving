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
	// ���� a�� b�� ��ǩ���� ã�´�.
	a = find(a);
	b = find(b);

	// ���ڿ� a�� �θ� b�� ��´�.
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
	
	// �ʱ�ȭ
	for (int i = 1; i <= L; i++) {
		link[i] = i;
	}

	int a, b;
	// input�� 1 2 �̷� ���·� ���´�.
	// 1������ 1�� ������ �ְ�, 1���� á���� 2�� ������ �־�� �̷� ���̴�.
	// ��, 1���� �θ� 2������ �д�.
	// 2������ ���� ���� 1������ �θ� �ȴ�.
	// �����鿡 ���� �湮 �迭�� �ּ�, �湮���� ���� ������ ���ؼ��� ���� �� �ְ� �Ѵ�.
	// �� �׷����� �� ���󰡼� ��Ʈ���� ���󰡸鼭 �� ������ �־��� ��� �ű⿡ ���,
	// ���������δ� 1���� ������ ��Ʈ�� 2���� ������ ��Ʈ�� ������ 1���� ���� ��Ʈ �θ�� 2���� ���� ��Ʈ �θ�
	// �Ǵ� �׸��� �׷�����.
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