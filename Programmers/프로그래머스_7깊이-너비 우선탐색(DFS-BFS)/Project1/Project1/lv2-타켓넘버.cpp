//n���� ���� �ƴ� ������ ����
//�̼��� ������ ���ϰų� ���� Ÿ���� ���� �������
//ex) 1,1,1,1,1 �� 3���� �������
//-1,+1,+1,+1,+1
//+1,-1,+1,+1,+1
//+1,+1,-1,+1,+1
//+1,+1,+1,-1,+1
//+1,+1,+1,+1,-1
//�� 5�� ����� �ִ�

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