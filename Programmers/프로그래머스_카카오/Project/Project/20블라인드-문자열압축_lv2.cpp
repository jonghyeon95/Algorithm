//����
//���ڿ� s �� �־����� ��
//1���̻����� ���డ��
//���������� ���� ª�� ���� return
//ex) abababab => (2������) 4ab,  (4������) 2abcd


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