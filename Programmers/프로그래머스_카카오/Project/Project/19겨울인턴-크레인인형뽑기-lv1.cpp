//����
//ũ������ NxN �迭�� ������ ����
//N��° ������ ������ �뿡 �������� ����
//�뿡 ���������� �������� ������ ����, �� ��� ������ ������?

#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;

    for (int i = 0; i < moves.size(); i++)
    {
        int line = moves[i] - 1;
        int pick = 0;

        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[j][line] != 0)
            {
                pick = board[j][line];
                board[j][line] = 0;
                break;
            }
        }

        if (pick != 0)
        {
            if (!st.empty())
            {
                int past = st.top();
                if (past == pick)
                {
                    st.pop();
                    answer += 2;
                }
                else
                {
                    st.push(pick);
                }
            }
            else
            {
                st.push(pick);
            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> board = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
    vector<int> moves = { 1,5,3,5,1,2,1,4 };

    cout << solution(board, moves);
}