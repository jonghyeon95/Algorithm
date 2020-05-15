//N마리 포켓몬중 N/2마리 가져갈 수 있음
//포켓몬 타입에 따라 숫자부여
//가질수있는 최대 타입의 갯수는?
//N<=10000
//포켓몬 종류 <=200,000

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int select_cnt = nums.size() / 2;
    set<int> set_pock;
    for (int i = 0; i < nums.size(); i++)
    {
        set_pock.insert(nums[i]);
    }

	answer = select_cnt > set_pock.size() ? set_pock.size() : select_cnt;
    return answer;
}
int main()
{
    vector<int> nums = { 3,3, 3, 2, 2, 4 };
    cout << solution(nums);
}

