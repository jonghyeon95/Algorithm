//문제
//number 문자열이 주어졌을 때
//k 개를 제거해서 만드는 가장 큰수

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) 
{
    string answer = "";
    int i = 0;
    while (k > 0 && i+1 < number.length())
    {
        if (number[i] < number[i + 1])
        {
            number = number.replace(i, 1, "");
            k--;
            if (i != 0)
                i--;
            continue;
        }
        i++;
    }

    if (k != 0)
    {
        number = number.substr(0, number.length() - k);
    }

    return number;
}
int main()
{
    string number = "6473";
    int k = 2;

    cout << solution(number, k);
}