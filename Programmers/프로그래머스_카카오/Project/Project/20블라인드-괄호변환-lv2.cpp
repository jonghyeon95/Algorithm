//����
//��ȣ�� ������ ������ �迭�� Ʋ�� ���ڿ��� ����
//�ùٸ��� �����Ͻÿ�

//1. �Է��� �� ���ڿ��� ���, �� ���ڿ��� ��ȯ�մϴ�.
//2. ���ڿ� w�� �� "�������� ��ȣ ���ڿ�" u, v�� �и��մϴ�.��, u�� "�������� ��ȣ ���ڿ�"�� �� �̻� �и��� �� ����� �ϸ�, v�� �� ���ڿ��� �� �� �ֽ��ϴ�.
//3. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�" �̶�� ���ڿ� v�� ���� 1�ܰ���� �ٽ� �����մϴ�.
//3 - 1. ������ ��� ���ڿ��� u�� �̾� ���� �� ��ȯ�մϴ�.
//4. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�"�� �ƴ϶�� �Ʒ� ������ �����մϴ�.
//4 - 1. �� ���ڿ��� ù ��° ���ڷ� '('�� ���Դϴ�.
//4 - 2. ���ڿ� v�� ���� 1�ܰ���� ��������� ������ ��� ���ڿ��� �̾� ���Դϴ�.
//4 - 3. ')'�� �ٽ� ���Դϴ�.
//4 - 4. u�� ù ��°�� ������ ���ڸ� �����ϰ�, ������ ���ڿ��� ��ȣ ������ ����� �ڿ� ���Դϴ�.
//4 - 5. ������ ���ڿ��� ��ȯ�մϴ�.

#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool check(string s)
{
    int val = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            val++;
        }
        else
        {
            val--;
        }
        if (val < 0)
            return false;
    }
    return true;
}
string reverse(string s)
{
    s = s.substr(1, s.length() - 2);

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
            s[i] = '(';
        else
            s[i] = ')';
    }
    return s;
}
string req(string s)
{
    string answer;
    int val = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            val++;
        }
        else
        {
            val--;
        }

        if (val == 0)
        {
            string u = s.substr(0, i + 1);
            string v = s.substr(i + 1, s.length());

            if (check(u))
            {
                answer = u + req(v);
            }
            else
            {
                answer = "(" + req(v) + ")" + reverse(u);
            }
            break;
        }
    }
    return answer;
}
string solution(string p)
{
    string answer = "";

    answer = req(p);


    return answer;
}
int main()
{
    string p = ")()()()(";
    cout << solution(p);
}