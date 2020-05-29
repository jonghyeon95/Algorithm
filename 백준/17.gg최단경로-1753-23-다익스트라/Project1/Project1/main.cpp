//다익스트라 알고리즘
// 1<=p<=20000
// 1<=n<=300000
// 1<=거리<=10


//메모리초과
#include <iostream>
#include <vector>
using namespace std;
#define INF 200001
int minDistance(vector<int>& dij, vector<bool> &b, int p)
{
	int min_idx = -1;
	int min_val = INF+1;
	for (int i = 0; i < p; i++)
	{
		if (!b[i] && dij[i] < min_val)
		{
			min_idx = i;
			min_val = dij[i];
		}
	}
	return min_idx;
}
int main()
{
	int p;	//장소 갯수
	int n;	//경로의 수
	int start;
	cin >> p >> n >> start;
	vector<int> dij(p);
	vector<bool> b(p, false);
	vector <vector<int>> route(p, vector<int>(p));
	//////초기설정

	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < p; j++)
		{
			if (i == j)
				route[i][j] = 0;
			else
				route[i][j] = INF;
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		int s;
		int e;
		int l;
		cin >> s >> e >> l;
		route[s-1][e-1] = l;
	}

	for (int i = 0; i < p; i++)
	{
		dij[i] = route[start - 1][i];
	}
	b[start - 1] = true;

	//풀이
	for (int i = 0; i < p - 2; i++)
	{
		int minIdx = minDistance(dij, b, p);
		b[minIdx] = true;

		for (int j = 0; j < p; j++)
		{
			if (!b[j] && dij[minIdx] + route[minIdx][j] < dij[j])
				dij[j] = dij[minIdx] + route[minIdx][j];
		}
	}


	//결과출력
	for (int i = 0; i < p; i++)
	{
		if (dij[i] == INF)
			cout << "INF" << endl;
		else
			cout << dij[i] << endl;
	}

	//for (int i = 0; i < p; i++)
	//{
	//	for (int j = 0; j < p; j++)
	//	{
	//		cout << route[i][j] << " ";
	//	}
	//	cout << endl;
	//}
}