//n개의 음이 아닌 정수가 있음
//이수를 적절히 더하거나 빼서 타켓의 수를 만드려함
//ex) 1,1,1,1,1 을 3으로 만드려면
//-1,+1,+1,+1,+1
//+1,-1,+1,+1,+1
//+1,+1,-1,+1,+1
//+1,+1,+1,-1,+1
//+1,+1,+1,+1,-1
//총 5개 방법이 있다

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int numsize;
int answer;
void dfs(int i, int sum, vector<int> numbers, int target)
{
    if (i == numsize)
    {
        if (sum == target)
            answer++;
        return;
    }
    dfs(i + 1, sum + numbers[i], numbers, target);
    dfs(i + 1, sum - numbers[i], numbers, target);
}
int solution(vector<int> numbers, int target) 
{
    answer = 0;
    numsize = numbers.size();
    
    dfs(0, 0, numbers, target);

    return answer;
}
int main()
{
    vector<int> numbers = { 1,1,1,1,1 };
    int target = 3;
    cout << solution(numbers, target);
}