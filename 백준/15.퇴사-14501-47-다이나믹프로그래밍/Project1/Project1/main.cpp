//N일까지 상담을 해야함
//N+1일이 넘어가는 상담은 하지 못함
//	1일	2일	3일	4일	5일	6일	7일
//Ti 3	5	1	1	2	4	2
//Pi 10	20	10	20	15	40	200
//1일차에 일을 하면 그날포함 3일동안 다른상담못함
//받을수있는 최대 돈은?
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
//	//값 입력
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
//	answer = req(1);	//1일차부터 시작
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

	//값 입력
	for (int i = 1; i <= N; i++)
	{
		int d, m;
		cin >> d >> m;
		{
			d_vec[i] = d;
			m_vec[i] = m;
		}
	}

	answer = req(1);	//1일차부터 시작
	
	cout << answer;

	return 0;
}
