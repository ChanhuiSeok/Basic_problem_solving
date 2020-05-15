#define _CRT_SECURE_NO_WARNINGS
#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

typedef long long ll;

using namespace std;

ll arr[10001];

int main() {

    int K, N; // ������ �ִ� ���� ���� K, �ʿ��� �ּ� ���� N
    
    scanf("%d %d", &K, &N);

    for (int i = 0; i < K; i++) {
        scanf("%lld", &arr[i]);
    }
    sort(arr, arr + K);

    ll left = 1, right = arr[K-1];
    ll answer = 0;

    while (left <= right) {

        ll mid = (left + right) / 2;
        ll sum = 0;

        for (int i = 0; i < K; i++) {
            sum += arr[i] / mid;
        }

        // ���� ������ N������ ������ ���
        if (sum < N) {
            right = mid - 1; // �ڸ��� ���̸� �ٿ� ����.
        }
        else if (sum >= N) {
            if (answer < mid)
                answer = mid;
            left = mid + 1; // �ڸ��� ���̸� �÷� ����.
        }
    }

    printf("%lld", answer);

    return 0;
}