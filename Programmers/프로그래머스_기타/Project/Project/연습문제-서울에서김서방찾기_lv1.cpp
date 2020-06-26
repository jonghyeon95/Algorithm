//문제
//seoul 이라는 배열이 있다
//seoul 배열에서 Kim 이란 문자열의 인덱스 반환

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<string> seoul) {
    string a = " ";
    for (int i = 0; i < seoul.size(); i++)
    {
        if (seoul[i].compare("Kim") == 0)
        {
            return "김서방은 " +to_string(i)+ "에 있다";
        }
    }
}
int main()
{
    vector<string> seoul = { "Jane", "Kim" };
    cout << solution(seoul);
}