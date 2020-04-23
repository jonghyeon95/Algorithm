//문제
//배열인덱스는 논문의 고유번호
//배열값은 자신의 논문이 인용된 횟수
//이 때 최대인용된 횟수???


//내가 품
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for (int i = 1; i <= citations.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < citations.size(); j++)
        {
            if (i <= citations[j])
            {
                count++;
            }
        }
        if (count >= i)
            answer = i;
    }
    return answer;
}
int main()
{
    //vector<int> citations = { 5,5,5,5 };
    vector<int> citations = { 3,0,6,1,5 };
    cout << solution(citations);
}

