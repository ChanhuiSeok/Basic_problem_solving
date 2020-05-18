#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<int, int> maps;

int main() {

	int N, M;
	scanf("%d", &N);
	vector<int> nums;
	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);
		nums.push_back(input);
	}
	scanf("%d", &M);
	vector<int> finds;
	for (int i = 0; i < M; i++) {
		int input;
		scanf("%d", &input);
		finds.push_back(input);
	}

	sort(nums.begin(), nums.end());

	for (int i = 0; i < finds.size(); i++) {

		int target = finds[i]; // ã���� �ϴ� ��
		int left = 0;
		int right = N - 1;

		while (left <= right) {
			int mid = (left + right) / 2;

			// ã���� �ϴ� ���� �߰������� Ŭ ���
			if (target > nums[mid]) {
				left = mid + 1;
			}
			else if (target < nums[mid])
				right = mid - 1;
			else if (target == nums[mid]) {
				maps[finds[i]]++;
				break;
			}
		}

	}

	for (int i = 0; i < M; i++) {
		if (maps[finds[i]] != 0)
			printf("1");
		else
			printf("0");
		printf("\n");
	}


}