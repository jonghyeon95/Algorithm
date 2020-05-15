//문제
//문자열 있을때 단어의 갯수 구하시오
//문자 사이는 띄어쓰기로 나눠짐

#include<iostream>
using namespace std;
#include <string>
int main()
{
	string str;
	int count = 0;
	bool word_start = false;
	getline(cin, str);

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && word_start == false)	//단어가 시작될 때
		{
			word_start = true;
		}
		if ((str[i] == ' ' || i == str.length() - 1) && word_start == true) //단어가 끝날때 
		{
			count++;
			word_start = false;
		}
	}
	cout << count;
}