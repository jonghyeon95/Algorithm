//문제
//n개의 섬에 다리를 건설하는 최소화 비용을 리턴
//AB가 BC가 연결되면 AC도 연결 된거
//크루스칼 알고리즘

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(vector<int> a, vector<int> b)
{
    if (a[2] < b[2])
        return true;
    else
        return false;
}
int getParent(vector<int>& parent, int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(vector<int>& parent, int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}
int solution(int n, vector<vector<int>> costs) 
{
    int answer = 0;

    sort(costs.begin(), costs.end(), compare);

    vector<int> parent(n);
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
    }
    int count = 0;

    for (int i = 0; i < costs.size(); i++)
    {
        int f = costs[i][0];
        int s = costs[i][1];

        if (getParent(parent,f) != getParent(parent, s))
        {
            unionParent(parent, f, s);
            count++;
            answer += costs[i][2];
        }

        if (count == n - 1)
            break;
    }
    return answer;
}

int main()
{
    vector<vector<int>> costs;
    int n;  //다리의 갯수

    n = 7;
    //costs = { {0,6,12},{0,3,28},{0,1,67},{0,4,17},{1,3,24},{1,4,62},
    //    {2,4,20}, {2,5,37},{3,6,13},{4,5,45},{4,6,73} };

    //n = 6;
    //costs = { {0,1,5},{0,2,4},{1,2,2},{1,3,7},{2,3,6},{2,4,11},{3,4,3},{3,5,8},{4,5,8} };

    n = 5;
    costs = { {0,1,1},{3,1,1},{0,2,2},{0,3,2},{0,4,100} };
    cout << solution(n, costs);
}





//#define INF 9999999
//bool compare(vector<int> a, vector<int> b)
//{
//    if (a[2] < b[2])
//        return true;
//    else
//        return false;
//}
//int solution(int n, vector<vector<int>> costs) 
//{
//    int answer = 0;
//
//    sort(costs.begin(), costs.end(), compare);
//
//    vector<int> parents(n, INF);
//    vector<int> link(n);
//    for (int i = 0; i < link.size(); i++)
//    {
//        link[i] = i;
//    }
//    int count = 0;
//
//    for (int i = 0; i < costs.size(); i++)
//    {
//        int f = costs[i][0];
//        int s = costs[i][1];
//
//        if (parents[f] == INF && parents[s] == INF)
//        {
//            int min_ = min(link[f], link[s]);
//            parents[f] = min_;
//            parents[s] = min_;
//            link[f] = min_;
//            link[s] = min_;
//        }
//        else if (parents[f] == parents[s])
//        {
//            continue;
//        }
//        else if(parents[f]==INF && parents[s]!=INF)
//        {
//            int parent = parents[s];
//            parents[f] = parent;
//            link[f] = parent;
//        }
//        else if (parents[f] != INF && parents[s] == INF)
//        {
//            int parent = parents[f];
//            parents[s] = parent;
//            link[s] = parent;
//        }
//        else if (parents[f] != INF && parents[s] != INF)
//        {
//            int max_ = max(parents[f], parents[s]);
//            int min_ = min(parents[f], parents[s]);
//            for (int j = 0; j < parents.size(); j++)
//            {
//                if (parents[j] == max_)
//                {
//                    parents[j] = min_;
//                    link[j] = min_;
//                }
//            }
//        }
//        count++;
//        answer += costs[i][2];
//
//        if (count == n - 1)
//            break;
//    }
//    return answer;
//}
//
//int main()
//{
//    vector<vector<int>> costs;
//    int n;  //다리의 갯수
//
//    //n = 7;
//    //costs = { {0,6,12},{0,3,28},{0,1,67},{0,4,17},{1,3,24},{1,4,62},
//    //    {2,4,20}, {2,5,37},{3,6,13},{4,5,45},{4,6,73} };
//
//    n = 6;
//    costs = { {0,1,5},{0,2,4},{1,2,2},{1,3,7},{2,3,6},{2,4,11},{3,4,3},{3,5,8},{4,5,8} };
//
//    cout << solution(n, costs);
//}




////합집합
//int getParent(int* parent, int x)
//{
//	if (parent[x] == x)
//		return x;
//	return getParent(parent, parent[x]);
//}
//
//void unionParent(int* parent, int a, int b)
//{
//	a = getParent(parent, a);
//	b = getParent(parent, b);
//
//	if (a < b)
//		parent[b] = a;
//	else
//		parent[a] = b;
//}
//
//int findParent(int* parent, int a, int b)
//{
//	if (parent[a] == parent[b])
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	int parent[9];
//	for (int i = 1; i <= 8; i++)
//	{
//		parent[i] = i;
//	}
//
//	unionParent(parent, 1, 2);
//	unionParent(parent, 2, 3);
//	unionParent(parent, 3, 4);
//	unionParent(parent, 5, 6);
//	unionParent(parent, 6, 7);
//	unionParent(parent, 7, 8);
//
//	unionParent(parent,1, 8);
//
//	for (int i = 1; i <= 8; i++)
//	{
//		cout << getParent(parent, i) << endl;
//	}
//}