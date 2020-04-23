//문제
//숫자야구
//자리수,숫자 다맞음 strike
//숫자만 맞음 ball
//모두틀림 out
//배열[숫자3개, strike, ball]
//가능한 경우의 수 말하기

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;

    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            for (int k = 1; k <= 9; k++)
            {
                if (i == j || i == k || j == k)
                    continue;

                bool suc = true;
                for (int s = 0; s < baseball.size(); s++)
                {
                    int str = 0;
                    int ball = 0;
                    int ball_num[3];
                    ball_num[0] = baseball[s][0] / 100;
                    ball_num[1] = baseball[s][0] / 10 % 10;
                    ball_num[2] = baseball[s][0] % 10;
                    
                    if (i == ball_num[0])
                        str++;
                    if (j == ball_num[1])
                        str++;
                    if (k == ball_num[2])
                        str++;

                    if (ball_num[0] == j || ball_num[0] == k)
                        ball++;
                    if (ball_num[1] == i || ball_num[1] == k)
                        ball++;
                    if (ball_num[2] == i || ball_num[2] == j)
                        ball++;
                    
                    if (str == baseball[s][1] && ball == baseball[s][2])
                        suc = true;
                    else
                    {
                        suc = false;
                        break;
                    }
                }
                if (suc)
                    answer++;
            }
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> baseball = { {123, 1, 1},{356, 1, 0},{327, 2, 0},{489, 0, 1} };
    cout << solution(baseball);
}