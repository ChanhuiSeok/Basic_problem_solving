#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int result[3];
int map[2200][2200];

// ���� ������ ������ ��� ������ �ƴ��� �Ǵ��ϴ� �Լ�
bool check(int row, int col, int num) {
	// ������
	int start = map[row][col];
	for (int i = row; i < row + num; i++) {
		for (int j = col; j < col + num; j++) {
			if (start != map[i][j])
				return false;
		}
	}
	return true;
}

// 9���ҷ� �������� �Լ�
void divide(int row, int col, int num) {

	// ���� ���� ���� ���� ��� ���� ���
	if (check(row, col, num)) {
		result[map[row][col]]++;
	}
	else {
		// ���ο� ��������� �����.
		int size = num / 3; // ó���� num 27�̾��ٸ� ���� ���� ���簢���� �� ���� ���̰� 9
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {

				divide(row + size * i, col + size * j, size);

			}
		}
	}
}


int main() {

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			int input;
			scanf("%d", &input);
			input++; // -1,0,1 �� ���� 0,1,2�� ǥ��
			
			map[i][j] = input;

		}
	}

	divide(0, 0, N);

	printf("%d\n%d\n%d", result[0], result[1], result[2]);

}