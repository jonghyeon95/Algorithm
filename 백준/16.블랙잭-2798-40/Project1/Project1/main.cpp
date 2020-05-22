//블랙잭게임
//N개의 카드중에서 3개를 택해서 M과 최대한 가깝게 해야함 (초과되면 안됨)
//3<=N<=100
//10<=M<=300000
//값은 100000이하


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int a, int b)
{
	return a > b;
}
int main()
{
	int N, M;
	vector<int> vec;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		vec.push_back(v);
	}

	sort(vec.begin(), vec.end(), comp);	//내림차순 정렬

	int m1, m2, m3, max = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		m1 = vec[i];
		if (m1 + vec[N - 1] + vec[N - 2] > M)
			continue;

		for (int j = i + 1; j < vec.size(); j++)
		{
			m2 = vec[j];
			if (m1 + m2 + vec[N - 1] > M)
				continue;
			for (int k = j + 1; k < vec.size(); k++)
			{
				m3 = vec[k];
				if (m1 + m2 + m3 <= M & m1 + m2 + m3 > max)
				{
					max = m1 + m2 + m3;
				}
			}
		}
	}
	cout << max;
	return 0;
}
