//���� array�� �־���
//commads�� {i, j, k} �϶� 
//array���� i,j��°���� �ڸ��迭�� �����ؼ� k��° ���� ������


//�켱���� ť ǰ
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int j = commands[i][0] - 1; j <= commands[i][1] - 1; j++)
        {
            pq.push(array[j]);
        }
        for (int j = 0; j < commands[i][2]-1; j++)
        {
            pq.pop();
        }
        answer.push_back(pq.top());
    }
    return answer;
}
int main()
{
    vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> commands = { {2, 5, 3},{4, 4, 1},{1, 7, 3 } };
    vector<int> answer = solution(array, commands);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << "  ";
            
    }
}