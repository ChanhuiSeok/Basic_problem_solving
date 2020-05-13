#define _CRT_SECURE_NO_WARNINGS

#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int cnt;
int member[100001];
bool cycle[100001];
bool visit[100001];

void dfs(int n_num) {

    visit[n_num] = true; // �湮 ǥ��
    int next = member[n_num];

    if (!visit[next]) {
        dfs(next);
    }
    else if (!cycle[next]) { // �̹� ����Ŭ�� �̾Ƴ´� ���� �ֳ� Ȯ��, �ƴ� ��츸 �Ʒ� ����
        for (int i = next; i != n_num; i = member[i])
            cnt++;
        cnt++;
    }
    cycle[n_num] = true;

}

/* DFS�� ����Ŭ�� �Ǵ��ϴ� ���� */

int main() {

    int input;
    int T, n;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        memset(visit, false, sizeof(visit));
        memset(cycle, false, sizeof(cycle));

        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &member[i]);
        }

        for (int k = 1; k <= n; k++) {
            if (!visit[k])
                dfs(k);
        }

        printf("%d\n", n - cnt);
        cnt = 0;
    }
    return 0;
}