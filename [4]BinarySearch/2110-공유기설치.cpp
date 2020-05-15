#define _CRT_SECURE_NO_WARNINGS

#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

typedef long long ll;

using namespace std;

ll* arr;

int main() {

    int N, M; // N은 나무의 갯수, M은 집으로 가져가려는 나무의 길이
    // 단, 나무는 M을 초과하지만 않으면 된다. 즉 M 이하의 숫자 중 최댓값을 구하면 됨
    int input;

    scanf("%d %d", &N, &M);

    arr = new ll[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &input);
        arr[i] = input;
    }

    sort(arr, arr + N);

    ll left, right, answer;
    left = 0; right = arr[N - 1];

    while (left <= right) {
        ll mid = (left + right) / 2;
        ll sum = 0;

        for (int i = 0; i < N; i++) {
            // 나무를 잘라 본다.
            if (mid <= arr[i])
                sum += arr[i] - mid;
        }

        // 합한 값이 M보다 작았으면, 톱의 높이를 낮춰볼 수 있다.
        if (sum < M) {
            right = mid - 1;
        }
        // M보다 컸으면, 톱의 높이를 높여 본다.
        else {
            answer = mid;
            left = mid + 1;
        }
    }

    printf("%lld", answer);

    return 0;
}