#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, M, input;
	bool flag = false;
	vector<int> cards;
	vector<int> candidate;
	vector<int> result;

	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &input);
		cards.push_back(input);
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &input);
		candidate.push_back(input);
	}
	
	//(1) sorting
	sort(cards.begin(), cards.end());

	for (int idx = 0; idx < M; idx++) {
		int left = 0;
		int right = cards.size() - 1;
		flag = false;

		while (left <= right) {
			int mid = (left + right) / 2;
			int target = candidate[idx];

			//중간값보다 타겟이 클 경우
			if (cards[mid] < target) {
				left = mid + 1;
			}
			else if (cards[mid] > target) {
				right = mid - 1;
			}
			else {
				flag = true;
				break;
			}
		}
		if (flag) result.push_back(1);
		else result.push_back(0);
	}

	for (int i = 0; i < M; i++) {
		printf("%d ", result[i]);
	}

}