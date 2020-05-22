//����
//K�� ���Ŀ� �а��縦 �ٽ� ���޹���
//�������� �ٸ��뼭 �����鼭 ���߾���
//�ּ� �ֹ����ؼ� K�������� ���߶�!

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
        if (stock >= k - day)   //������ ����
        {
            break;
        }
        if (day == dates[dates_idx])    //��³��̸�
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