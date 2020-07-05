#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> weight) 
{
    int answer = 1;
    int sum = 0;
    int i = 0;
    sort(weight.begin(), weight.end());

    while (true)
    {
        if (i < weight.size())
            sum += weight[i];
        else
            return answer;

        if (answer < weight[i])
            return answer;

        answer += weight[i];
        i++;
    }
}
int main()
{
    vector<int> weight = { 3,1,6,2,7,30,1 };
    cout << solution(weight);
}