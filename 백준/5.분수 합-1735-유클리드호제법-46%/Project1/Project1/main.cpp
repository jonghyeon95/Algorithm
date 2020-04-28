//문제
//Top1,Top2 :분자
//Bottom1, Bottom2 : 분모
//두분수 합치고 기약분수로 나타내서
//분자, 분모로 출력


//방법2 메모리1984, 시간984
#include<iostream>
using namespace std;
int main()
{
	int top1, top2, sum_top;
	int bot1, bot2, sum_bot;
	int min_sum;
	int Great_1, Great_2, Great_sum;

	cin >> top1 >> bot1;
	cin >> top2 >> bot2;

	sum_top = top1 * bot2 + top2 * bot1;
	sum_bot = bot1 * bot2;

	int i = 2;
	while (i <= sum_top && i <= sum_bot)
	{
		if (sum_top % i == 0 && sum_bot % i == 0)
		{
			sum_top /= i;
			sum_bot /= i;
			i = 2;
		}
		else
			i++;
	}
	cout << sum_top << " " << sum_bot;
}




////방법1 메모리1984, 시간984
//#include<iostream>
//using namespace std;
//int Greatestfactor(int a, int b)
//{
//	int max, min;
//	int Great = 1;
//	max = a >= b ? a : b;
//	min = a < b ? a : b;
//
//	for (int i = min; i > 0; i--)
//	{
//		if (max % i == 0 && min % i == 0)
//		{
//			Great = i;
//			return Great;
//		}
//	}
//	return Great;
//}
//int main()
//{
//	int top1, top2, sum_top;
//	int bot1, bot2, sum_bot;
//	
//	int Great_1, Great_2, Great_sum;
//
//	cin >> top1 >> bot1;
//	cin >> top2 >> bot2;
//	
//	Great_1 = Greatestfactor(top1, bot1);
//	Great_2 = Greatestfactor(top2, bot2);
//
//	top1 = top1 / Great_1;
//	bot1 = bot1 / Great_1;
//
//	top2 = top2 / Great_2;
//	bot2 = bot2 / Great_2;
//
//	sum_top = top1 * bot2 + top2 * bot1;
//	sum_bot = bot1 * bot2;
//	
//	Great_sum = Greatestfactor(sum_top, sum_bot);
//
//	cout << sum_top / Great_sum << " " << sum_bot / Great_sum;
//}