//���� ���ڿ� s �� ���� n�� �־�������
//����s�� i��ŭ ���ض� (ex a + 2 = c)
//z������ a
//n<=25

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, int n) {
    string answer = "";

    for (int i = 0; i < s.length(); i++)
    {
        int a = s[i];

        if (a == ' ')
        {
            answer += ' ';
            continue;
        }
        
        a += n;

        if (a > 'Z' && s[i] <='Z')
            a = a - 'Z' + 'A' - 1;
        else if (a > 'z')
            a = a - 'z' + 'a' - 1;

        answer += char(a);
    }

    return answer;
}

int main()
{
    string s = "aAzZ";
    int n = 25;

    cout << solution(s, n);
}