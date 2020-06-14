#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int seive[10001];
int visit[10001];

int main() {

	int T;
	scanf("%d", &T);

	for (int x = 2; x < 10001; x++) {
		if (seive[x] == 0) {
			for (int u = 2 * x; u < 10001; u += x) {
				seive[u] = 1;
			}
		}
	}

	int a, b;
	int result_depth;
	for (int i = 0; i < T; i++) {

		bool finishFlag = false;
		queue<pair<int, int>> q;
		memset(visit, 0, sizeof(visit));
		scanf("%d %d", &a, &b);
		
		q.push({ a,0 });

		if (a == b) {
			printf("0\n");
			continue;
		}

		while (!q.empty() && !finishFlag) {
			int num = q.front().first;
			int depth = q.front().second;
			q.pop();

			string strNum;

			for (int i = 0; i < 4; i++) {
				strNum = to_string(num);

				for (int j = 0; j <= 9; j++) {
					// 숫자를 바꿔보기
					strNum[i] = j + 48;
					int stoiNum = stoi(strNum);

					if (stoiNum < 1000 || stoiNum == a) continue;

					if (seive[stoiNum] == 0 && visit[stoiNum] == 0) {
						if (stoiNum == b) {
							result_depth = depth + 1;
							finishFlag = true;
							break;
						}
						q.push({ stoiNum, depth + 1 });
						visit[stoiNum] = 1;
					}
				}
				if (finishFlag) break;
			}
		}
		if (finishFlag) printf("%d\n", result_depth);
		else if (!finishFlag) printf("Impossible\n");
	}

	return 0;
}