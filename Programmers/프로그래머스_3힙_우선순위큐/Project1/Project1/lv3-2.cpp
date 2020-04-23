//����
//I ���� => �߰�
//D 1 => �ִ� ����
//D -1 => �ּڰ� ����
//��翬�� ���� �� [�ִ�, �ּڰ�] ���
//ť ������� [0, 0] ���
//ť ������� ���������� ����

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> solution(vector<string> operations) 
{
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    priority_queue<int, vector<int>, less<int>> max_pq;
    int max, min;
    int count = 0;

    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i][0] == 'I')    //������ �߰�
        {
            string str_num = operations[i].substr(2, operations[i].size());
            int num = atoi(str_num.c_str());
            min_pq.push(num);
            max_pq.push(num);
            count++;
        }
        else if (operations[i] == "D -1") //�ּڰ� ����
        {
            if (!min_pq.empty())
            {
                min_pq.pop();
                count--;
            }
        }
        else if (operations[i] == "D 1")    //�ִ� ����
        {
            if (!max_pq.empty())
            {
                max_pq.pop();
                count--;
            }
        }
        if (count == 0)
        {
            int max_size = max_pq.size();
            for (int i = 0; i < max_size; i++)
            {
                max_pq.pop();
            }
            int min_size = min_pq.size();
            for (int i = 0; i < min_size; i++)
            {
                min_pq.pop();
            }
        }
    }
    if (min_pq.empty())
    {
        max = min = 0;
    }
    else
    {
        max = max_pq.top();
        min = min_pq.top();
    }
    answer.push_back(max);
    answer.push_back(min);
    return answer;
}
int main()
{
    vector<string> operations{ "I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D -1", "D -1", "I 5", "I 6" };
    //vector<string> operations{ "I 7","I 5","I -5","D -1" };
    vector<int> answer = solution(operations);

    cout << answer[0] << ", " << answer[1];
}