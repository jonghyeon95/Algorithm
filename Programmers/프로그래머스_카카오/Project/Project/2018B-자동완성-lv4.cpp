//go
//gone
//guild ������
//go�� ��ġ�� go�������� 2
//gon�� ġ�� gone�� ������ 3
//gu�� ġ�� guild�� ���� 2
//���� 7

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(vector<string> words) {
    int answer = 0;
    int size = words.size();
    sort(words.begin(), words.end());

    for (int i = 0; i < size; i++)  //arr�� i��°
    {
        bool pre = true;   //�տ����� �� ���� ����
        bool next = true;  //�ڿ��ܾ�� �� ���� ����
        for (int j = 0; j < words[i].size(); j++)  //string(words[i])�� j��°
        {
            if (j + 1 == words[i].size())   //������ ������ ��
            {
                answer += j + 1;
                break;
            }
            char c = words[i][j];

            if (i == 0) //ù�ܾ��̹Ƿ� ���� �ܾ�� �����ʿ� ����
                pre = false;
            if (i == size - 1) //������ �ܾ��̹Ƿ� �� �ܾ�� �����ʿ� ����
                next = false;

            //�տ��ܾ�� ��
            if (pre && (j >= words[i - 1].size() || c != words[i - 1][j]))
            {
                pre = false;
            }

            //�ڿ��ܾ�� ��
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