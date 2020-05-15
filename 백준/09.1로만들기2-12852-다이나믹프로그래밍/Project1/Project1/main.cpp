//1로 빼거나 ,3으로 나누거나, 2로 나눌수있다
//1을 만드는 최소횟수와 지나는 루트 구하기

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int dp[1000001];
	int N;
	vector<int> vec;
	cin >> N;

	//dp[N] 구하기
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


	//루트구하기
	vec.push_back(N);
	for (int i = 0, n = N; i < dp[N]; i++)
	{
		int k = dp[n - 1];
		int val = n - 1;
		if (n % 3 == 0)
		{
			if (k > dp[n / 3])
			{
				k = dp[n / 3];
				val = n / 3;
			}
		}
		else if (n % 2 == 0)
		{
			if (k > dp[n / 2])
			{
				k = dp[n / 2];
				val = n / 2;
			}
		}
		n = val;
		vec.push_back(val);
	}

	cout << dp[N] << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	return 0;
}