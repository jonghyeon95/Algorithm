//N�ϱ��� ����� �ؾ���
//N+1���� �Ѿ�� ����� ���� ����
//	1��	2��	3��	4��	5��	6��	7��
//Ti 3	5	1	1	2	4	2
//Pi 10	20	10	20	15	40	200
//1������ ���� �ϸ� �׳����� 3�ϵ��� �ٸ�������
//�������ִ� �ִ� ����?
//1<=N<=15
//1<=T<=5
//1<=P<=1000

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//vector<int> dp(15 + 1,-1);
//vector<int> d_vec(15 + 1);
//vector<int> m_vec(15 + 1);
//int N;
//int req(int d)
//{
//	if (d == N + 1)
//	{
//		return 0;
//	}
//	if (d > N + 1)
//	{
//		return -9999999;
//	}
//
//	int Max = dp[d];
//	if (Max != -1)
//		return Max;
//	
//	Max = max(req(d + d_vec[d]) + m_vec[d], req(d + 1));
//	
//	return Max;
//}
//int main()
//{
//	cin >> N;
//	int answer;
//
//	//�� �Է�
//	for (int i = 1; i <= N; i++)
//	{
//		int d, m;
//		cin >> d >> m;
//		if (i + d > N)
//		{
//			d_vec[i] = d;
//			m_vec[i] = m;
//		}
//	}
//
//	answer = req(1);	//1�������� ����
//	
//	cout << answer;
//	//for (int i = 1; i <= N; i++)
//	//{
//	//	cout << d_vec[i] << " " << m_vec[i] << endl;
//	//}
//	return 0;
//}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> dp(15 + 1,-1);
vector<int> d_vec(15 + 1);
vector<int> m_vec(15 + 1);
int N;
int req(int d)
{
	if (d == N + 1)
	{
		return 0;
	}
	if (d > N + 1)
	{
		return -9999999;
	}

	int Max = max(req(d + d_vec[d]) + m_vec[d], req(d + 1));
	
	return Max;
}
int main()
{
	cin >> N;
	int answer;

	//�� �Է�
	for (int i = 1; i <= N; i++)
	{
		int d, m;
		cin >> d >> m;
		{
			d_vec[i] = d;
			m_vec[i] = m;
		}
	}

	answer = req(1);	//1�������� ����
	
	cout << answer;

	return 0;
}
