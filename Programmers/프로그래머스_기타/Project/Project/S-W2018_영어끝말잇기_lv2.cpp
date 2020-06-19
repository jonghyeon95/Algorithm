//n명이 끝말잇기를 함 ,1->2->3->1->2->3
//words 단어가 있음, 중복안됨
//틀린 사람의 번호와 몇번째에서 틀렸는지 출력(1부터시작)

#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;
    vector<vector<string>> vec(words.size() / n);
    map<string, int> mapWords;
    int index;

    mapWords[words[0]] = 1;
    for (int i = 0; i < words.size() - 1; i++)
    {
        int len = words[i].length();
        char pre = words[i][len - 1];
        char next = words[i + 1][0];

        if (mapWords[words[i+1]] == 1)
        {
            index = i + 1;
            break;
        }
        else
        {
            mapWords[words[i + 1]] = 1;
        }

        if (pre != next)
        {
            index = i + 1;
            break;
        }
        if (i == words.size() - 2)
        {
            index = 0;
            break;
        }
    }
   
    if (index == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
	else
	{
		answer.push_back(index % n + 1);
		answer.push_back(index / n + 1);
	}

    return answer;
}
int main()
{
    int n = 3;
    vector<string> words = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };
    //vector<string> words = { "hello", "one", "even", "never", "now", "world", "draw" };
    vector<int> result = solution(n, words);
    cout << result[0] << " " << result[1];
    
}