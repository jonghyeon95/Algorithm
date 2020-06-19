//문제
//구명보트에 최대 2명탑승가능
//구명보트 무게제한 있음
//보트 최소몇개필요할까?

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(int a, int b)
{
    return a > b;
}
int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end(), compare);
    int start = 0;
    int last = people.size() - 1;
    while (start < last)
    {
        if (people[start] + people[last] <= limit)
        {
            start++;
            last--;
            answer++;
        }
        else
        {
            start++;
            answer++;
        }
        if (start == last)
        {
            start++;
            answer++;
        }
    }
    return answer;
}
int main()
{
    vector<int> people = { 70,80,50 };
    int limit = 100;

    cout << solution(people, limit);
}




////시간초과
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int solution(vector<int> people, int limit) 
//{
//    int answer = 0;
//    sort(people.begin(), people.end());
//
//    while (people.size() != 0)
//    {
//        int lastidx = people.size() - 1;
//
//        while (true)
//        {
//            if (lastidx != 0)
//            {
//                if (people[0] + people[lastidx] <= limit)
//                {
//                    people.erase(people.begin() + lastidx);
//                    people.erase(people.begin());
//                    answer++;
//                    break;
//                }
//                else if (people[0] + people[lastidx] > limit)
//                {
//                    lastidx--;
//                }
//            }
//            if (lastidx == 0)
//            {
//                people.erase(people.begin());
//                answer++;
//                break;
//            }
//        }
//    }
//    return answer;
//}
//int main()
//{
//    vector<int> people = { 70,50,80,50 };
//    int limit = 100;
//
//    cout << solution(people, limit);
//}