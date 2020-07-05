//���� 
//ex
//5�� ������ 12�� ǥ���ϴ¹��
//5+5+(5/5)+(5/5)   =>6��
//55/5 + 5/5        =>5��
//(55+5)/5          =>4��
//�ּ� ��밹�� 4 ����

//1<=N<=9
//1<= number <=32000
//Ƚ���� 8���� ũ�� -1 return;

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int N, int number) {
    int answer = -1;
    int val;
    vector<vector<int>> vec (9);
    vec[1].push_back(N);
    if (number == N)
        return 1;
    for (int i = 2; i <= 8; i++)
    {
        vec[i].push_back(vec[i - 1][0] * 10 + N);
        for (int j = 1; j <= i / 2; j++)
        {
            for (int k = 0; k < vec[j].size(); k++)
            {
                for (int l = 0; l < vec[i - j].size(); l++)
                {
                    vec[i].push_back(vec[j][k] * vec[i - j][l]);
                    if(vec[i-j][l] != 0)
                        vec[i].push_back(vec[j][k] / vec[i - j][l]);
                    vec[i].push_back(vec[j][k] + vec[i - j][l]);
                    vec[i].push_back(vec[j][k] - vec[i - j][l]);
                    vec[i].push_back(vec[i - j][l] - vec[j][k]);
                    if (vec[j][k] != 0)
                        vec[i].push_back(vec[i - j][l] / vec[j][k]);
                }
            }
        }
        auto iter = find(vec[i].begin(), vec[i].end(), number);
        if (iter != vec[i].end())
        {
            return i;
        }
    }

    return answer;
}
int main()
{
    int N = 5;
    int number = 12;

    cout << solution(N, number);
}
