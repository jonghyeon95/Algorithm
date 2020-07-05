//자연수 n이랑 s가 주어짐
//자연수 n개의 합을 s로 만듬
//자연수 n개의 곱이 가장 큰 값은?

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, int s)
{
    if (n > s)
        return vector<int> {-1};

    vector<int> answer;

    int nam = s % n;
    for (int i = 0; i < n; i++)
    {
        answer.push_back(s / n);
    }
    for (int i = 0; i < nam; i++)
    {
        answer[n - 1 - i] += 1;
    }

    return answer;
}

int main()
{
    int n = 2;
    int s = 9;
    vector<int> answer = solution(n, s);

    for (int i : answer)
    {
        cout << i << " ";
    }
}