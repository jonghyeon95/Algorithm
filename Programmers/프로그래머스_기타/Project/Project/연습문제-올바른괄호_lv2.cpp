//����
//���ڿ� s �� ��ȣ���� �������
//��ȣ ��ġ�� �ùٸ��� true, �ƴϸ� false

#include<string>
#include <iostream>
#include <stack>
using namespace std;
bool solution(string s)
{
    bool answer = true;
    stack<char> stck;
    stack<char> sub;

    for (int i = 0; i < s.length(); i++)
    {

        stck.push(s[i]);
    }

    while (!stck.empty())
    {
        char c = stck.top();
        stck.pop();

        if (sub.empty())
        {
            if (c == '(')
            {
                answer = false;
                break;
            }
            else
            {
                sub.push(c);
            }
        }
        else
        {
            char d = sub.top();
            if (c != d)
            {
                sub.pop();
            }
            else
            {
                sub.push(c);
            }
        }
    }
    
    if (!sub.empty())
        answer = false;

    return answer;
}
int main()
{
    string s = "())";
    cout << solution(s);
}