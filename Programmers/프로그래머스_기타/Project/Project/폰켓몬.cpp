//N���� ���ϸ��� N/2���� ������ �� ����
//���ϸ� Ÿ�Կ� ���� ���ںο�
//�������ִ� �ִ� Ÿ���� ������?
//N<=10000
//���ϸ� ���� <=200,000

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

