//문제
//1과 0으로 채워진 표가 있음
//1로 이루어진 가장 큰 정사각형을 찾아 넓이 return 하는 함수
//행열 크기 <=1000



//시간초과 and 몇개안됨
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;

    int max_i = board.size();
    int max_j = board[0].size();

    for (int i = 1; i < max_i; i++)
    {
        for (int j = 1; j < max_j; j++)
        {
            if (board[i][j] != 0 && board[i - 1][j] != 0 && board[i][j - 1] != 0 && board[i - 1][j - 1] != 0)
            {
                int minval = min(board[i - 1][j], board[i-1][j-1]);
                minval = min(minval, board[i][j - 1]);
                board[i][j] = minval + 1;
            }
        }
    }
   
    for (int i = 0; i < max_i; i++)
    {
        for (int j = 0; j < max_j; j++)
        {
            answer = max(answer, board[i][j]);
        }
    }

    return answer * answer;
}
int main()
{
    vector<vector<int>> board = { {0, 1, 1, 1},{1, 1, 1, 1},{1, 1, 1, 1},{0, 0, 1, 0 } };
    //vector<vector<int>> board = { {0, 0, 1, 1},{1, 1, 1, 1} };
    //vector<vector<int>> board = { {0,0} };
    //vector<vector<int>> board = { {1, 1, 1, 1},{1, 1, 1, 1},{1, 1, 1, 1},{1, 1, 1, 1},{1, 1, 1, 1}, {1, 1, 1, 1} };



    cout << solution(board);
}



////시간초과 and 몇개안됨
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int sq_area(int a, int b, vector<vector<int>>& board)
//{
//    int max_area = 1;
//    int max_i = board.size();
//    int max_j = board[0].size();
//    int i = a;
//    int j = b;
//    bool suc = true;
//    while (suc)
//    {
//        if (i+1 < max_i && j+1 < max_j && board[i][j + 1] == 1 && board[i + 1][j] == 1)
//        {
//            i++;
//            j++;
//            for (int ii = a+1; ii <= i; ii++)
//            {
//                if (board[ii][j] != 1)
//                {
//                    suc = false;
//                    break;
//                }
//            }
//            if (suc)
//            {
//                for (int jj = b + 1; jj <= j; jj++)
//                {
//                    if (board[i][jj] != 1)
//                    {
//                        suc = false;
//                        break;
//                    }
//                }
//            }
//        }
//        else
//            break;
//
//        if (suc)
//        {
//            max_area = (i - a + 1) * (i - a + 1);
//        }
//    }
//    return max_area;
//}
//
//int solution(vector<vector<int>> board)
//{
//    int answer = 0;
//
//    for (int i = 0; i < board.size(); i++)
//    {
//        for (int j = 0; j < board[0].size(); j++)
//        {
//            if (board[i][j] != 0)
//            {
//                int area = sq_area(i, j, board);
//                answer = answer <= area ? area : answer;
//            }
//        }
//    }
//    return answer;
//}
//int main()
//{
//    //vector<vector<int>> board = { {0, 1, 1, 1},{1, 1, 1, 1},{1, 1, 1, 1},{0, 0, 1, 0 } };
//    //vector<vector<int>> board = { {0, 0, 1, 1},{1, 1, 1, 1} };
//    //vector<vector<int>> board = { {0,0} };
//    //vector<vector<int>> board = { {1, 1, 1, 1},{1, 1, 1, 1},{1, 1, 1, 1},{1, 1, 1, 1},{1, 1, 1, 1}, {1, 1, 1, 1} };
//    vector<vector<int>> board = { {0,1,0} ,{1,1,1},{0,1,1} };
//
//
//
//    cout << solution(board);
//}