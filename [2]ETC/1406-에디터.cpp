#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char s[100001];
    char added;

    list<char> li;
    list<char>::iterator iter;
    list<char>::iterator end_iter;

    int cursor;
    int m, Idx = 0;
    int sLength = 0;

    scanf("%s", s);    
    scanf("%d", &m);

    // strlen도 시간 초과에 많은 영향을 주었다.
    // 그냥 for문 두번째 조건을 true냐 false냐로 판단하도록
    // s[i]로 둔다. (널문자이면 for문 빠져나가도록)
    for (int i = 0; s[i]; i++) {
        li.push_back(s[i]);
    }
    
    end_iter = li.end();

    for (int i = 0; i < m; i++) {

        char oper, ch, added;
        scanf("%c", &ch);
        scanf("%c", &oper);
        
        if (oper == 'L' && end_iter != li.begin()) { // 왼쪽으로 이동
            end_iter--;
        }
        else if (oper == 'D' && end_iter != li.end()) { // 오른쪽으로 이동
            end_iter++;
        }
        else if (oper == 'B' && end_iter != li.begin()) {// 왼쪽 삭제         
            end_iter--;
            end_iter = li.erase(end_iter);
            // 그냥 li.erase(end_iter)을 하는 것과,
            // end_iter = li.erase(end_iter)을 하여 담는 것과는
            // 엄청 다른 것이다. 이렇게 안전하게 지운 뒤
            // 그 자리의 iterator를 담아두어야 한다.
        }
        else if (oper == 'P') {
            scanf("%c", &ch);
            scanf("%c", &added);
            li.insert(end_iter, added);
        }
    }

    for (iter = li.begin(); iter != li.end(); iter++){
        printf("%c", *iter);
    }
    
    return 0;
}