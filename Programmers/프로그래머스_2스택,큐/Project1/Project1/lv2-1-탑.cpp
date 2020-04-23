//문제   스택
//배열이 있을때 왼쪽으로 빛이 나가는데 자신의 값보다 큰 값한테 빛이 전달됨
//몇번한테 보냈는지 저장한 배열을 작성

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;

    for (int i = heights.size()-1; i > 0; i--)
    {
        int reach = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (heights[i] < heights[j])
            {
                reach = j + 1;
                break;
            }
        }
        answer.push_back(reach);
    }
    answer.push_back(0);

    reverse(answer.begin(), answer.end());

    return answer;
}
int main()
{
    vector<int> heights{ 1, 5, 3, 6, 7, 6, 5 };

    vector<int> answer = solution(heights);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << "  ";
    }
}