//문제
//[ 1, 2, 3 ,4 , 5]
//시작부터 끝까지 가야함
//값이 점프할수있는 최대값
//최소 경우의 수 리턴
//못가면 -1

#include <iostream>
using namespace std;
#define Max_N 1001
int main()
{
	int n;
	int dp[Max_N] = { 0, };
	int* arr;
	cin >> n;

	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		arr[i] = v;
	}

	////풀이
	for (int i = 0; i < n; i++)
	{
		if (i != 0 && dp[i] == 0)	//i 까지 못오는경우
		{
			continue;
		}
		int d = arr[i];
		for (int j = 1; j <= d; j++)
		{
			if (i + j >= n)
			{
				break;
			}
			if (dp[i + j] == 0 || dp[i + j] > dp[i] + 1)	//값이 없음 or 기존값이 더 클 경우
			{
				dp[i + j] = dp[i] + 1;
			}
		}
	}

	if (dp[n - 1] == 0 && n != 1)
	{
		cout << -1;
		return 0;
	}
	cout << dp[n - 1];
	return 0;
}