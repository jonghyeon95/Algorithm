//����
//������ �ִ� * + -
//������ ������ ��������
//��ȣ�� �־ �ִ� �����
//��ȣ�ȿ� �� ���ִ� ������ �Ѱ� and ��ȣ �ߺ� �Ұ�
//N = ����,���� ���� 1<= N <=19
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
		else	//�����϶�
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



	//�켱�������
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


	////�������
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