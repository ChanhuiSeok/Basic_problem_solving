#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

int main() {

    int N, K;
    vector<int> origin;
    vector<int> yo;
    vector<int>::iterator iter;
    string result = "";

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    int Idx;
    Idx = 0;

    for (int i = 1; i <= N; i++) {
        origin.push_back(i);
    }

    Idx = 0;
    iter = origin.begin();
    while (!origin.empty()) {
        int i = 0;
        // 3칸 까지 뒤로 갈 수 있으면
        if (Idx + (K -1) < origin.size()) {
            Idx = Idx + (K - 1);
            for (iter = origin.begin(); iter != origin.end(); iter++, i++) {
                if (i == Idx) {
                    break;
                }
            }
            yo.push_back(*iter);
            origin.erase(iter);
        }

        else if (Idx + (K - 1) >= origin.size()) {
            Idx = (Idx + (K - 1)) % origin.size();
            for (iter = origin.begin(); iter != origin.end(); iter++, i++) {
                if (i == Idx) {
                    break;
                }
            }
            yo.push_back(*iter);
            origin.erase(iter);
        }
    }

    result += "<";
 
    for (int i = 0; i < yo.size(); i++) {
        result += to_string(yo[i]);
        if (i == yo.size()-1){
           break;
        }
        else {
            result += ", ";
        }
    }

    result += ">";

    cout << result;
    return 0;
}