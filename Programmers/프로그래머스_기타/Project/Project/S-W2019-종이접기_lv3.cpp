//����
//���簢���� �׻� ���ʿ��� �����ʹ������� ������ ����
//���� ���¿��� ������ ������ ������. ..N�� ���� 1<=N<=20
//������ �Ǹ� ���������� �ִµ� V�������� ������ 0, A�������� ������ 1��
//�����κи�� �����϶�

#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
vector<int> solution(int n) 
{
    vector<int> answer;
    string s = "0";
    for (int i = 0; i < n - 1; i++)
    {
        int len = s.length();
        s += "0" + s;
        s[len + pow(2, i)] = '1';
    }
    vector<char> answer_char (s.begin(), s.end());
    for (char c : answer_char)
    {
        answer.push_back(c - '0');
    }

    return answer;
}
int main()
{
    int n = 2;
    vector<int> answer = solution(n);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
}