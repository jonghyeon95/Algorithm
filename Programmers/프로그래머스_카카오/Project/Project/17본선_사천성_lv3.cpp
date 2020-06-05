//사천성
//크기 m행 n 열 1<=  <=100
//. 빈칸
//* 벽
//알파벳 대문자는 타일
//타일 못깨면 IMPOSSIBLE
//타일 깨면 꺠는순서대로 문자열출력(여러가지일경우 알파벳순서)

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <math.h>
using namespace std;

//알파벳 위치찾기
vector<pair<int, int>> find(vector<string> board, char target)
{
    vector<pair<int, int>> ans;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == target)
                ans.push_back(make_pair(i, j));
        }
        if (ans.size() == 2)
            return ans;
    }
}

string solution(int m, int n, vector<string> board) {
    string answer = "";
    
    //알파벳 종류 
    set<char> set_board;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(board[i][j]>='A' && board[i][j] <= 'Z')
            set_board.insert(board[i][j]);
        }
    }

    //알파벳 정렬
    stack<char> sta;
    for (auto i = set_board.rbegin(); i != set_board.rend(); i++)
    {
        sta.push(*i);
    }

    //풀이
    int roof = 0;
    stack<char> sta_sub;
    while (roof < set_board.size() || !sta.empty())
    {
        roof++;

        char target = sta.top();
        sta.pop();
        vector<pair<int, int>> point = find(board, target);

        int y_dis = point[0].first - point[1].first;    //행 차이
        int x_dis = point[0].second - point[1].second;  //열 차이

        int now_y = point[0].first;     //현재 y좌표
        int now_x = point[0].second;    //현재 x좌표

        bool y_suc = false;
        bool x_suc = false;
        bool x_start = true;
        bool y_start = false;
        bool suc = false;
        for (int t = 0; t < 2; t++)
        {
            if (x_suc == false && x_start == true) //좌우 확인
            {
                int sign = 1;
                if (x_dis > 0)  //첫번째가 오른쪽에 있을 때
                    sign = -1;

                for (int x = 0; x <= abs(x_dis); x++)
                {
                    if (board[now_y][now_x + sign * x] == '.' || board[now_y][now_x + sign * x] == target)  //이동한곳이 비었거나, 찾는 알파벳 일 때
                    {
                        if (x == abs(x_dis))    //원하는곳까지 이동했을 때
                        {
                            now_x = point[1].second;
                            x_suc = true;
                        }
                    }
                    else  //이동한곳이 벽이거나, 다른 알파벳 일 때
                    {
                        break;
                    }
                }
                y_start = true;
            }

            if (y_suc == false && y_start == true)
            {
                for (int y = 0; y <= abs(y_dis); y++)
                {
                    if (board[now_y + y][now_x] == '.' || board[now_y + y][now_x] == target)
                    {
                        if (y == abs(y_dis))
                        {
                            now_y = point[1].first;
                            y_suc = true;
                            x_start = true;
                            y_start = false;
                        }
                    }
                    else
                    {
                        if (x_suc == true)  //x방향으로는 문제없으나 y방향으로 문제있음
                        {
                            x_suc = false;
                            x_start = false;    //y방향으로 먼저 시작하고, 뒤에 x방향으로 시작
                            now_x = point[0].second;
                            t--;
                        }
                        break;
                    }
                }
            }

            if (x_suc == true && y_suc == true)
            {
                suc = true;
                break;
            }
        }

        if (suc)
        {
            board[point[0].first][point[0].second] = '.';
            board[point[1].first][point[1].second] = '.';
            while (!sta_sub.empty())
            {
                sta.push(sta_sub.top());
                sta_sub.pop();
            }
            answer += target;
            roof = answer.length();
        }
        else
        {
            sta_sub.push(target);
        }
    }
    if (answer.length() != set_board.size())
        answer = "IMPOSSIBLE";
    return answer;
}

int main()
{
    int m = 2;
    int n = 2;
    //vector<string> board = { "DBA", "C*A", "CDB" };
    //vector<string> board = { "NRYN", "ARYA"};
    //vector<string> board = { ".ZI.", "M.**","MZU.",".I.U" };
    vector<string> board = { "AB","BA"};
    //vector<string> board = { "..",".." };

    cout << solution(m, n, board);
}