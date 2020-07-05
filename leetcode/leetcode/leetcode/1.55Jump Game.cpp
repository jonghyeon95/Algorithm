//문제
//[ 1, 2, 3 ,4 , 5]
//시작부터 끝까지 가야함
//값이 점프할수있는 최대값
//갈수있냐 or 못가냐로 결과리턴

#include <iostream>
#include <vector>
using namespace std;

//bool canJump(vector<int>& nums)
//{
//	vector<bool> visit(nums.size(), false);
//	visit[0] = true;
//	for (int i = 0; i < nums.size() - 1; i++)
//	{
//		if (visit[i])
//		{
//			for (int j = 1; j <= nums[i]; j++)
//			{
//				if (i + j < nums.size())
//					visit[i + j] = true;
//			}
//		}
//	}
//
//	return visit[nums.size() - 1];
//}


bool answer = false;
bool fair = false;
void rec_jump(int target_idx, vector<int>& nums, int idx)
{
    if (nums[idx] >= target_idx - idx)
    {
        if (idx == 0)
            answer = true;
        for (int i = 0; i < idx; i++)
        {
            if (answer)
                break;
            if (fair)
                break;
            rec_jump(idx, nums, i);
        }
        fair = true;
    }
}
bool canJump(vector<int>& nums)
{
    int last_idx = nums.size() - 1;
    if (last_idx == 0)
    {
        return true;
    }
    for (int i = last_idx - 1; i >= 0; i--)
    {
        if (answer)
            break;
        rec_jump(last_idx, nums, i);
    }
    return answer;
}


//void rec_jump(int last_idx, vector<int>& nums, int idx)
//{
//	if (nums[idx] >= last_idx - idx)
//	{
//		for (int i = 1; i <= nums[idx]; i++)
//		{
//
//			if (idx == 0)
//			{
//				answer = true;
//				break;
//			}
//			if (answer)
//				break;
//			if (idx - i >= 0)
//			{
//				for (int i = idx - 1; i >= 0; i--)
//				{
//					if (answer)
//						break;
//					rec_jump(idx, nums, i);
//				}
//			}
//		}
//	}
//}
//
//bool canJump(vector<int>& nums) 
//{
//	int last_idx = nums.size() - 1;
//	if (last_idx == 0)
//	{
//		return true;
//	}
//	for (int i = last_idx - 1; i >= 0; i--)
//	{
//		if (answer)
//			break;
//		rec_jump(last_idx, nums, i);
//	}
//	return answer;
//}
int main()
{
	//int N;
	//cin >> N;
	//vector<int> nums{ 2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6 };
	//vector<int> nums = { 3,2,1,0,4 };
	vector<int> nums = { 2,3,1,1,4 };

	//for (int i = 0; i < N; i++)
	//{
	//	int k;
	//	cin >> k;
	//	nums.push_back(k);
	//}
	cout << canJump(nums);
}