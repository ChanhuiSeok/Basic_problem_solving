#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Atomic{
	int x;
	int y;
	int dir;
	int K;
	bool disCharge;
}atomic;

int arr[2002][2002];
int collide[2002][2002];
int collEntry[1001];
atomic atomic_list[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, N, inX, inY, inD, inK;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		for (int i = 1; i < 1001; i++) collEntry[i] = 0;

		// arr �迭 �ʱ�ȭ
		for (int k = 0; k < 2002; k++)
			for (int j = 0; j < 2002; j++) 
				arr[k][j] = 0;
					
		cin >> N; //������ ����

		for (int i = 1; i <= N; i++) {
			cin >> inX >> inY >> inD >> inK;
			atomic_list[i].x = inX + 1000;
			atomic_list[i].y = inY + 1000;

			if (inD == 0) atomic_list[i].dir = 1;
			else if (inD == 1) atomic_list[i].dir = -1;
			else if (inD == 2) atomic_list[i].dir = 2;
			else if (inD == 3) atomic_list[i].dir = -2;

			atomic_list[i].K = inK;
			atomic_list[i].disCharge = false;
			arr[inY + 1000][inX + 1000] = i;
		}

		int ty, tx, tD, tK;
		int time = 0, t_Energy = 0;

		// �ð� �帧 ����
		while (1) {
			time += 1;
			if (time > 2001) break; // -1000~1000 ���� �̵��� 2000��, �� �̻��� ��� ��� �� �ٱ�����..

			// [1] '�� ����'�� ���� �ºپ� �־ 0.5�ʿ� �ε��� ���� �ִ��� ���� Ȯ��
			for (int j = 1; j <= N; j++) {
				if (atomic_list[j].disCharge == true) continue; // �̹� ����� ���ڴ� �н�

				ty = atomic_list[j].y; tx = atomic_list[j].x;
				tD = atomic_list[j].dir; tK = atomic_list[j].K;

				// �ű�� ���� ���� ��ǥ ����
				int beforeX = tx, beforeY = ty;

				// ���ʴ�� ��(y ���� ����), ��, ��, ��� �̵����� ����.
				if (tD == 1) ty += 1; else if (tD == -1) ty -= 1;
				else if (tD == 2) tx -= 1; else tx += 1;

				// �ٷ� ���� ĭ�� ��� ������ ĭ�̸鼭, �ٸ� ���ڰ� ���� ���
				if (ty >= 0 && tx >= 0 && ty < 2002 && tx < 2002 && arr[ty][tx] != -1) {

					// �� ����ĭ�� ��ϵ� ���ڰ� ����� ���ڰ� �ƴ� ��쿡�� ����
					if (atomic_list[arr[ty][tx]].disCharge != true) {
						int nextDir = atomic_list[arr[ty][tx]].dir;

						// 0.5�ʿ��� �ε��� ��Ȳ�� �� ���, ���� �� �ʱ�ȭ ����
						if (nextDir * -1 == tD) {
							collEntry[arr[ty][tx]] = 1; collEntry[j] = 1;
							arr[beforeY][beforeX] = 0; // ���� �� �ڸ� �ʱ�ȭ
							atomic_list[j].disCharge = true; // ����
							atomic_list[arr[ty][tx]].disCharge = true; // ����
							arr[ty][tx] = 0; // �浹 ���� �ʱ�ȭ
						}
					}
				}	
			}

			// [2] �º��� ĭ ó�� �Ϸ� -> 1�� ���� �Ͼ�� ��
			for (int j = 1; j <= N; j++) {
				if (atomic_list[j].disCharge == true) continue; // �̹� ����� ���ڴ� �н�

				ty = atomic_list[j].y; tx = atomic_list[j].x;
				tD = atomic_list[j].dir; tK = atomic_list[j].K;

				// �ű�� ���� ���� ��ǥ ����
				int beforeX = tx, beforeY = ty;

				// ���ʴ�� ��(y ���� ����), ��, ��, ��� �̵����� ����.
				if (tD == 1) ty += 1; else if (tD == -1) ty -= 1;
				else if (tD == 2) tx -= 1; else tx += 1;
					
				// ������ �̵��ؾ� �� ���� �ƹ��͵� ���� ���, �ű��.
				if (ty >= 0 && ty < 2002 && tx >= 0 && tx < 2002 && collide[ty][tx] == 0) {
					arr[ty][tx] = j;
					atomic_list[j].y = ty; atomic_list[j].x = tx;
					collide[ty][tx] = tK; // �̵��� ĭ�� �������� ����
				}

				else if (ty >= 0 && ty < 2002 && tx >= 0 && tx < 2002 && collide[ty][tx] != 0) {
					collEntry[arr[beforeY][beforeX]] = 1;
					collEntry[arr[ty][tx]] = 1;

					if(arr[ty][tx] != 0) atomic_list[arr[ty][tx]].disCharge = true; // ���� ���� ����
					atomic_list[j].disCharge = true; // �浹 ���� ���� ����

					arr[beforeY][beforeX] = 0; // ���� �� �ڸ� �ʱ�ȭ
					arr[ty][tx] = 0; // �浹 ���� �ʱ�ȭ			
				}
				else arr[beforeY][beforeX] = 0; // ��� ���� ��� ��� ���� �� �ڸ� �ʱ�ȭ				
			}

			// [4] collide �迭 �ʱ�ȭ
			for (int k = 1; k<=N; k++) {
				int tx = atomic_list[k].x;
				int ty = atomic_list[k].y;
				collide[ty][tx] = 0;
			}
		}
		for (int i = 1; i <= N; i++) {
			if (collEntry[i] == 1) t_Energy += atomic_list[i].K;		
		}
		cout << "#" << t + 1 << " " << t_Energy << '\n';
	}
	return 0;
}