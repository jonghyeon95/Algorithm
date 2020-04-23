//문제 큐
//프린터는 앞에께 먼저 나옴
//앞에꺼 나오려는데 중요도가 더 높은게있으면 제일뒤로가짐
//내가원하는게 언제 나오는지 리턴하시오


//내가 품 queue사용
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool prioiteSort(int a, int b)
{
    return b < a;
}
int solution(vector<int> priorities, int location) {
    int answer = 0;
    int out_idx = -1;
    queue<pair<int, int>> priorite_que;   //인덱스번호, 중요도
    for (int i = 0; i < priorities.size(); i++)
    {
        priorite_que.push(make_pair(i, priorities[i]));
    }
    sort(priorities.begin(), priorities.end(), prioiteSort);
    
    while (out_idx != location)
    {
        pair<int, int> temp;
        temp = priorite_que.front();
        priorite_que.pop();
        if(temp.second == priorities[answer])
        {
            answer++;
            out_idx = temp.first;
        }
        else
        {
            priorite_que.push(temp);
        }
    }

    return answer;
}
int main()
{
    vector<int> priorities { 2, 1, 3, 2 };
    int location = 2;

    cout << solution(priorities, location) << endl;
}
