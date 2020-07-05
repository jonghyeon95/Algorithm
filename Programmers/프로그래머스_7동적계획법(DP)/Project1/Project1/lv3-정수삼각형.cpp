//�����ﰢ��
//		1
//	2		3
//4		5		6
//1�� 2,3�� �̵�����
//2�� 4,5�� �̵�����
//3�� 5,6�� �̵�����
//�̵������� ���ؼ� �ִ� ���� ���϶�

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            int max = -1;
            if (j - 1 != -1)    //���� ���� �ƴ� ��
            {
                max = max > triangle[i - 1][j - 1] + triangle[i][j] ? max : triangle[i - 1][j - 1] + triangle[i][j];
            }
            if (j + 1 != triangle[i].size())    //������ ���� �ƴ� ��
            {
                max = max > triangle[i - 1][j] + triangle[i][j] ? max : triangle[i - 1][j] + triangle[i][j];
            }
            triangle[i][j] = max;
        }
    }
    
    int last = triangle.size() - 1;
    answer = *max_element(triangle[last].begin(), triangle[last].end());

    return answer;
}
int main()
{
    vector<vector<int>> triangle = { {7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5} };

    cout << solution(triangle);
}