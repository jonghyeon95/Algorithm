//����
//[ 1, 2, 3 ,4 , 5]
//���ۺ��� ������ ������
//���� �����Ҽ��ִ� �ִ밪
//�ּ� ����� �� ����
//������ -1

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

	////Ǯ��
	for (int i = 0; i < n; i++)
	{
		if (i != 0 && dp[i] == 0)	//i ���� �����°��
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
			if (dp[i + j] == 0 || dp[i + j] > dp[i] + 1)	//���� ���� or �������� �� Ŭ ���
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