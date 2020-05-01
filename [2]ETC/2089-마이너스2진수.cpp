#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

int main() {

    int idx = 0;
    int N;
    string s = "";
    scanf("%d", &N);
    stack<int> result;

    if (N == 0)
        result.push(0);

    while (N) {

        if (N > 0) {
            result.push(N % 2);
            N = (N / 2) * -1;
        }

        else {

            if (N % 2 == 0) {
                result.push(0);
                N = (N * -1) / 2;
            }
            else {
                result.push(1);
                N = ((N * -1) + 1) / 2;
            }

        }

    }
    
    while (!result.empty()) {
        printf("%d", result.top());
        result.pop();
    }


    return 0;
}