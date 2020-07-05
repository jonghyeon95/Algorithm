//문제
//N행 4열의 2차원 배열이있다.
//각행에서 한칸만 밟을 수 있다
//밟은 칸의 점수의 합이 최대를 찾아라
//단, 같은 열을 연속해서 못밟는다

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

////완탐
//vector<int> lastrow;
//void req(vector<vector<int>>& land, int row, int col, int sum)
//{
//    if (row == land.size())
//    {
//        lastrow.push_back(sum);
//        return;
//    }
//    for (int i = 0; i < land[0].size(); i++)
//    {
//        if (i != col)
//        {
//            req(land, row + 1, i, sum + land[row][i]);
//        }
//    }
//}
//int solution(vector<vector<int>> land)
//{
//    for (int i = 0; i < land[0].size(); i++)
//    {
//        req(land, 1, i, land[0][i]);
//    }
//
//    return *max_element(lastrow.begin(), lastrow.end());
//}
//dp
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