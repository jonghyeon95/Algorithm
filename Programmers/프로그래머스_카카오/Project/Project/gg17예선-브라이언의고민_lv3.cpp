//����
//�����ڸ� ���� ���ڷ� �������� ��
//�����Ģ
//AzBzCzD   �ܾ���̿� ���� �ҹ�������
//zABCDz     �ܾ� �糡�� �ҹ���
//zAxBxCxDz     �ΰ��� ���� �� �� ����
//�ܾ ������ ��ĭ ���
//���Ű� �ȵǸ� valid return;

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
        if (sentence[i] >= 'a') //���Խ���
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