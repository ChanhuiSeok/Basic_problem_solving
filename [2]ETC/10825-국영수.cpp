#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

typedef struct student {

	string name;
	int korean;
	int english;
	int math;

}stu;

bool compare(stu a1, stu a2) {

	if (a1.korean == a2.korean &&
		a1.english == a2.english &&
		a1.math == a2.math) {
		return a1.name < a2.name;
	}

	else if (a1.korean == a2.korean &&
		a1.english == a2.english) {
		return a1.math > a2.math;
	}

	else if (a1.korean == a2.korean) {
		return a1.english < a2.english;
	}

	else {
		return a1.korean > a2.korean;
	}
}

int main() {

	vector<stu> vec;
	int N;

	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		int a, b, c;
		stu st;
		cin >> s >> a >> b >> c;
		st.name = s; st.korean = a; st.english = b;
		st.math = c;
		vec.push_back(st);
	}

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << vec[i].name << '\n';
	}


}