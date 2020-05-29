//닉네임을 바꿈
//최종닉네임으로 들어왔다 나갔다 표시
//닉네임바꾸는방법2가지
//방에서 change 통해 바꿈
//나간상태에서 바꿈


#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    vector<string> command_vec;
    vector<string> id_vec;
    vector<string> nick_vec;
    map<string, string> nick_map; //key = id, value = nickname
    //배열에 값 넣어주기
    for (int i = 0; i < record.size(); i++)
    {
        stringstream ss(record[i]);
        string s;
        vector<string> str_vec;
        while (ss >> s)
        {
            str_vec.push_back(s);
        }
        command_vec.push_back(str_vec[0]);
        id_vec.push_back(str_vec[1]);
        if (str_vec.size() == 3)
        {
            nick_vec.push_back(str_vec[2]);
            nick_map[str_vec[1]] = str_vec[2];
        }
        else
            nick_vec.push_back("");

    }

    //결과값 넣기
    for (int i = 0; i < record.size(); i++)
    {
        if ((string)"Enter" == command_vec[i])
        {
            string s = nick_map[id_vec[i]] + "님이 들어왔습니다.";
            answer.push_back(s);
        }
        else if ((string)"Leave" == command_vec[i])
        {
            string s = nick_map[id_vec[i]] + "님이 나갔습니다.";
            answer.push_back(s);
        }
    }
    return answer;
}
int main()
{
    vector<string> result;
    //vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo",
    //    "Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
    vector<string> record = { "Enter uid0606 Gimoi", "Enter uid4567 Prodo", "Leave uid0606", "Enter uid1234 Prodo", "Change uid1234 OhYeah" };
    result = solution(record);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
}