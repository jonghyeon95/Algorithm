//N과 M사이 소수 모두 출력
//1<=M<=N<1000000
//일반적인 방법은 시간초과 뜸

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int main(void)
{
	int M, N;
	cin >> M >> N;

	int* arr = new int[N + 1];

	arr[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(N); i++)
	{
		if (arr[i] == 0)
		{
			continue;
		}
		for (int j = i * i; j <= N; j += i)
		{
			arr[j] = 0;
		}
	}

	for (int i = M; i <= N; i++)
	{
		if (arr[i] != 0)
			cout << arr[i] << '\n';
	}

	return 0;
}