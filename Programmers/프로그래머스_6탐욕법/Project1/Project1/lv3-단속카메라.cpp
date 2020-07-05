//��ӵ��� ��������� �ܼӿ�ī�޶� �ѹ��� ������ �Ҷ�
//�ּ� ��� ī�޶� ��ġ�ؾ� �ϴ°�
//1<=����<=10000
//�迭 [a,b] a=��������, b=�������� -30000<=a,b<=30000

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
	int point = routes[0][1];

    for (int i = 1; i < routes.size() - 1; i++)
    {
        if (routes[i][1] < point)
        {
            point = routes[i][1];
        }
        if (routes[i + 1][0] > point)
        {
            point = routes[i + 1][1];
            answer++;
        }
    }

    return answer;
}
int main()
{
    vector<vector<int>> routes = { {-20,15},{-14,-5},{-18,-13},{-5,-3} };
	//vector<vector<int>> routes = { {1,2},{3,4},{6,7},{9,10} };

    cout << solution(routes);
}