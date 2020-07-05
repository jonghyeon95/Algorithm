#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

vector<vector<int>> dfs;
void findfunc(vector<int>& vec, vector<bool> check, int row, vector<int> numvec)
{
    check[row] = true;
    numvec.push_back(vec[row]);

    if (numvec.size() == vec.size())
    {
        dfs.push_back(numvec);
        return;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        if (check[i] == false)
            findfunc(vec, check, i, numvec);
    }
}
int getabs(vector<int> vec)
{
    int sum = 0;

    for (int i = 0; i < vec.size()-1; i++)
    {
        sum += abs(vec[i] - vec[i + 1]);
    }

    return sum;
}
int solution(vector<int> v)
{
    int max_sum = 0;

    vector<bool> check(v.size(), false);
    vector<int> numvec;
    for (int i = 0; i < v.size(); i++)
    {
        findfunc(v, check, i, numvec);
    }

    for (int i = 0; i < dfs.size(); i++)
    {
        max_sum = max(max_sum,getabs(dfs[i]));
    }

    return max_sum;
}
int main()
{
    vector<int> v = { 20,8,10,1,4,15 };
    cout << solution(v);

	return 0;
}