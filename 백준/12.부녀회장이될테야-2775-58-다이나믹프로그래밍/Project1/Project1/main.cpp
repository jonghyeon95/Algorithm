//����Ʈ������
//k�� nȣ�� �����
//(k-1)���� 1ȣ~nȣ ������ ����� �հ� ���ƾ� �Ѵ�
//0������ ���� 1ȣ���� ����
//0���� iȣ���� i���� �������
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

	//0�� �ʱ�ȭ
	for (int i = 1; i <= max_K; i++)
	{
		dp[0][i] = i;
	}

	//�˰���
	for (int n = 1; n <= max_N; n++)	//n���� ��
	{
		for (int k = 1; k <= max_K; k++)	//kȣ�� ��
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
