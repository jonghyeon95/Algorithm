//����
//2�̻��� �� n�� �Էµ� ��
//1234567�� ���� �������� �����ϴ� �Լ�

#include <string>
#include <vector>
#include <iostream>
using namespace std;
int solution(int n) 
{
    vector<int> fivo(n + 1, 0);
    fivo[1] = 1;
    fivo[2] = 1;
    for (int i = 3; i < n + 1; i++)
    {
        fivo[i] = fivo[i - 1] + fivo[i - 2];
        fivo[i] %= 1234567;
    }

    return fivo[n];
}
int main()
{
    int n = 5;
    cout << solution(n);
}