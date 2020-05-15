//벌집
//가운데1 주변으로 6N개씩 늘어남
//N 주어질때 1부터 N까지 지나는 방의 갯수는?

#include<iostream>
using namespace std;
int main()
{
	int start = 1;
	int n;
	int answer = 1;
	cin >> n;

	while (n > start)
	{
		start += 6 * answer;
		answer++;
	}

	cout << answer;
}