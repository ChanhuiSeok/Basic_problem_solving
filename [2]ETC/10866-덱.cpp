#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	deque<int> deq;

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		int input;

		cin >> s;
		if (s == "push_front") {
			cin >> input;
			deq.push_front(input);
		}

		else if (s == "push_back") {
			cin >> input;
			deq.push_back(input);
		}

		else if (s == "pop_front") {
			if (!deq.empty())
			{
				cout << deq.front() << '\n';
				deq.pop_front();
			}
			else {
				cout << -1 << '\n';
			}
		}

		else if (s == "pop_back") {
			if (!deq.empty())
			{
				cout << deq.back() << '\n';
				deq.pop_back();
			}
			else {
				cout << -1 << '\n';
			}
		}

		else if (s == "size") {
			cout << deq.size() << '\n';
		}

		else if (s == "empty") {
			if (!deq.empty())		
				cout << 0 << '\n';
			
			else 
				cout << 1 << '\n';
			
		}
		else if (s == "front") {
			if (!deq.empty())
			{
				cout << deq.front() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (s == "back") {
			if (!deq.empty())
			{
				cout << deq.back() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}

	}
}