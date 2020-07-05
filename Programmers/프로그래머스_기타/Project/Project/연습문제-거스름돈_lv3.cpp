//����
//������ ���� 5�϶�
//�������ִ� ���� ������ [1,2,5] �϶�
//�����ִ� ����� �� ���ϱ�
//��<=100000 , ȭ����� 100��������
//1000000007 �� �������� �����ض�(Ŀ�����־)

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