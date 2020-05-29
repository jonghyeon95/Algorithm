//실패율 = 스테이지a 도달했으나 못깬사람 / a에 도달한 모든사람
//스테이지갯수 1 <= N <= 500
//stages배열 사용자들의 현재 스테이지
// 1 <= stages.size() <= 200000
// 1 <= stages[a] <= N+1
//return값 => 실패율높은 스테이지부터 출력, 실패율같으면 작은번호, 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(pair<double, int> a, pair<double, int> b)
{
    if (a.first > b.first)
        return true;
    else if (a.first < b.first)
        return false;
    else
        return a.second < b.second;
}
vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;
    vector<pair<int, int>> failAll(N + 2); //실패한사람, 도달한사람
    vector<pair<double, int>> fail_rate(N + 1); //실패율, 번호
    for (int i = 1; i <= stages.size(); i++)
    {
        int stg = stages[i - 1];
        for (int i = 1; i <= stg; i++)
        {
            failAll[i].second += 1;
            if (i == stg)
                failAll[i].first += 1;
        }
    }

    for (int i = 1; i < N+1; i++)
    {
        fail_rate[i - 1].first = (double)failAll[i].first / failAll[i].second;
        fail_rate[i - 1].second = i;
    }

    sort(fail_rate.begin(), fail_rate.end()-1, compare);

    for (int i = 0; i < N; i++)
    {
        //cout << fail_rate[i].first <<", "<< fail_rate[i].second << endl;
        answer.push_back(fail_rate[i].second);
    }
    return answer;
}

int main()
{
    int N = 4;
    //vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };
    vector<int> stages = { 4,4,4,4,4 };
    vector<int> result (N);

    result = solution(N, stages);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}