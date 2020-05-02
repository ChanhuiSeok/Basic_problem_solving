#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX 1000000

using namespace std;

int sieve[1000001];
int visit[1000001];

int main() {
    //int M, N;
    int n, x;
    int diff;
    int maxDiff = -1;

    /* 에라토스네테스의 체로 소수 구하기 */
    for (int x = 2; x <= 1000000; x++) {
        if (sieve[x] == 1) continue; // 1이면 소수가 아님
        for (int u = 2 * x; u <= 1000000; u += x) { // 배수 모두 1로 표시
            sieve[u] = 1;
        }
    }

    sieve[0] = 1;
    sieve[1] = 1;
   
    while (1) {
        int n;
        maxDiff = -1;
        scanf("%d", &n);

        if (n == 0)
            break;

        for (int x = 3; x <= 1000000; x++) {
            if (sieve[x] == 0) { 
                diff = n - x;
                if (sieve[diff] == 0) {
                    printf("%d = %d + %d\n", n, x, diff);
                    break;
                    // 여기까지 왔다는 건,
                    // x는 작은 수부터 차례로 시작하기 때문에
                    // 가장 큰 차이의 두 소수가 구해질 수 밖에 없다.
                }
            }

            // x가 n보다 커지면 성립 x
            if (x == 1000000) {
                printf("Goldbach's conjecture is wrong.\n");
                break;
            }
        }
    }
    return 0;
}