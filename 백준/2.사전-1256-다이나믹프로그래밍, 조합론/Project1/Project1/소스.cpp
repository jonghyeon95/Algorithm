//문제
// N개의 "a"와 M개의 "z"
// 사전순 정렬 K번쨰 값은?
//N,M의 갯수는 0~100







//DP, 재귀	답지봄..
#include<iostream>
using namespace std;
#define N_Max 100
#define M_Max 100
#define K_Max 1000000000
int com[N_Max + M_Max + 1][N_Max + M_Max + 1];
int main()
{
	int N, M, K;
	int count;
	int size;
	string answer;
	cin >> N >> M >> K;

	if (N == 0)
	{
		for (int i = 0; i < M; i++)
			answer += 'z';
		cout << answer;
		return 0;
	}
	if (M == 0)
	{
		for (int i = 0; i < N; i++)
			answer += 'a';
		cout << answer;
		return 0;
	}
	//combination 채우기
	for (int n = 0; n <= 200; n++)
	{
		for (int r = 0; r <= n; r++)
		{
			if (n == 0 || r == 0 || n == r)
			{
				com[n][r] = 1;	//0C0 = 1
				continue;
			}
			com[n][r] = com[n - 1][r] + com[n - 1][r - 1];
			if (com[n][r] > K_Max)
				com[n][r] = K_Max + 1;
		}
	}


	//-1 검토
	if (com[N + M][N] < K)
	{
		cout << -1;
		return 0;
	}

	size = N + M;
	//글자쓰기
	for (int i = 0; i < size; i++)
	{
		if (N == 0)
		{
			answer += 'z';
			continue;
		}
		if (M == 0)
		{
			answer += 'a';
			continue;
		}
		int size = com[N + M - 1][N - 1];	//a하나를 썻다고 가정
		if (K <= size)	//a를 채워줌
		{
			answer += 'a';
			N--;
		}
		else
		{
			answer += 'z';
			M--;
			K -= size;
		}
	}
	cout << answer;
}





////이진법 시간초과
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//using namespace std;
//unsigned long long BinToDec(string str)
//{
//	unsigned long long num = 0;
//
//	for (int i = 0; i < str.length(); i++)
//	{
//		if (str[i] == '1')
//			num += 1 << (str.length() - i - 1);
//	}
//	return num;
//}
//string DecToBin(unsigned long long num, int len)
//{
//	string Bin;
//	int count = 0;
//	while (num != 0)
//	{
//		Bin += to_string(num % 2);
//		num = num / 2;
//		count++;
//		if (count == len)
//			break;
//	}
//	while (Bin.length() < len)
//	{
//		Bin += '0';
//	}
//
//	reverse(Bin.begin(), Bin.end());
//
//	return Bin;
//}
//int factorial(int n, int count)
//{
//	int result = 1;
//	for (int i = 0; i < count; i++)
//	{
//		result *= n - i;
//	}
//	return result;
//}
//int main()
//{
//	int N, M;
//	int Z;
//	string max_str;
//	string min_str;
//	unsigned long long max_int;
//	unsigned long long min_int;
//	string answer_bin;
//	string answer;
//	int count = 0;
//	int num_case;
//	cin >> N;
//	cin >> M;
//	cin >> Z;
//
//	num_case = factorial(N + M, N) / factorial(N, N);
//	if (num_case < Z)
//	{
//		cout << -1;
//		return -1;
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		max_str += "1";
//		min_str += "1";
//	}
//	for (int i = 0; i < M; i++)
//	{
//		max_str += "0";
//		min_str.insert(0, "0");
//	}
//
//	max_int = BinToDec(max_str);
//	min_int = BinToDec(min_str);
//
//	while (true)
//	{
//		string str;
//		int aNum = 0;
//		int zNum = 0;
//		str = DecToBin(max_int, N + M);
//		max_int -= 1;
//
//		for (int i = 0; i < str.length(); i++)
//		{
//			if (str[i] == '1')
//				aNum++;
//			else
//				zNum++;
//		}
//		if (aNum == N && zNum == M)
//		{
//			count++;
//			if (count == Z)
//			{
//				answer_bin = str;
//				break;
//			}
//
//		}
//	}
//	for (int i = 0; i < N + M; i++)
//	{
//		if (answer_bin[i] == '1')
//		{
//			answer += "a";
//		}
//		else
//		{
//			answer += "z";
//		}
//	}
//	cout << answer;
//}
