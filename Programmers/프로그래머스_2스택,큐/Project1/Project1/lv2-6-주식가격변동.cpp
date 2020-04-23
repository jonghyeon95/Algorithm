//문제
//초단위로 기록된 주식가격이 담긴배열있음
//각 값마다 안떨어지는 기간을 각각 구하시오



//답지 스택 이해못함..
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();
    for (int i = 0; i < size; i++) {
        while (!s.empty() && prices[s.top()] > prices[i]) {
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        answer[s.top()] = size - s.top() - 1;
        s.pop();
    }
    return answer;
}
int main()
{
    vector<int> prices{ 1,2,3,2,3 };
    vector<int> answer = solution(prices);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
}





////백터로풀기
//#include <iostream>
//#include <string>
//#include <vector>
//#include <stack>
//using namespace std;
//
//vector<int> solution(vector<int> prices) {
//    vector<int> answer;
//
//    for (int i = 0; i < prices.size() - 1; i++)
//    {
//        int count = 0;
//        for (int j = i + 1; j < prices.size(); j++)
//        {
//            count++;
//            if (prices[i] > prices[j])  //값이 더 싸짐
//            {
//                break;
//            }
//        }
//        answer.push_back(count);
//    }
//    answer.push_back(0);
//
//    return answer;
//}
//int main()
//{
//    vector<int> prices { 1,2,3,2,3 };
//    vector<int> answer = solution(prices);
//    
//    for (int i = 0; i < answer.size(); i++)
//    {
//        cout << answer[i] << endl;
//    }
//}