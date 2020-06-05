//��õ��
//ũ�� m�� n �� 1<=  <=100
//. ��ĭ
//* ��
//���ĺ� �빮�ڴ� Ÿ��
//Ÿ�� ������ IMPOSSIBLE
//Ÿ�� ���� �ƴ¼������ ���ڿ����(���������ϰ�� ���ĺ�����)

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <math.h>
using namespace std;

//���ĺ� ��ġã��
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
    
    //���ĺ� ���� 
    set<char> set_board;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(board[i][j]>='A' && board[i][j] <= 'Z')
            set_board.insert(board[i][j]);
        }
    }

    //���ĺ� ����
    stack<char> sta;
    for (auto i = set_board.rbegin(); i != set_board.rend(); i++)
    {
        sta.push(*i);
    }

    //Ǯ��
    int roof = 0;
    stack<char> sta_sub;
    while (roof < set_board.size() || !sta.empty())
    {
        roof++;

        char target = sta.top();
        sta.pop();
        vector<pair<int, int>> point = find(board, target);

        int y_dis = point[0].first - point[1].first;    //�� ����
        int x_dis = point[0].second - point[1].second;  //�� ����

        int now_y = point[0].first;     //���� y��ǥ
        int now_x = point[0].second;    //���� x��ǥ

        bool y_suc = false;
        bool x_suc = false;
        bool x_start = true;
        bool y_start = false;
        bool suc = false;
        for (int t = 0; t < 2; t++)
        {
            if (x_suc == false && x_start == true) //�¿� Ȯ��
            {
                int sign = 1;
                if (x_dis > 0)  //ù��°�� �����ʿ� ���� ��
                    sign = -1;

                for (int x = 0; x <= abs(x_dis); x++)
                {
                    if (board[now_y][now_x + sign * x] == '.' || board[now_y][now_x + sign * x] == target)  //�̵��Ѱ��� ����ų�, ã�� ���ĺ� �� ��
                    {
                        if (x == abs(x_dis))    //���ϴ°����� �̵����� ��
                        {
                            now_x = point[1].second;
                            x_suc = true;
                        }
                    }
                    else  //�̵��Ѱ��� ���̰ų�, �ٸ� ���ĺ� �� ��
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
                        if (x_suc == true)  //x�������δ� ���������� y�������� ��������
                        {
                            x_suc = false;
                            x_start = false;    //y�������� ���� �����ϰ�, �ڿ� x�������� ����
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