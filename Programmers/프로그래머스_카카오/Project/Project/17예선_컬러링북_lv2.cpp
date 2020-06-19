//m x n 배열 1<=  <=100
//배열의 원소값 0<= <=2^31 -1
//원소값이 0이면 색칠 안한곳
//가로세로 이어지면 한덩어리
//총 몇덩어리인가? and 가장큰덩어리의 갯수

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void req(int i, int j, long val, int m, int n, vector<vector<int>>& picture, int& c)
{
    picture[i][j] = -1;
    if (j < n - 1 && picture[i][j+1] == val)
    {
        c++;
        req(i, j+1, val, m, n, picture, c);
    }
    if (i < m - 1 && picture[i+1][j] == val)
    {
        c++;
        req(i+1, j, val, m, n, picture, c);
    }
    if (j > 0 && picture[i][j-1] == val)
    {
        c++;
        req(i, j-1, val, m, n, picture, c);
    }
    if (i > 0 && picture[i - 1][j] == val)
    {
        c++;
        req(i - 1, j, val, m, n, picture, c);
    }
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);
    vector<int> count;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int c = 1;
            if (picture[i][j] != 0 && picture[i][j] != -1)
            {
                req(i, j, picture[i][j], m, n, picture, c);
                count.push_back(c);
            }
        }
    }
    
    answer[0] = count.size();
    answer[1] = *max_element(count.begin(), count.end());
    return answer;
}
int main()
{
    //int m = 6;
    //int n = 4;
    //vector<vector<int>> picture = { {1, 1, 1, 0},{1, 2, 2, 0},{1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 3},{0, 0, 0, 3} };

    //int m = 13;
    //int n = 16;
    //vector<vector<int>> picture = { {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 }, { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 }, { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 }, { 0, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 0 }, { 0, 1, 1, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 1, 1, 0 }, { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 }, { 0, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 0 }, { 0, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 0 }, { 0, 0, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 0, 0 }, { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 }, { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 } };
    
    int m = 4;
    int n = 3;
    vector<vector<int>> picture = { {0,0,1},{1,0,1},{1,0,1},{1,1,1} };
    vector<int> answer = solution(m, n, picture);
    //12,120

    cout << answer[0] << ", " << answer[1];
}