//����
//seoul �̶�� �迭�� �ִ�
//seoul �迭���� Kim �̶� ���ڿ��� �ε��� ��ȯ

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<string> seoul) {
    string a = " ";
    for (int i = 0; i < seoul.size(); i++)
    {
        if (seoul[i].compare("Kim") == 0)
        {
            return "�輭���� " +to_string(i)+ "�� �ִ�";
        }
    }
}
int main()
{
    vector<string> seoul = { "Jane", "Kim" };
    cout << solution(seoul);
}