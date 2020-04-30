#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	int N, K;
	vector<int> vec;
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);
		vec.push_back(input);
	}

	sort(vec.begin(), vec.end());

	printf("%d", vec[K - 1]);

	return 0;
}