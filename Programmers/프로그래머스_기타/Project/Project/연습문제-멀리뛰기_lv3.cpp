//문제
//한번에 1칸 or 2칸 뛸수 있다
//칸이 총 4개 있을때 경우의수는 5개이다
//경우의 수를 구하라

#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int n) 
{
    vector<long long> dp(n + 1, 0);

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    }

    return dp[n];
}
int main()
{
    int n = 4;
    cout << solution(n);
}