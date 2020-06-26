//문제
//문자열 s가 주어짐
//s의 첫번째 글자가 영어이면 첫번째 글자만 대문자 하고 나머지 문자다 소문자
//영어가 아니면 그 다음 단어의 첫번째 글자만 소문자 하고 나머지는 대문자


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