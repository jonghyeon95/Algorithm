//�ﰢ�������
//������ n�� ������ ���� �� �ִ� �ﰢ�� ������??
//n<=50000


#include<iostream>
using namespace std;
int main()
{
	int n;
	int answer = 0;

	cin >> n;
	for (int i = 1; i <= n/2; i++)	//9���� 4������
	{
		for (int j = i; j < n; j++)	//�տ����� ���Ѱ��� ��ü-1 ���� �۰ų� ����
		{
			int k = n - i - j;
			if (k < j)
			{
				break;
			}
			if (i + j > k)
				answer++;
		}
	}
	cout << answer;
	return 0;
}