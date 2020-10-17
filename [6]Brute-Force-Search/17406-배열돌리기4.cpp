#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <deque>
#include <queue>

using namespace std;

int N, M, K;
int arr[52][52];
vector<int> order;
vector<int> oper[6];

// 배열의 값을 구하는 함수
int calArr() {
	int minV = 987654321;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= M; j++) {
			sum += arr[i][j];
		}
		minV = min(sum, minV);
	}
	return minV;
}

// 배열을 시계 방향으로 회전하는 함수
void circular(int r, int c, int s) {

	int copy_arr[52][52];
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			copy_arr[i][j] = 0;
		}
	}

	// (r-s,c-s) ~ (r+s,c+s) 정사각형 범위를 시계 방향으로 돌리기
	int idr = 0;
	while (1) {
		if ((c - s) + idr >= (c + s - 1) - idr) {
			break;
		}	
		// 맨 위의 가로행
		for (int col = (c - s) + idr; col <= (c + s - 1) - idr; col++) {
			copy_arr[r - s + idr][col + 1] = arr[r - s + idr][col];
		}
		// 오른쪽 세로열
		for (int row = (r - s) + idr; row <= (r + s - 1) - idr; row++) {
			copy_arr[row + 1][c + s - idr] = arr[row][c + s - idr];
		}
		// 아래쪽 가로행
		for (int col = (c + s) - idr; col >= (c - s + 1) + idr; col--) {
			copy_arr[r + s - idr][col - 1] = arr[r + s - idr][col];
		}
		// 위쪽 세로열
		for (int row = (r + s) - idr; row >= (r - s + 1) + idr; row--) {
			copy_arr[row - 1][c - s + idr] = arr[row][c - s + idr];
		}
		idr += 1;
	}
	// (r-s ~ r+s) 가 홀수였을 경우 정가운데 값은 채워주어야 한다.
	if ((r + s - r - s + 1) % 2 != 0) {
		int row = (r + s + r - s) / 2;
		int col = (c - s + c + s) / 2;
		copy_arr[row][col] = arr[row][col];
	}

	for (int i = r-s; i <= r+s; i++) {
		for (int j = c-s; j <= c+s; j++) {
			arr[i][j] = copy_arr[i][j];
		}
	}

}


int simulation() {

	int minV = 987654321;
	int copy_arr[52][52];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			copy_arr[i][j] = arr[i][j];
		}
	}

	do {
		// new_order에 담긴 순서대로 명령을 집어넣는다.
		// 그 명령대로 시계방향으로 돌려 본다.
		for (int k = 0; k < order.size(); k++) {
			int r, c, s;
			r = oper[order[k]][0];
			c = oper[order[k]][1];
			s = oper[order[k]][2];

			circular(r, c, s);
		}
		// 테스트 케이스 답
		minV = min(minV, calArr());

		// arr 원상복귀
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				arr[i][j] = copy_arr[i][j];
			}
		}

	} while (next_permutation(order.begin(), order.end()));
	return minV;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int m = 0; m < K; m++) {
		int r, c, s;
		cin >> r >> c >> s;
		oper[m] = { r,c,s };
	}

	// K 개수만큼 order에 넣기
	for (int i = 0; i < K; i++) {
		order.push_back(i);
	}

	int res = simulation();

	cout << res;

	return 0;
}