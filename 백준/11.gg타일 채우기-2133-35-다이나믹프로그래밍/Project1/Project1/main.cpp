//3xNũ���� ���� 2x1 or 1x2 Ÿ�Ϸ� ä��� ����� �� ���Ͻÿ�
// 1<= N <=30
//Ȧ���� �ȵ�
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