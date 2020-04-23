//문제
//par과 com 비교해서 com에 없는것을 찾기

#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (int i = 0; i < participant.size(); i++)
    {
        if (i == participant.size() - 1 || participant[i] != completion[i])
        {
            answer = participant[i];
            break;
        }
    }
    return answer;
}
int main()
{
    vector<string> par{ "marina", "filipa",  "nikola", "vinko","josipa","z" };
    vector<string> com{ "nikola", "filipa", "marina","vinko","josipa" };

    cout << solution(par, com);
}




//#include <string>
//#include <vector>
//#include<iostream>
//using namespace std;
//string solution(vector<string> participant, vector<string> completion) {
//    string answer = "";
//
//    for (int i = 0; i < completion.size(); i++)
//    {
//        string par = completion[i];
//        for (int j = 0; j < participant.size(); j++)
//        {
//            if (par.compare(participant[j]) == 0)
//            {
//                participant.erase(participant.begin() + j);
//                break;
//            }
//        }
//    }
//    answer = participant[0];
//    return answer;
//}
//int main()
//{
//    vector<string> par{ "marina", "filipa",  "nikola", "vinko", "filipa","josipa" };
//    vector<string> com{ "nikola", "filipa", "marina","vinko","josipa" };
//
//    cout << solution(par, com);
//}

