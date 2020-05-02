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

    /* �����佺���׽��� ü�� �Ҽ� ���ϱ� */
    for (int x = 2; x <= 1000000; x++) {
        if (sieve[x] == 1) continue; // 1�̸� �Ҽ��� �ƴ�
        for (int u = 2 * x; u <= 1000000; u += x) { // ��� ��� 1�� ǥ��
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
                    // ������� �Դٴ� ��,
                    // x�� ���� ������ ���ʷ� �����ϱ� ������
                    // ���� ū ������ �� �Ҽ��� ������ �� �ۿ� ����.
                }
            }

            // x�� n���� Ŀ���� ���� x
            if (x == 1000000) {
                printf("Goldbach's conjecture is wrong.\n");
                break;
            }
        }
    }
    return 0;
}