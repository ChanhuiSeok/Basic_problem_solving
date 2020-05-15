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

    int N, M; // N�� ������ ����, M�� ������ ���������� ������ ����
    // ��, ������ M�� �ʰ������� ������ �ȴ�. �� M ������ ���� �� �ִ��� ���ϸ� ��
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
            // ������ �߶� ����.
            if (mid <= arr[i])
                sum += arr[i] - mid;
        }

        // ���� ���� M���� �۾�����, ���� ���̸� ���纼 �� �ִ�.
        if (sum < M) {
            right = mid - 1;
        }
        // M���� ������, ���� ���̸� ���� ����.
        else {
            answer = mid;
            left = mid + 1;
        }
    }

    printf("%lld", answer);

    return 0;
}