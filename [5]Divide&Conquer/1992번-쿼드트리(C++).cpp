#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int map[65][65];
int N;
string temp = "";

// ��� ���� ������ �ƴ��� �Ǵ��ϴ� �Լ�
int check(int row, int col, int num) {

	int start = map[row][col]; // ��������. ��, �� ���� �� ��ĭ
	for (int i = row; i < row + num; i++) {
		for (int j = col; j < col + num; j++) {
			if (start != map[i][j]) return -1;
		}
	}
	if (start == 0)
		return 0;
	else
		return 1;
}

// �� 4���ҷ� �������� �Լ�
void divide(int row, int col, int num) {

	// ���� üũ. ��������, string �� ��ȭ
	int checkNum = check(row, col, num);

	if (checkNum == 0 || checkNum == 1){
		temp += to_string(checkNum);
	}

	else {
		int size = num / 2; // ����
		temp += "(";

		for (int i = 0; i < 2; i ++) {
			for (int j = 0; j < 2; j ++) {
				divide(row + size * i, col + size * j, size);
			}
		}
		temp += ")";
	}
}


int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	divide(0, 0, N);

	printf("%s", temp.c_str());

	return 0;
}