//3xN크기의 벽을 2x1 or 1x2 타일로 채우는 경우의 수 구하시오
// 1<= N <=30
//홀수면 안됨
//
#include<iostream>
using namespace std;
int dp[31];
int main()
{
	int N;
	cin >> N;

	dp[2] = 3;

	if (N % 2 == 1)
	{
		cout << 0;
		return 0;
	}

	for (int i = 4; i <= N; i+=2)
	{
		dp[i] = 

	}
}