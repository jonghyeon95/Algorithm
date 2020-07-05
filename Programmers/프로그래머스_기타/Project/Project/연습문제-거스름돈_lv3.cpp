//문제
//내야할 돈이 5일때
//가지고있는 돈의 종류가 [1,2,5] 일때
//낼수있는 경우의 수 구하기
//돈<=100000 , 화폐단위 100종류이하
//1000000007 로 나머지를 리턴해라(커질수있어서)

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> money) 
{
    int answer = 0;

    vector<vector<int>> dp(money.size(), vector<int>(n + 1, 0));

    sort(money.begin(), money.end());

    for (int j = 1; j < dp[0].size(); j++)
    {
        if (j % money[0] == 0)
        {
            dp[0][j] = 1;
        }
    }

    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if (money[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else if(money[i] == j)
            {
                dp[i][j] = dp[i - 1][j] + 1;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - money[i]]) % 1000000007;
            }
        }
    }

    answer = dp[money.size() - 1][n];

    return answer;
}
int main()
{
    int n = 5;
    vector<int> money = { 1,2,5 };

    cout << solution(n, money);
}