//문제 
//computers[i][j] 가 1이면 i와 j가 연결되어 있다는 뜻
//0이면 연결 안됨
//총 네트워크 갯수는?
//컴퓨터갯수 <= 200

#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool visit[200];

void dfs(int i, int n, vector<vector<int>>& computers)
{
    visit[i] = true;
    for (int j = 0; j < n; j++)
    {
        if (!visit[j] && computers[i][j] == 1)
        {
            dfs(j, n, computers);
        }
    }
}
int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (visit[i] == false)
        {
            answer++;
            dfs(i, n, computers);
        }
    }

    return answer;
}
int main()
{
    int n = 3;
    vector<vector<int>> computers = { {1,1,0},{1,1,0},{0,0,1} };

    cout << solution(n, computers);
}
