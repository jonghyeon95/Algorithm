//문제
//N진수가 주어짐 if 3진수면
//1, 2, 1, 0, 1, 1, 1, 2 이런식으로 끊어서 말해야함
//n진법, 미리구할 숫자의 갯수t, 게임참가인원m, 내순서p
//16진법 까지 가능, A~F

#include <string>
#include <vector>
#include <iostream>
using namespace std;
string notation(int n, int a)
{
    string s = "";
    do
    {
        int nam = a % n;
        if (nam >= 10)
        {
            s = char(nam - 10 + 'A') + s;
        }
        else
        {
            s = char(nam + '0') + s;
        }
        a = a / n;
    } while (a != 0);

    return s;
}
string solution(int n, int t, int m, int p) 
{
    string answer = "";
    int number = 0;
    bool flag = true;
    string str;
    int cnt = 1;
    int i;
    int myturn = 0;
    while (myturn < t)
    {
        if (flag)
        {
            str = notation(n, number++);
            flag = false;
            i = 0;
        }

        char c = str[i++];

        if (cnt % m == p % m)
        {
            answer += c;
            myturn++;
        }

        if (str.length() == i)
        {
            flag = true;
        }
        cnt++;
    }

    return answer;
}
int main()
{
    int n, t, m, p;

 /*   n = 16;
    t = 16;
    m = 2;
    p = 1;*/

    n = 2;
    t = 4;
    m = 2;
    p = 1;

    cout << solution(n, t, m, p);
}