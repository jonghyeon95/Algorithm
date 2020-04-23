//문제
//배열에 정수가 담겨져있음
//정수들의 위치를 재배치하여 가장큰 수를 출력


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool numberCompare(string a, string b)
{
    return a + b > b + a;
}
string solution(vector<int> numbers) 
{
    string answer = "";
    vector<string> num_vec;
    for (int i = 0; i < numbers.size(); i++)
    {
        num_vec.push_back(to_string(numbers[i]));
    }
    sort(num_vec.begin(), num_vec.end(), numberCompare);
    for (int i = 0; i < numbers.size(); i++)
    {
        answer += num_vec[i];
    }
    if (answer[0] == '0')
        return "0";
    return answer;
}
int main()
{
    //vector<int> numbers = {0,1000,0,0};
    vector<int> numbers = { 3, 30, 34, 5, 9 };
    cout << solution(numbers);
}