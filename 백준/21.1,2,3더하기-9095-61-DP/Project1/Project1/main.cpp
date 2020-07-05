//1,2,3 더하기
//1,2,3을 더해서 N을 만드는 경우의 수 출력

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	int maxn = 0;
	vector<int> vec;
	vector<int> dp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
		maxn = max(maxn, a);
	}
	dp.resize(maxn + 1, 0);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= maxn; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	
	for (int i = 0; i < vec.size(); i++)
	{
		cout << dp[vec[i]] << endl;
	}
}
