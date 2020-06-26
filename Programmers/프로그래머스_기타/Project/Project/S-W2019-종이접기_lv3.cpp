//문제
//직사각형을 항상 왼쪽에서 오른쪽방향으로 절반을 접음
//접은 상태에서 또접고 또접고 또접고. ..N번 접음 1<=N<=20
//접고나서 피면 접힌방향이 있는데 V방향으로 접히면 0, A방향으로 접히면 1임
//접힌부분모양 리턴하라

#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
vector<int> solution(int n) 
{
    vector<int> answer;
    string s = "0";
    for (int i = 0; i < n - 1; i++)
    {
        int len = s.length();
        s += "0" + s;
        s[len + pow(2, i)] = '1';
    }
    vector<char> answer_char (s.begin(), s.end());
    for (char c : answer_char)
    {
        answer.push_back(c - '0');
    }

    return answer;
}
int main()
{
    int n = 2;
    vector<int> answer = solution(n);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
}