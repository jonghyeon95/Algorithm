//타일 정사각형 한변 1 붙여서 직사각형 만듬
//다음에는 한변 2, 그다음은 3 ...
//N번째 전체 둘레, 1<= N <= 80

#include <string>
#include <vector>
#include <iostream>
using namespace std;
long long dp[81];
long long solution(int N) 
{
    long long answer = 0;

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < N + 1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    answer = dp[N - 1] + dp[N - 1] + dp[N] + dp[N];

    return answer;
}
int main()
{
    int N = 6;
    cout << solution(N);
}