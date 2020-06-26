//����
//���α���2 �̰� ���α��� 1�� ���簢���ִ�
//����2�̰� ���ΰ� N�� ���簢���� ä����� �Ѵ�. ����� ����?

//�غ��ϱ� �Ǻ���ġ ��

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n)
{
    int answer = 0;

    vector<int> fiv(n + 1, 0);

    fiv[1] = 1;
    fiv[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        fiv[i] = (fiv[i - 1] + fiv[i - 2]) % 1000000007;
    }

    return fiv[n];
}
int main()
{
    int n = 10;
    cout << solution(n);
}