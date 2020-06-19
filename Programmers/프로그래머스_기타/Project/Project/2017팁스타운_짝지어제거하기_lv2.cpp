//문제
//문자열 s 주어짐
//문자붙어있는거 지움
//다 지워지면 1, 아니면 0

//스택
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int solution(string s)
{
    if (s.length() % 2 == 1)
                return 0;

    stack<char> stck;
    
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (stck.empty())
        {
            stck.push(c);
        }
        else
        {
            if (c == stck.top())
            {
                stck.pop();
            }
            else
            {
                stck.push(c);
            }
        }
    }
    if (stck.empty())
    {
        return 1;
    }
    else
        return 0;
}
int main()
{
    string s = "kacddcak";
    cout << solution(s);
}


////시간초과
//#include <iostream>
//#include<string>
//using namespace std;
//int solution(string s)
//{
//    int answer = 0;
//    int idx = s.length() - 1;
//
//    if (s.length() % 2 == 1)
//        return 0;
//    bool suc = true;
//    while (suc)
//    {
//        suc = false;
//        while(idx != 0)
//        {
//            if (s[idx] == s[idx - 1])
//            {
//                suc == true;
//                s.replace(idx - 1, 2, "");
//            }
//            idx--;
//        }
//    }
//    if (s.length() == 0)
//        return 1;
//    else
//        return 0;
//}
//int main()
//{
//    //string s = "baabaa";
//    string s = "kacddcak";
//    cout << solution(s);
//    //cout << s.substr(2, 100);
//}



////시간초과
//#include <iostream>
//#include<string>
//using namespace std;
//int solution(string s)
//{
//    int answer = 0;
//    int idx = 0;
//
//    if (s.length() % 2 == 1)
//        return 0;
//
//    while (true)
//    {
//        char now = s[idx];
//        char next = s[idx + 1];
//        if (now == next)
//        {
//            //s = s.substr(0, idx) + s.substr(idx + 2, s.length());
//            s = s.replace(idx, 2, "");
//            if (idx == 0)
//                idx = 0;
//            else
//                idx--;
//        }
//        else
//        {
//            idx++;
//            if (idx >= s.length() - 1)
//            {
//                return 0;
//            }
//        }
//
//        if (s.length() == 0)
//        {
//            return 1;
//        }
//    }
//    return answer;
//}
//int main()
//{
//    //string s = "baabaa";
//    string s = "kacddcak";
//    cout << solution(s);
//}