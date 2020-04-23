//문제
//0~9들어가는 배열(문자열) 있을때
//이를 조합해서 나오는 소수의 개수 찾기


//실패 포기
//한자리수만 있을때 못잡아냄
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

    ///////////////자릿값 만들기
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