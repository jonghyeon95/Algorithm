//정수삼각형
//		1
//	2		3
//4		5		6
//1은 2,3로 이동가능
//2은 4,5로 이동가능
//3은 5,6로 이동가능
//이동했을때 더해서 최대 합을 구하라

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
            if (j - 1 != -1)    //왼쪽 끝이 아닐 때
            {
                max = max > triangle[i - 1][j - 1] + triangle[i][j] ? max : triangle[i - 1][j - 1] + triangle[i][j];
            }
            if (j + 1 != triangle[i].size())    //오른쪽 끝이 아닐 때
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