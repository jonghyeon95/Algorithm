//아파트가있음
//k층 n호에 사려면
//(k-1)층의 1호~n호 까지의 사람의 합과 같아야 한다
//0층부터 존재 1호부터 있음
//0층의 i호에는 i명이 살고있음
//1<=k<=14
//1<=n<=14

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	long long a = 1000000000000;
	cout << a;
	int dp[15][15];
	int test;
	int max_N, max_K;
	cin >> test;
	vector<int> N( test );
	vector<int> K( test );
	for (int i = 0; i < test; i++)
	{
		cin >> N[i];
		cin >> K[i];
	}

	max_N = *max_element(N.begin(), N.end());
	max_K = *max_element(K.begin(), K.end());

	//0층 초기화
	for (int i = 1; i <= max_K; i++)
	{
		dp[0][i] = i;
	}

	//알고리즘
	for (int n = 1; n <= max_N; n++)	//n층일 때
	{
		for (int k = 1; k <= max_K; k++)	//k호일 때
		{
			int sum = 0;
			for (int s = 1; s <= k; s++)
			{
				sum += dp[n - 1][s];
			}
			dp[n][k] = sum;
		}
	}

	for (int i = 0; i < test; i++)
	{
		cout << dp[N[i]][K[i]] << endl;
	}
}
