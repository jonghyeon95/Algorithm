//����
//���ڿ� s�� �־���
//s�� ù��° ���ڰ� �����̸� ù��° ���ڸ� �빮�� �ϰ� ������ ���ڴ� �ҹ���
//��� �ƴϸ� �� ���� �ܾ��� ù��° ���ڸ� �ҹ��� �ϰ� �������� �빮��


#include <string>
#include <iostream>
using namespace std;
bool english(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    return false;
}

string solution(string s) 
{
    string answer = "";
    bool flag = true;
    
    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 'a' - 'A';

        if (flag && english(s[i]))
        {
            if (s[i] >= 'a')
                s[i] = s[i] - ('a' - 'A');
        }
        flag = false;

        if (s[i] == ' ')
            flag = true;
    }

    return s;
}
int main()
{
    string s = "3people unFollowed me";
    //string s = "for the last week";

    cout << solution(s);
}