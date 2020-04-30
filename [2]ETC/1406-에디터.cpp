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

    // strlen�� �ð� �ʰ��� ���� ������ �־���.
    // �׳� for�� �ι�° ������ true�� false�ķ� �Ǵ��ϵ���
    // s[i]�� �д�. (�ι����̸� for�� ������������)
    for (int i = 0; s[i]; i++) {
        li.push_back(s[i]);
    }
    
    end_iter = li.end();

    for (int i = 0; i < m; i++) {

        char oper, ch, added;
        scanf("%c", &ch);
        scanf("%c", &oper);
        
        if (oper == 'L' && end_iter != li.begin()) { // �������� �̵�
            end_iter--;
        }
        else if (oper == 'D' && end_iter != li.end()) { // ���������� �̵�
            end_iter++;
        }
        else if (oper == 'B' && end_iter != li.begin()) {// ���� ����         
            end_iter--;
            end_iter = li.erase(end_iter);
            // �׳� li.erase(end_iter)�� �ϴ� �Ͱ�,
            // end_iter = li.erase(end_iter)�� �Ͽ� ��� �Ͱ���
            // ��û �ٸ� ���̴�. �̷��� �����ϰ� ���� ��
            // �� �ڸ��� iterator�� ��Ƶξ�� �Ѵ�.
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