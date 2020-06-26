//문제
//정수형 arr이 있을때 이 수들의 최소 공배수를 반환하라

#include <string>
#include <vector>
#include <iostream>
using namespace std;
int LCM(int a, int b)
{
    vector<int> vec;
    int max;
    int min;
    int result = 1;
    if (a >= b)
    {
        max = a;
        min = b;
    }
    else
    {
        max = b;
        min = a;
    }

    int i = 2;
    while (min >= i)
    {
        if (min % i == 0 && max % i == 0)
        {
            min /= i;
            max /= i;
            vec.push_back(i);
        }
        else
        {
            i++;
        }
    }

    for (int j = 0; j < vec.size(); j++)
    {
        result *= vec[j];
    }
    result *= max * min;
    return result;
}
int solution(vector<int> arr) 
{
    int answer = 1;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        answer = LCM(arr[i], arr[i + 1]);
        arr[i + 1] = answer;
    }

    return answer;
}
int main()
{
    vector<int> arr = { 2, 6, 8, 14};
    cout << solution(arr);
}