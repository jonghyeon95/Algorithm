//����
//�ڿ��� n�� �־�������
//�����ϴ� ������ ���� n�� ����� ���� ���϶�
//ex 15
//1+2+3+4+5
//4+5+6
//7+8
//15  =>�� 4��

#include<iostream>
#include <string>
#include <vector>
using namespace std;
int solution(int n) 
{
    int answer = 0;

	for (int i = 1; i <= n / 2 + 1; i++)
	{
        int sum = 0;
        for (int j = i; sum < n; j++)
        {
            sum += j;
            if (sum == n)
            {
                answer++;
                break;
            }
        }
	}

    if (n != 1 && n != 2)
    {
        answer++;
    }

    return answer;
}
int main()
{
    int n = 15;
    cout << solution(n);
}