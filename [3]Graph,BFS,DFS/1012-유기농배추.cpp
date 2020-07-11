#include <iostream>
#include <algorithm>

using namespace std;

int arr[51][51];
int visit[51][51];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int bugCnt = 0;

int T, M, N, K, X, Y;

void dfs(int y, int x) {

	// 상,하,좌,우 실시
	visit[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];

		// 갈 수 있는 범위이고 방문하지 않았을 경우 탐색
		if (ty >= 0 && ty < N && tx >= 0 && tx < M && !visit[ty][tx]) {	
			// 배추가 심어져 있을 경우에만 이동
			if (arr[ty][tx] == 1) {
				visit[ty][tx] = 1;
				dfs(ty, tx);
			}
		}
	}

}



int main() {
	
	int resultCnt = 0;

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int t = 0; t < T; t++) {

		cin >> M >> N >> K; // M은 가로, N은 세로 길이
		// K는 배추가 심어져 있는 위치의 갯수

		for (int i = 0; i < K; i++) {
			cin >> X >> Y; // X는 가로, Y는 세로
			arr[Y][X] = 1;
		}

		for (int i = 0; i < N; i++) { // M은 가로
			for (int j = 0; j < M; j++) { // N은 세로
				if (arr[i][j] == 1 && visit[i][j] == 0) {
					dfs(i, j);
					resultCnt += 1;
				}
			}
		}

		cout << resultCnt << '\n';
		
		//초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				arr[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		bugCnt = 0; resultCnt = 0;
	}

	return 0;
}