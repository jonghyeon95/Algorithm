//문제
//문자열 s 가 주어졌을 때
//1개이상으로 압축가능
//압축했을때 가장 짧은 길이 return
//ex) abababab => (2개압축) 4ab,  (4개압축) 2abcd


#include <string>
#include <iostream>
#include <queue>
using namespace std;

int solution(string s)
{
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    if (s.length() == 1)
    {
        return 1;
    }

    for (int i = 1; i < s.length() / 2 + 1; i++)
    {
        string str = "";
        string cap;
        int cap_cnt = 0;

        for (int j = 0; j < s.length();)
        {
            if (cap_cnt == 0)
            {
                cap = s.substr(j, i);
            }
            if (j + i < s.length())
            {
                if (cap == s.substr(j + i, i))
                {
                    cap_cnt++;
                    j += i;
                }
                else
                {
                    if (cap_cnt >= 1)
                    {
                        str += to_string(cap_cnt + 1) + cap;
                        j += i;
                    }
                    else
                    {
                        str += cap;
                        j += i;
                    }
                    cap_cnt = 0;
                }
            }
            else
            {
                if (cap_cnt >= 1)
                {
                    str += to_string(cap_cnt + 1) + cap;
                    j += i;
                }

                str += s.substr(j, i);
                break;
            }
        }
        pq.push(str.length());
    }

    return pq.top();
}
int main()
{
    string s = "aabbaccc";
    cout << solution(s);
}