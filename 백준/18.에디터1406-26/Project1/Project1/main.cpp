//������
//���ڰ� �־���, Ŀ���� ����(���Ͽ���, ���Ͽ�����, �߰��� ��ġ����, ���ڱ���+1)
//�Է¹޴¹���
//L: Ŀ�� �������� ��ĭ �ű�
//D: Ŀ�� ���������� ��ĭ �ű�
//B: Ŀ�� ���ʿ� �ִ¹��� ����
//P%: %��¹��ڸ� Ŀ�� ���ʿ� �߰�
//������� �����

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int main()
{
	string answer = "";
	string s;
	int cmd;
	vector<string> cmd_vec;
	stack<char> stck1;
	stack<char> stck2;

	cin >> s;
	cin >> cmd;
	cin.ignore();
	for (int i = 0; i < cmd; i++)
	{
		string str;
		getline(cin, str);
		cmd_vec.push_back(str);
	}
	for (int i = 0; i < s.length(); i++)
	{
		stck1.push(s[i]);
	}

	for (int i = 0; i < cmd_vec.size(); i++)
	{
		if (cmd_vec[i][0] == 'L')
		{
			if (!stck1.empty())
			{
				char c = stck1.top();
				stck1.pop();
				stck2.push(c);
			}
		}
		else if (cmd_vec[i][0] == 'D')
		{
			if (!stck2.empty())
			{
				char c = stck2.top();
				stck2.pop();
				stck1.push(c);
			}
		}
		else if (cmd_vec[i][0] == 'B')
		{
			if (!stck1.empty())
			{
				stck1.pop();
			}
		}
		else if (cmd_vec[i][0] == 'P')
		{
			stck1.push(cmd_vec[i][2]);
		}
	}

	while (!stck1.empty())
	{
		char c = stck1.top();
		stck1.pop();
		stck2.push(c);
	}
	while (!stck2.empty())
	{
		answer += stck2.top();
		stck2.pop();
	}

	cout << answer << endl;
}



//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int main()
//{
//	string s;
//	int cursor;
//	int cmd;
//	vector<string> cmd_vec;
//
//	cin >> s;
//	cursor = s.length();
//	cin >> cmd;
//	cin.ignore();
//	for (int i = 0; i < cmd; i++)
//	{
//		string str;
//		getline(cin, str);
//		cmd_vec.push_back(str);
//	}
//
//	for (int i = 0; i < cmd_vec.size(); i++)
//	{
//		if (cmd_vec[i][0] == 'L')
//		{
//			if (cursor != 0)
//				cursor--;
//		}
//		else if (cmd_vec[i][0] == 'D')
//		{
//			if (cursor != s.length())
//				cursor++;
//		}
//		else if (cmd_vec[i][0] == 'B')
//		{
//			if (cursor != 0)
//			{
//				s = s.erase(cursor - 1, 1);
//				cursor--;
//			}
//		}
//		else if (cmd_vec[i][0] == 'P')
//		{
//			s = s.insert(cursor, 1, cmd_vec[i][2]);
//			cursor ++;
//		}
//	}
//
//	cout << s << endl;
//}