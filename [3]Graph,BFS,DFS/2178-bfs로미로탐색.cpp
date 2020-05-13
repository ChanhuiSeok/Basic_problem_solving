#define _CRT_SECURE_NO_WARNINGS

#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, M;
int minPath = 1000001;
int arr[101][101];
int visit[101][101];
int pathnum[101][101];

queue<pair<int, int> > q;

bool permit(int y, int x) {
    if (y > N || x > M || y < 0 || x < 0)
        return false;
    return true;
}

// dfs로 하니까 시간 초과
void dfs(int y, int x, int path) {

    visit[y][x] = true;
   
    if (y == N - 1 && x == M - 1) {
        minPath = min(minPath, path);
        return;
    }

    if (path >= minPath) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ty = y + dy[i];
        int tx = x + dx[i];

        if (permit(ty, tx) && !visit[ty][tx] && arr[ty][tx] != 0) {
            dfs(ty, tx, path + 1);
            visit[ty][tx] = false;
        }
    }

}


int main() {

    int input;
    int paths = 0;
    string s;

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    getline(cin, s);
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        for (int k = 0; k < s.size(); k++)
            arr[i][k] = s[k] - '0';
    }

    q.push({ 0, 0 });
    // 큐가 빌 때 까지
    while (!q.empty()) {

       int y = q.front().first;
       int x = q.front().second;
       q.pop();

       if (y == N - 1 && x == M - 1) {
           break;
       }

       for (int i = 0; i < 4; i++) {
            int ty = y + dy[i];
            int tx = x + dx[i];

            if (permit(ty, tx) && visit[ty][tx] == 0 && arr[ty][tx] != 0) {
                visit[ty][tx] = visit[y][x] + 1;
                q.push({ ty, tx });
            }
       }
    }

    cout << visit[N-1][M-1] + 1;

    return 0;
}