#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

#define INF 987654321

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int R, C;

char arr[51][51];
int visit[51][51];
int visit_water[51][51];
int startY, startX;
int waterY, waterX;
int destY, destX;

int minPath = INF;

vector<pair<int, int>> water_dist;
queue<pair<int, int>> water;
queue<pair<int, pair<int, int>>> path;


bool valid_path(int y, int x) {
	if (y < 0 || y >= R || x < 0 || x >= C ||
		visit[y][x] || arr[y][x] == '*' || arr[y][x] == 'X') {
		return false;
	}
	return true;
}

bool valid_water(int y, int x) {
	if (y < 0 || y >= R || x < 0 || x >= C ||
		visit_water[y][x] || arr[y][x] == 'D' || arr[y][x] == 'X') {
		return false;
	}
	return true;
}

void bfs() {

	// 초기 위치 push
	path.push({ 0, {startY, startX} });
	visit[startY][startX] = 1;

	// 초기 물 위치 push
	for(int i = 0; i<water_dist.size();i++)
		water.push({ water_dist[i].first, water_dist[i].second });

	while (!path.empty()) {
		vector<pair<int, int>>cand_water;
		vector<pair<int, pair<int, int>>>cand_path;

		//(1) 물이 상,하,좌,우로 예비로 퍼지게 한다.
		while (!water.empty()) {
			int wry = water.front().first;
			int wrx = water.front().second;
			visit_water[wry][wrx] = 1;
			water.pop();

			for (int i = 0; i < 4; i++) {
				int wty = wry + dy[i];
				int wtx = wrx + dx[i];
				if (valid_water(wty, wtx)) {
					arr[wty][wtx] = '*';
					visit_water[wty][wtx] = 1;
					cand_water.push_back({ wty,wtx });
				}
			}
		}
		for (int i = 0; i < cand_water.size(); i++) {
			water.push({ cand_water[i].first,cand_water[i].second });
		}
		
		/*
		cout << "\n물을 퍼뜨린 후 " << '\n';
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << arr[i][j] << " ";
			}
			cout << '\n';
		}
		*/
		
		while (!path.empty()) {
			//(2) 고슴도치가 갈 길을 가게 한다.
			int rPath = path.front().first;
			int ry = path.front().second.first;
			int rx = path.front().second.second;
			visit[ry][rx] = 1;
			path.pop();

			if (ry == destY && rx == destX) {
				minPath = min(minPath, rPath);
			}

			for (int i = 0; i < 4; i++) {
				int ty = ry + dy[i];
				int tx = rx + dx[i];

				if (valid_path(ty, tx)) {
					visit[ty][tx] = 1;
					cand_path.push_back({ rPath + 1, {ty,tx} });
				}
			}
		}
		for (int i = 0; i < cand_path.size(); i++) {
			path.push({ cand_path[i].first,cand_path[i].second });
		}

	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				startY = i;
				startX = j;
			}
			if (arr[i][j] == '*') {
				water_dist.push_back({ i,j });
			}
			if (arr[i][j] == 'D') {
				destY = i;
				destX = j;
			}
		}
	}

	// 물은 *, 돌은 X, 비어있는 곳은 .
	// 비버의 굴은 D, 고슴도치의 위치는 S.
	bfs();
	
	if (minPath == INF) cout << "KAKTUS";
	else cout << minPath;

	return 0;
}
