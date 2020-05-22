//�������
//N���� ī���߿��� 3���� ���ؼ� M�� �ִ��� ������ �ؾ��� (�ʰ��Ǹ� �ȵ�)
//3<=N<=100
//10<=M<=300000
//���� 100000����


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

	sort(vec.begin(), vec.end(), comp);	//�������� ����

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
