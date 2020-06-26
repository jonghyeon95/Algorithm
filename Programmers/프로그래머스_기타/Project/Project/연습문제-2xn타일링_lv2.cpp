//문제
//가로길이2 이고 세로길이 1인 직사각형있다
//세로2이고 가로가 N인 직사각형에 채우려고 한다. 경우의 수는?

//해보니깐 피보나치 임

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n)
{
    int answer = 0;

    vector<int> fiv(n + 1, 0);

    fiv[1] = 1;
    fiv[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        fiv[i] = (fiv[i - 1] + fiv[i - 2]) % 1000000007;
    }

    return fiv[n];
}
int main()
{
    int n = 10;
    cout << solution(n);
}