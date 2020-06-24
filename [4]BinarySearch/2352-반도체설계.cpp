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
		mid = (left + right) / 2; // �߰��� ����

		if (lis[mid] < target) { // lis �迭�� �� ���� ã�� ���̹Ƿ�
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
	lis[0] = arr[0]; // lis �迭�� �� ù��° ���� arr[0]���� �ʱ�ȭ
	int i = 1;

	// arr�� �ι�°���� ���������� �ϳ��� lis�� ���ϸ鼭 �־��ش�.
	while (i < n) {

		// lis �迭�� �� ���� ������ arr[i]�� �� ũ�� �װ��� lis�迭 �� ���� �־��ش�.
		if (lis[j] < arr[i]) {
			lis[j + 1] = arr[i];
			j += 1;
		}
		// arr[i]���� �� ������, arr[i]�� ���� lis �迭 �� ��� ���� ������ �̺�Ž���Ѵ�.
		else {
			int idx = binarysearch(0, j, arr[i]);
			lis[idx] = arr[i];
		}
		i += 1;
	}

	cout << j + 1;


	return 0;
}