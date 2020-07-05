#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool checkSqure(vector<vector<int>>& map, int i, int j)
{
	if (map[i - 1][j - 1] == 0) //11시
		return false;
    if (map[i - 1][j] == 0) //12시
		return false;
	if (map[i - 1][j + 1] == 0) //1시
		return false;
	if (map[i][j + 1] == 0) //3시
		return false;
	if (map[i + 1][j + 1] == 0) //5시
		return false;
    if (map[i + 1][j] == 0) //6시
		return false;
	if (map[i + 1][j - 1] == 0) //7시
		return false;
	if (map[i][j - 1] == 0) //9시
		return false;
    return true;
}
int solution(vector<string> moves) 
{
    int answer = 0;

    int hor_move = 0, ver_move = 0;

    for (int i = 0; i < moves.size(); i++)
    {
        if (moves[i] == "U" || moves[i] == "D")
        {
            ver_move++; //세로크기
        }
        else
        {
            hor_move++; //가로크기
        }
    }

    vector<vector<int>> map(hor_move * 4, vector<int>(ver_move * 4, 0));
    int my_v = ver_move;    
    int my_h = hor_move;    
    map[my_v][my_h] = 1;
    for (int i = 0; i < moves.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (moves[i] == "U")
            {
                my_v--;
            }
            else if (moves[i] == "D")
            {
                my_v++;
            }
            else if (moves[i] == "L")
            {
                my_h--;
            }
            else
            {
                my_h++;
            }
            map[my_v][my_h] = 1;
        }
    }

    for (int i = 1; i < map.size(); i++)
    {
        for (int j = 1; j < map[0].size(); j++)
        {
            if (map[i][j] == 0 && checkSqure(map, i, j))
            {
                 answer++;
            }
        }
    }

    return answer;
}
//for (int i = 1; i < map.size(); i++)
//{
//    for (int j = 1; j < map[0].size(); j++)
//    {
//        cout << map[i][j] << "  ";
//    }
//    cout << endl;
//}
int main()
{
    vector<string> moves = { "U", "U", "R", "D", "L", "L", "L", "U", "R", "D", "D", "D", "L", "U", "R", "R", "R", "D", "L", "U" };
    //vector<string> moves = { "U", "R", "D", "L", "U", "R", "D", "L" };

    cout << solution(moves);

	return 0;
}