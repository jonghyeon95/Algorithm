//집에서 학교가는길 m x n 임
//가장왼쪽위가 집, 오른쪽아래가 학교
//puddles는 물이잠긴 좌표임 (1,1 시작)	//0개 <= 물이잠긴위치 <=10개
//학교가는 최단경로 구하기


////dp
//#include <vector>
//#include <iostream>
//using namespace std;
//#define water -9999999
//int solution(int m, int n, vector<vector<int>> puddles)
//{
//    vector<vector<int>> map(n, vector<int>(m, 0));
//    int water_check = 1;
//    for (int i = 0; i < puddles.size(); i++)
//    {
//        map[puddles[i][1] - 1][puddles[i][0] - 1] = water;
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//
//        if (map[i][0] != water)
//            map[i][0] = water_check;
//        else
//            water_check = 0;
//    }
//    water_check = 1;
//    for (int j = 0; j < m; j++)
//    {
//        if (map[0][j] != water)
//            map[0][j] = water_check;
//        else
//            water_check = 0;
//    }
//
//
//    for (int i = 1; i < n; i++)
//    {
//        for (int j = 1; j < m; j++)
//        {
//            if (map[i][j] != water)
//            {
//                int ssum = 0;
//                if (map[i - 1][j] != water)
//                    ssum += map[i - 1][j];
//                if (map[i][j - 1] != water)
//                    ssum += map[i][j - 1];
//                map[i][j] = ssum % 1000000007;
//            }
//        }
//    }
//    return map[n - 1][m - 1];
//}
//int main()
//{
//    int m = 4;
//    int n = 3;
//    vector<vector<int>> puddles = { {2,2} };
//
//    cout << solution(m, n, puddles);
//}


////dfs 풀기 시간초과
//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//#define water -9999999
//int minval = 99999999;
//int answer = 0;
//void req(vector<vector<int>>& map, int i, int j)
//{
//    if (i == map.size() - 1 && j == map[0].size() - 1)
//    {
//        if (map[i][j] < minval)
//        {
//            minval = map[i][j];
//            answer = 1;
//        }
//        else if (map[i][j] == minval)
//        {
//            answer = (answer + 1) % 1000000007;
//        }
//        return;
//    }
//
//    int place = map[i][j];
//    if (place == water)
//        return;
//
//    if (i != map.size() - 1 && (map[i + 1][j] >= place + 1 || map[i + 1][j] == 0))
//    {
//        map[i + 1][j] = place + 1;
//        req(map, i + 1, j); //아래
//    }
//    
//    if (j != map[0].size() - 1 && (map[i][j + 1] >= place + 1 || map[i][j + 1] == 0))
//    {
//        map[i][j + 1] = place + 1;
//        req(map, i, j + 1); //오른쪽
//    }
//    return;
//}
//int solution(int m, int n, vector<vector<int>> puddles)
//{
//    vector<vector<int>> map(n, vector<int>(m, 0));
//
//    map[0][0] = water;
//    map[1][0] = 1;
//    map[0][1] = 1;
//
//    for (int i = 0; i < puddles.size(); i++)
//    {
//        map[puddles[i][1] - 1][puddles[i][0] - 1] = water;
//    }
//    req(map, 1, 0);
//    req(map, 0, 1);
//
//    return answer;
//}
//int main()
//{
//    int m = 4;
//    int n = 3;
//    vector<vector<int>> puddles = { {2,2} };
//
//    cout << solution(m, n, puddles);
//}




#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define water -9999999
int minval = 99999999;
int answer = 0;
void req(vector<vector<int>>& map, int i, int j)
{
    if (i == map.size() - 1 && j == map[0].size() - 1)
    {
        if (map[i][j] < minval)
        {
            minval = map[i][j];
            answer = 1;
        }
        else if (map[i][j] == minval)
        {
            answer = (answer + 1) % 1000000007;
        }
        return;
    }

    int place = map[i][j];
    if (place == water)
        return;

    if (i != 0 && (map[i - 1][j] >= place + 1 || map[i - 1][j] == 0))
    {
        map[i - 1][j] = place + 1;
        req(map, i - 1, j); //위
    }
    if (i != map.size() - 1 && (map[i + 1][j] >= place + 1 || map[i + 1][j] == 0))
    {
        map[i + 1][j] = place + 1;
        req(map, i + 1, j); //아래
    }
    if (j != 0 && (map[i][j - 1] >= place + 1 || map[i][j - 1] == 0))
	{
        map[i][j - 1] = place + 1;
		req(map, i, j - 1); //왼쪽
	}
	if (j != map[0].size() - 1 && (map[i][j + 1] >= place + 1 || map[i][j + 1] == 0))
	{
        map[i][j + 1] = place + 1;
		req(map, i, j + 1); //오른쪽
	}
    return;
}
int solution(int m, int n, vector<vector<int>> puddles) 
{
    vector<vector<int>> map (n, vector<int>(m,0));

    map[0][0] = water;
    map[1][0] = 1;
    map[0][1] = 1;

    for (int i = 0; i < puddles.size(); i++)
    {
        map[puddles[i][1] - 1][puddles[i][0] - 1] = water;
    }
    req(map, 1, 0);
    req(map, 0, 1);

    return answer;
}
int main()
{
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles = { {2,2} };

    cout << solution(m, n, puddles);
}