//�ڿ��� n�̶� s�� �־���
//�ڿ��� n���� ���� s�� ����
//�ڿ��� n���� ���� ���� ū ����?

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, int s)
{
    if (n > s)
        return vector<int> {-1};

    vector<int> answer;

    int nam = s % n;
    for (int i = 0; i < n; i++)
    {
        answer.push_back(s / n);
    }
    for (int i = 0; i < nam; i++)
    {
        answer[n - 1 - i] += 1;
    }

    return answer;
}

int main()
{
    int n = 2;
    int s = 9;
    vector<int> answer = solution(n, s);

    for (int i : answer)
    {
        cout << i << " ";
    }
}