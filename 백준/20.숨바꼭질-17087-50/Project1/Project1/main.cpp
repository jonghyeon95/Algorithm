//���ٲ���
//����N��� ���ٲ��� �Ѵ�
//���� ��ġ�� ��s
//������ a1,a2,an�� �ִ�
//1���Ŀ� x+D ����, �� x+d�� ��Ȯ�� ��ġ���� ��
//d�� �ִ� ���ϱ�
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

int main()
{
	int my;
	int num;
	int gcd = 1;
	vector<int> vec;

	cin >> num;
	cin >> my;

	for (int i = 0; i < num; i++)
	{
		int a;
		cin >> a;
		vec.push_back(abs(a-my));	//����ġ���� �Ÿ� 
	}

	gcd = vec[0];
	for (int i = 1; i < num; i++)
	{
		gcd = GCD(gcd, vec[i]);
	}

	cout << gcd;

	return 0;
}
