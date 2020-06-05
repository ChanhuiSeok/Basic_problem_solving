#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int arr[101][101];
int visit[101][101];

int row, col;
vector<int> result;

bool validation(int y, int x) {
	if (y < 0 || y >= row || x < 0 || x >= col || visit[y][x] == 1) {
		return false;
	}
	return true;
}

void dfs(int y, int x) {
	visit[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];
		if (validation(ty, tx) && (arr[ty][tx] == 0 || arr[ty][tx] == 5)) {
			visit[ty][tx] = 1;
			arr[ty][tx] = 5;
			dfs(ty, tx);
		}
	}
}

bool isAllMelted(int arr[][101]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i == 0 && j == 0) continue;
			if (arr[i][j] != 5 && arr[i][j] != 0) return false;
		}
	}
	return true;
}

int main() {

	int time = 0;
	int beforeBlockCnt = 0;

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {
		if (isAllMelted(arr)) break;

		// 1. 바깥 공기를 '5'로 바꿔주는 부분
		dfs(0, 0);
		
		// 2. '5'로 쓰여진 곳과 맞닿은 바깥 테두리를 '7'로 바꿔주는 부분
		int blockCnt = 0;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				bool flag = false;
				for (int k = 0; k < 4; k++) {
					int ty = i + dy[k];
					int tx = j + dx[k];
					if (arr[i][j] == 1 && arr[ty][tx] == 5) {
						flag = true;
						break;
					}
				}
				if (flag) arr[i][j] = 7;
				if (arr[i][j] == 7 || arr[i][j] == 1) blockCnt += 1;
			}
		}

		beforeBlockCnt = blockCnt;

		// 3. '7'로 표시된 곳을 '5'로 바꿔주는 부분
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (arr[i][j] == 7) arr[i][j] = 5;
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				visit[i][j] = 0;
			}
		}
		time += 1;
	}

	cout << time << '\n';
	cout << beforeBlockCnt;

	return 0;
}
