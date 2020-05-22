//go
//gone
//guild 있을때
//go를 다치면 go가나오고 2
//gon을 치면 gone이 나오고 3
//gu를 치면 guild가 나옴 2
//총합 7

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(vector<string> words) {
    int answer = 0;
    int size = words.size();
    sort(words.begin(), words.end());

    for (int i = 0; i < size; i++)  //arr의 i번째
    {
        bool pre = true;   //앞에꺼와 비교 여부 결정
        bool next = true;  //뒤에단어와 비교 여부 결정
        for (int j = 0; j < words[i].size(); j++)  //string(words[i])의 j번째
        {
            if (j + 1 == words[i].size())   //마지막 문자일 때
            {
                answer += j + 1;
                break;
            }
            char c = words[i][j];

            if (i == 0) //첫단어이므로 이전 단어와 비교할필요 없다
                pre = false;
            if (i == size - 1) //마지막 단어이므로 뒤 단어와 비교할필요 없다
                next = false;

            //앞에단어와 비교
            if (pre && (j >= words[i - 1].size() || c != words[i - 1][j]))
            {
                pre = false;
            }

            //뒤에단어와 비교
            if (next && (j >= words[i + 1].size() || c != words[i + 1][j]))
            {
                next = false;
            }

            if (!pre && !next)
            {
                answer += j + 1;
                break;
            }
        }
    }

    return answer;
}
int main()
{
    //vector<string> words{ "go", "gone", "guild" };
    //vector<string> words{ "abc", "def", "ghi", "jklm" };
    //vector<string> words{ "word", "war", "warrior", "world" };
    //vector<string> words{ "aa", "aaaaaaa", "aaaab"};
    vector<string> words{ "arak", "areb", "ores" };

    cout << solution(words);
}