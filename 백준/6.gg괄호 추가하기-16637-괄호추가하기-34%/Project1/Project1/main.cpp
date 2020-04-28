//문제
//연산이 있다 * + -
//무조건 왼쪽이 먼저실행
//괄호를 넣어서 최댓값 만들기
//괄호안에 들어갈 수있는 수식은 한개 and 괄호 중복 불가
//N = 수식,숫자 갯수 1<= N <=19
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int N;
	string exp;
	vector<int> num;
	vector<char> op;
	string num_str;
	int answer = 0;

	cin >> N;
	cin >> exp;

	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '+' || exp[i] == '*' || exp[i] == '-')
		{
			op.push_back(exp[i]);
			num.push_back(atoi(num_str.c_str()));
			num_str.clear();
		}
		else	//숫자일때
		{
			if (i == exp.length() - 1)
			{
				num_str += exp[i];
				num.push_back(atoi(num_str.c_str()));
			}
			else
			{
				num_str += exp[i];
			}
		}
	}



	//우선순위계산
	for (int i = 0; i < op.size(); i++)
	{
		if (op[i] == '+')
		{
			num[i + 1] += num[i];
			op[i] = ' ';
		}
		else if (op[i] == '-')
		{
			if (i < num.size() - 2 && op[i + 1] == '-' && num[i + 1] - num[i + 2] < 0)
			{
				num[i + 2] = num[i + 1] - num[i + 2];
				op[i + 1] = ' ';
			}
		}
		if (op[i] == ' ')
		{
			continue;
		}
	}


	////최종계산
	for (int i = 0; i < op.size(); i++)
	{
		if (op[i] == '+' || op[i] == '-' || op[i] == '*')
		{
			answer = num[i];
			break;
		}
	}

	for(int i=0; i<op.size(); i++)
	{
		if (op[i] == ' ')
		{
			continue;
		}
		int n;
		n = num[i+1];

		switch (op[i])
		{
		case '+':
			answer += n;
			break;

		case '-':
			if (i < op.size() - 1 && op[i + 1] == ' ')
			{
				answer -= num[i + 2];
				continue;
			}
			answer -= n;
			break;

		case '*':
			answer *= n;
			break;
		}
	}
	cout << answer;
}