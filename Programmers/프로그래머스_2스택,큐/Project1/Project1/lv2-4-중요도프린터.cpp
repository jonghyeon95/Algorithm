//���� ť
//�����ʹ� �տ��� ���� ����
//�տ��� �������µ� �߿䵵�� �� ������������ ���ϵڷΰ���
//�������ϴ°� ���� �������� �����Ͻÿ�


//���� ǰ queue���
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
    queue<pair<int, int>> priorite_que;   //�ε�����ȣ, �߿䵵
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
