//����
//���ڿ�s�� �������� ���е� ���ڵ��� �ִ� (��������)
//�ִ񰪰� �ּڰ��� �������� �����ض�

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string solution(string s) 
{
    vector<int> vec;

    string str = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            str += s[i];
        }
        else
        {
            vec.push_back(atoi(str.c_str()));
            str = "";
        }

        if (i + 1 == s.length())
        {
            vec.push_back(atoi(str.c_str()));
        }
    }

    sort(vec.begin(), vec.end());

    return to_string(vec[0]) + " " + to_string(vec[vec.size() - 1]);
}
int main()
{
    string s = "-1 -2 -3 -4";

    cout << solution(s);
}