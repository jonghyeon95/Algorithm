//0<= 캐시 크기 <= 30
//도시이름배열 <=100000
//캐시 배열안에 도시가 있으면 1초
//캐시 배열안에 도시가 없으면 5초
//캐시의 크기만큼 캐시배열안에 저장
//안쓴지 오래될수록 사라지는 우선순위 높아짐

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) 
{
    int answer = 0;

    stack<string> stck1;
    stack<string> stck2;

    if (cacheSize == 0)
    {
        return 5 * cities.size();
    }

    //for (int i = 0; i < cities.size(); i++)
    //{
    //    transform(cities[i].begin(), cities[i].end(), cities[i].begin(), tolower);
    //}

    for (int i = 0; i < cities.size(); i++)
    {
        for (int j = 0; j < cities[i].length(); j++)
        {
            if (cities[i][j] <= 'Z')
                cities[i][j] = cities[i][j] + 'a'-'A';
        }
    }

    stck1.push(cities[0]);
    answer += 5;

    for (int i = 1; i < cities.size(); i++)
    {
        string str = cities[i];
        for (int j = 0; j < cacheSize; j++)
        {
            string pop = stck1.top();
            stck1.pop();
            if (pop == str)
            {
                while (!stck2.empty())
                {
                    stck1.push(stck2.top());
                    stck2.pop();
                }
                stck1.push(str);
                answer += 1;
                break;
            }
            else
            {
                stck2.push(pop);
            }

            if (stck2.size() == cacheSize)
            {
                stck2.pop();
                for (int k = 0; k < cacheSize - 1; k++)
                {
                    stck1.push(stck2.top());
                    stck2.pop();
                }
                stck1.push(str);
                answer += 5;
                break;
            }
            if (stck1.empty())
            {
                while (!stck2.empty())
                {
                    stck1.push(stck2.top());
                    stck2.pop();
                }
                stck1.push(str);
                answer += 5;
                break;
            }
        }
    }
    return answer;
}
int main()
{
    int cacheSize = 0;
    //vector<string> cities = { "jeju", "pangyo", "newyork", "anyang", "jeju", "Anyang"}; //26
    vector<string> cities = { "a","b","c","d" }; //20

    cout << solution(cacheSize ,cities);
}