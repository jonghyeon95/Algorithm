//에디터
//문자가 주어짐, 커서가 존재(제일왼쪽, 제일오른쪽, 중간에 위치가능, 문자길이+1)
//입력받는문자
//L: 커서 왼쪽으로 한칸 옮김
//D: 커서 오른쪽으로 한칸 옮김
//B: 커서 왼쪽에 있는문자 지움
//P%: %라는문자를 커서 왼쪽에 추가
//최종결과 적어라

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