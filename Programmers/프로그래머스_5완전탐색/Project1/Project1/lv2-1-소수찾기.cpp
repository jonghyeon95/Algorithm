//����
//0~9���� �迭(���ڿ�) ������
//�̸� �����ؼ� ������ �Ҽ��� ���� ã��


//���� ����
//���ڸ����� ������ ����Ƴ�
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

void findsosoo(string max, vector<int>& sosoo)
{
    for (int i = 2; i <= atoi(max.c_str()); i++)
    {
        int t = 2;
        while (i != t)
        {
            if (i % t == 0)
            {
                break;
            }
            else
                t++;
        }
        if (i == t)
        {
            sosoo.push_back(i);
        }
    }
}
bool compare(string a, string b)
{
    return a > b;
}
int solution(string numbers) 
{
    int answer = 0;
    vector<string> nums;
    vector<int> sosoo;
    string max;
    vector<string> sosoo_vec;
    
    for (int i = 0; i < numbers.size(); i++)
    {
        nums.push_back(numbers.substr(i, 1));
    }
    sort(nums.begin(), nums.end(), compare);
    for (int i = 0; i < nums.size(); i++)
    {
        max += nums[i];
    }
    findsosoo(max, sosoo);

    ///////////////�ڸ��� �����
    priority_queue<string> pq;
    for (int i = 0; i < sosoo.size(); i++)
    {
        string str = to_string(sosoo[i]);
        string change_str;
        for (int j = 0; j < str.size(); j++)
        {
            pq.push(str.substr(j, 1));
        }
        
        for (int i = pq.size(); i < numbers.length(); i++)
        {
            pq.push("0");
        }

        for (int j = 0; !pq.empty(); j++)
        {
            change_str += pq.top();
            pq.pop();
        }
        sosoo_vec.push_back(change_str);
    }

    string str;
    for (int i = 0; i < nums.size(); i++)
    {
        str += nums[i];
    }

    for (int i = 0; i < sosoo_vec.size(); i++)
    {
        if (str.compare(sosoo_vec[i]) == 0)
        {
            answer++;
        }
    }

    return answer;
}
int main()
{
    string numbers = "011";
    cout << solution(numbers);
}