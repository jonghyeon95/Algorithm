//문제 스택
//() 는 레이저고
//( ㅁㄴㅇㅁㄴ) 안붙어있으면 쇠막대기임, 가장 인접한 ) 까지가 길이임
//레이저로 막대기 자르는데 총 막대기 갯수는??



//답지..ㄷㄷ
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string a) {
    int answer = 0;
    stack<char> s;

    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '(')
            s.push(a[i]);
        else {
            s.pop();
            if (a[i - 1] == '(')
                answer += s.size();
            else
                answer++;
        }
    }
    return answer;
}
int main()
{
    string arrangement = "()(((()())(())()))(())";
    cout << solution(arrangement);
}



////내가 품 스택이용
//#include <iostream>
//#include <string>
//#include <vector>
//#include <stack>
//using namespace std;
//
//int solution(string arrangement) 
//{
//    int answer = 0;
//    int str_num = 0;
//    stack<pair<int,char>> arrangement_stk;  //indx, char
//    vector<int> gun_vec;
//    vector<pair<int, int>> stick_vec;
//    for (int i = 0; i < arrangement.length(); i++)
//    {
//        arrangement_stk.push(make_pair(i, arrangement[i]));
//        
//        pair<int, char> temp = arrangement_stk.top();
//        if (temp.second == ')')
//        {
//            arrangement_stk.pop();
//            if (arrangement_stk.top().first+1 == temp.first)    //레이저일때
//            {
//                gun_vec.push_back(arrangement_stk.top().first);
//                arrangement_stk.pop();
//            }
//            else
//            {
//                stick_vec.push_back(make_pair(arrangement_stk.top().first, temp.first));
//                arrangement_stk.pop();
//            }
//        }
//    }
//
//    for (int i = 0; i < stick_vec.size(); i++)  //막대 갯수찾기
//    {
//        pair<int, int> stick = stick_vec[i];
//        for (int j = 0; j < gun_vec.size(); j++)
//        {
//            int gun = gun_vec[j];
//            if (stick.first < gun && stick.second > gun)
//            {
//                answer++;
//            }
//        }
//        answer++;
//    }
//    return answer;
//}
//
//int main()
//{
//    string arrangement = "()(((()())(())()))(())";
//    cout << solution(arrangement);
//}