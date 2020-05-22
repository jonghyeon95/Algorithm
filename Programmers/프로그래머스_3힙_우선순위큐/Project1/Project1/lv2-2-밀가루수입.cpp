//문제
//K일 이후에 밀가루를 다시 공급받음
//그전까지 다른대서 받으면서 버텨야함
//최소 주문을해서 K전날까지 버텨라!

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int solution(int stock, vector<int> dates, vector<int> supplies, int k)
{
    int answer = 0;
    int day = 0;
    int dates_idx = 0;
    priority_queue<int, int, less> sup_pq;

    for (day; day < k; day++)
    {
        if (stock >= k - day)   //나가는 조건
        {
            break;
        }
        if (day == dates[dates_idx])    //사는날이면
        {
            sup_pq.push(supplies[dates_idx]);
            if (dates_idx < dates.size() - 1)
                dates_idx++;
        }
        if (stock == 0)
        {
            stock += sup_pq.top();
            sup_pq.pop();
            answer++;
        }
        stock--;
    }
    return answer;
}
int main()
{
    int stock = 4;
    vector<int> dates = { 4, 10, 15 };
    vector<int> supplies = { 20, 5, 10 };
    int k = 30;

    cout << solution(stock, dates, supplies, k);
}