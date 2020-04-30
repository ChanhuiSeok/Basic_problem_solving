#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>

typedef long long ll; // 2^63이 long long 범위
using namespace std;
map<ll, int> maps;

ll arr[100001];

bool compare(pair<ll, int>& a, pair<ll, int>& b) {
	if (a.second == b.second) {
		return a.first > b.first;
	}
	else
		return a.second < b.second;
}

int main() {

	int N, input;
	ll maxVal = -100;
	vector<pair<ll, int>> vec;
	int maxIdx = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		ll key;
		scanf("%lld", &key);
		maps[key]++;
	}

	for (int i = 0; i < N; i++) {
		if (maxVal < maps[i]) {
			maxVal = maps[i];
			maxIdx = i;
		}
	}

	copy(maps.begin(), maps.end(), back_inserter(vec)); // back_inserter 알아두기
	sort(vec.begin(), vec.end(), compare);


	printf("%lld", vec[vec.size() - 1].first);

}