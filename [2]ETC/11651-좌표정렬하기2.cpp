#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else
		return a.second < b.second;
}

int main() {

	vector<pair<int, int>> pi;
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		pi.push_back({ a,b });
	}

	sort(pi.begin(), pi.end(), compare);

	for (int i = 0; i < N; i++) {
		printf("%d %d\n", pi[i].first, pi[i].second);
	}

}