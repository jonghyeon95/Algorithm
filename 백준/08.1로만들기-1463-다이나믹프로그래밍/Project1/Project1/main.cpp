//1�� ���ų� ,3���� �����ų�, 2�� �������ִ�
//1�� ����� �ּ�Ƚ�� ���ϱ�
#include <iostream>
using namespace std;
int main()
{
	int dp[1000001];
	int N;
	cin >> N;

	dp[1] = 0;

	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
		{
			dp[i] = dp[i] < dp[i / 3] + 1 ? dp[i] : dp[i / 3] + 1;
		}
		else if (i % 2 == 0)
		{
			dp[i] = dp[i] < dp[i / 2] + 1 ? dp[i] : dp[i / 2] + 1;
		}
	}
	cout << dp[N];

	return 0;
}