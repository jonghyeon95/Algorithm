//����
//���ڿ� ������ �ܾ��� ���� ���Ͻÿ�
//���� ���̴� ����� ������

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
		if (str[i] != ' ' && word_start == false)	//�ܾ ���۵� ��
		{
			word_start = true;
		}
		if ((str[i] == ' ' || i == str.length() - 1) && word_start == true) //�ܾ ������ 
		{
			count++;
			word_start = false;
		}
	}
	cout << count;
}