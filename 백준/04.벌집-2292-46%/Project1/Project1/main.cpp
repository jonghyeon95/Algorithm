//����
//���1 �ֺ����� 6N���� �þ
//N �־����� 1���� N���� ������ ���� ������?

#include<iostream>
using namespace std;
int main()
{
	int start = 1;
	int n;
	int answer = 1;
	cin >> n;

	while (n > start)
	{
		start += 6 * answer;
		answer++;
	}

	cout << answer;
}