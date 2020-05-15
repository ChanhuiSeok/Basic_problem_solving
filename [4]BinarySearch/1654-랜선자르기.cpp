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

    int K, N; // 가지고 있는 랜선 갯수 K, 필요한 최소 갯수 N
    
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

        // 합한 갯수가 N개보다 적었을 경우
        if (sum < N) {
            right = mid - 1; // 자르는 길이를 줄여 본다.
        }
        else if (sum >= N) {
            if (answer < mid)
                answer = mid;
            left = mid + 1; // 자르는 길이를 늘려 본다.
        }
    }

    printf("%lld", answer);

    return 0;
}