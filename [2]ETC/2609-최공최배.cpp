#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

// 꼭 기억
int gcd(int a, int b) {

    if (b == 0)
        return a;
    else {
        return gcd(b, a % b);
    }
}



int main() {

    int a, b;
    int div;
    int LCM = 1;
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
    div = gcd(a, b);

    /*
    while (a != 1 || b != 1) {
        LCM = LCM * div;

        if (a / div == 0) {
            a = a % div;
        } else {
            a = a / div;
        }
            
        if (b / div == 0) {
            b = b % div;
        } else {
            b = b / div;
        }

        if (a != 1 || b != 1) {
            div = (a > b ? a : b);
        }
    }
    */
    // m * n = gcd * LCM 인 성질을 이용하면 된다.
    printf("%d", a * b / div);

    return 0;
}