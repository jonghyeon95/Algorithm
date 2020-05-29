//�г����� �ٲ�
//�����г������� ���Դ� ������ ǥ��
//�г��ӹٲٴ¹��2����
//�濡�� change ���� �ٲ�
//�������¿��� �ٲ�


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
    //�迭�� �� �־��ֱ�
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

    //����� �ֱ�
    for (int i = 0; i < record.size(); i++)
    {
        if ((string)"Enter" == command_vec[i])
        {
            string s = nick_map[id_vec[i]] + "���� ���Խ��ϴ�.";
            answer.push_back(s);
        }
        else if ((string)"Leave" == command_vec[i])
        {
            string s = nick_map[id_vec[i]] + "���� �������ϴ�.";
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