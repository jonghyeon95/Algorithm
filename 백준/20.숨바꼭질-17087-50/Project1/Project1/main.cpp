//숨바꼭질
//동생N명과 숨바꼭질 한다
//현재 위치는 점s
//동생은 a1,a2,an에 있다
//1초후에 x+D 가능, 딱 x+d가 정확한 위치여야 함
//d의 최댓값 구하기
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
		vec.push_back(abs(a-my));	//내위치와의 거리 
	}

	gcd = vec[0];
	for (int i = 1; i < num; i++)
	{
		gcd = GCD(gcd, vec[i]);
	}

	cout << gcd;

	return 0;
}
