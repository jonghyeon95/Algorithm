//삼각형만들기
//성냥이 n개 있을때 만들 수 있는 삼각형 갯수는??
//n<=50000


#include<iostream>
using namespace std;
int main()
{
	int n;
	int answer = 0;

	cin >> n;
	for (int i = 1; i <= n/2; i++)	//9개면 4까지만
	{
		for (int j = i; j < n; j++)	//앞에꺼랑 더한값이 전체-1 보다 작거나 같음
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