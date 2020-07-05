#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int VerticalMax(vector<vector<int>> vec, int start, int end, int col)
{
	int maxval = 0;
	for (int i = start; i <= end; i++)
	{
		maxval = max(maxval, vec[i][col]);
	}

	return maxval;
}
int HorizonMax(vector<int> vec, int start, int end)
{
	int maxval = 0;
	for (int i = start; i <= end; i++)
	{
		maxval = max(maxval, vec[i]);
	}
	return maxval;
}
int solution(vector<vector<int>> heightMap)
{
	int answer = 0;
	for (int i = 1; i < heightMap.size() - 1; i++)
	{
		for (int j = 1; j < heightMap[0].size() - 1; j++)
		{
			int left = HorizonMax(heightMap[i], 0, j - 1);
			int right = HorizonMax(heightMap[i], j + 1, heightMap[0].size() - 1);
			int bottom = VerticalMax(heightMap, i + 1, heightMap.size() - 1, j);
			int top = VerticalMax(heightMap, 0, i - 1, j);

			int minval_h = min(left, right);
			int minval_v = min(top, bottom);
			int minval = min(minval_h, minval_v);

			int water = minval - heightMap[i][j];
			if (water > 0)
				answer += water;
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> heightMap;
	//heightMap = { {1,4,3,1,3,2} , {3,2,1,3,2,4}, {2,3,3,2,3,1 } };
	heightMap = { {12, 13, 1, 12},{13, 4, 13, 12},{13, 8, 10, 12},{12, 13, 12, 12},{13, 13, 13, 13} };

	cout << solution(heightMap);
}