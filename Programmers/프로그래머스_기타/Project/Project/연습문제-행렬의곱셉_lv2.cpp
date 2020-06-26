//문제
//2차원행렬 arr1과 arr2의 곱을 변환하는 함수

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int> vec;
        for (int j = 0; j < arr2[0].size(); j++)
        {
            int result = 0;
            for (int k = 0; k < arr1[0].size(); k++)
            {
                 result += arr1[i][k] * arr2[k][j];
            }
            vec.push_back(result);
        }
        answer.push_back(vec);
    }

    return answer;
}
int main()
{
    //vector<vector<int>> arr1 = { {1,4},{3,2},{4,1} };
    //vector<vector<int>> arr2 = { {3, 3} ,{3, 3} };
    //vector<vector<int>> arr1 = { {1,1},{2,2},{3,3} };
    //vector<vector<int>> arr2 = { {1,2,3,4},{1,2,3,4} };
    vector<vector<int>> arr1 = { {1} ,{2},{3},{4} };
	vector<vector<int>> arr2 = { {1,2,3,4} };


    vector<vector<int>> answer = solution(arr1, arr2);

    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[0].size(); j++)
        {
            cout << answer[i][j] << "  ";
        }
        cout << endl;
    }
}