//배열에서 세숫자를 더해서 소수가 나오는것을 구하라
// 1<=배열의 값<=1000
// 소수의 최대값 = 3000
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> sosoo(3001, true);
void getsosoo(int max)
{
    for (int i = 2; i <= sqrt(max); i++)
    {
        if (sosoo[i] == false)
            continue;
        for (int j = i; i * j <= max; j++)
        {
            sosoo[i * j] = false;
        }
    }
}
int solution(vector<int> nums) {
    int answer = 0;
    vector<int> k;
    getsosoo(3000);
    int a, b, c;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (sosoo[nums[i] + nums[j] + nums[k]])
                    answer++;
            }
        }
    }
    return answer;
}

int main()
{
    vector<int> nums = { 1,2,7,6,4 };
    cout << solution(nums);
}