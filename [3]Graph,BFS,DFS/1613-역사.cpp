#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int adj[401][401];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int a, b;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		adj[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (adj[i][k] && adj[k][j]) {
					adj[i][j] = 1;
				}
			}
		}
	}

	int temp;
	cin >> temp;

	for (int i = 0; i < temp; i++) {
		cin >> a >> b;
		if (adj[a][b] == 1)
			cout << -1 << '\n';
		else if (adj[b][a] == 1)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}