#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool visit[1001];

int main() {

    int T, N;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int cnt = 0;
        vector<int> input;
        scanf("%d", &N);

        input.pb(0);
        for (int i = 1; i <= N; i++) {
            int temp;
            scanf("%d", &temp);
            input.pb(temp);
        }

        // 첫 번째 노드부터 방문 시작
        for (int i = 1; i < input.size(); i++) {
            int j = 1;
            set<int> sets;

            if (!visit[i]) {
                visit[i] = true;
                j = i;
                while (1) {
                    int next = input[j];
                    if (!visit[next]) {
                        visit[next] = true;
                        j = next;
                    }
                    else
                        break;
                }
                cnt++;
            }
        }

        printf("%d\n", cnt);
        cnt = 0;
        for (int i = 0; i <= N; i++)
            visit[i] = false;

    }


    return 0;
}