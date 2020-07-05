//문제
//광고문자를 원래 문자로 돌리려고 함
//광고규칙
//AzBzCzD   단어사이에 같은 소문자있음
//zABCDz     단어 양끝에 소문자
//zAxBxCxDz     두개가 섞일 수 도 있음
//단어가 끝나면 한칸 띄기
//제거가 안되면 valid return;

#include <string>
#include <iostream>
#include <queue>
using namespace std;
string solution(string sentence) 
{
    vector<int> v;
    string answer = "";
    int start = -1;
    int end = -1;
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] >= 'a') //스팸시작
        {

        }
        else
        {
            if (start == -1)
            {
                start = -1;
            }
            
        }


    }


    return answer;
}
int main()
{
    string sentence = "zABCz";
    cout << solution(sentence);
}