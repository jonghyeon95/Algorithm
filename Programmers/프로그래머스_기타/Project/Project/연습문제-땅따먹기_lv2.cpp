//����
//N�� 4���� 2���� �迭���ִ�.
//���࿡�� ��ĭ�� ���� �� �ִ�
//���� ĭ�� ������ ���� �ִ븦 ã�ƶ�
//��, ���� ���� �����ؼ� ����´�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int secondMax(int idx, vector<int> vec)
{
    int max = -1;
    for (int i = 0; i < vec.size(); i++)
    {
        if (i != idx && max <= vec[i])
            max = vec[i];
    }
    return max;
}
int solution(vector<vector<int>> land)
{
    int answer = 0;
    int idx = 0;
    int max_idx = (max_element(land[0].begin(), land[0].end()) - land[0].begin());
    int max= land[0][max_idx];
    int max2= secondMax(max_idx, land[0]);

    for (int i = 1; i < land.size(); i++)
    {
        for (int j = 0; j < land[0].size(); j++)
        {
            if (j != max_idx)
                land[i][j] += max;
            else
                land[i][j] += max2;
        }
        max_idx = (max_element(land[i].begin(), land[i].end()) - land[i].begin());
        max = land[i][max_idx];
        max2 = secondMax(max_idx, land[i]);
    }

    answer = *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end());

    return answer;
}
int main()
{
    vector<vector<int> > land{ {1,2,3,5},{5,6,7,8},{4,3,2,1} };
    cout << solution(land);
}