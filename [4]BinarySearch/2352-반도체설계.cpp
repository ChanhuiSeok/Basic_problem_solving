#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int n;
int arr[40001];
int lis[40001];

int binarysearch(int left, int right, int target) {

	int mid;

	while (left < right) {
		mid = (left + right) / 2; // 중간값 설정

		if (lis[mid] < target) { // lis 배열에 들어갈 것을 찾는 것이므로
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return right;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int j = 0;
	lis[0] = arr[0]; // lis 배열의 맨 첫번째 값은 arr[0]으로 초기화
	int i = 1;

	// arr의 두번째부터 마지막까지 하나씩 lis와 비교하면서 넣어준다.
	while (i < n) {

		// lis 배열의 맨 뒤의 값보다 arr[i]가 더 크면 그것을 lis배열 맨 끝에 넣어준다.
		if (lis[j] < arr[i]) {
			lis[j + 1] = arr[i];
			j += 1;
		}
		// arr[i]값이 더 작으면, arr[i]의 값이 lis 배열 중 어느 곳에 들어올지 이분탐색한다.
		else {
			int idx = binarysearch(0, j, arr[i]);
			lis[idx] = arr[i];
		}
		i += 1;
	}

	cout << j + 1;


	return 0;
}