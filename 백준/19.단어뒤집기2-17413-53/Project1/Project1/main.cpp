//문자열뒤집기2
//소문자, 숫자, 공백, 특수문자 < > 가 있음
//문자열 시작 끝은 공백이 아님
//한 단어만 뒤집음(소문자,숫자), 띄어쓰기와, <>로 단어 구분
//괄호안에 있는건 안뒤집음

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int main()
{
	string answer = "";
	string s;
	getline(cin, s);
	bool flag = true;
	stack<char> stck;

	for (int i = 0; i < s.length(); i++)
	{
		if (flag)
		{
			if (s[i] == '<')
			{
				while (!stck.empty())
				{
					answer += stck.top();
					stck.pop();
				}
				answer += '<';
				flag = false;
				
				continue;
			}
			if (s[i] != ' ')
			{
				stck.push(s[i]);
			}
			else
			{
				while (!stck.empty())
				{
					answer += stck.top();
					stck.pop();
				}
				answer += ' ';
			}
		}
		else
		{
			answer += s[i];
			if (s[i] == '>')
			{
				flag = true;
			}
		}
	}

	while (!stck.empty())
	{
		answer += stck.top();
		stck.pop();
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