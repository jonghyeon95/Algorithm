//���� ť
//���α׷� ������ �Ϸ�����
//�ڿ��ִ°� ���� �ϼ��ǵ� �տ��ִ°� �Ǿ��� ��������
//���α׷����� ���߼ӵ� �ٸ�
//�� �������� ��� �����Ǵ°�


//���� ǰ(vec����)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int now_suc_count = 0;
    while (!progresses.empty())
    {
        for (int i = 0; i < progresses.size(); i++)
        {
            progresses[i] += speeds[i];
        }
        while (progresses[0] >= 100)
        {
            now_suc_count++;
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            if (progresses.empty())
                break;
        }
        if (now_suc_count != 0)
            answer.push_back(now_suc_count);
        now_suc_count = 0;
    }
    return answer;
}
int main()
{
    vector<int> progresses{ 93, 30, 55 };
    vector<int> speeds{ 1, 30, 5 };

    vector<int> answer = solution(progresses, speeds);

    for (auto iter = answer.begin(); iter != answer.end(); iter++)
    {
        cout << *iter << endl;
    }

}




////���� ǰ(queue����) -> ����
//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//using namespace std;
//
//vector<int> solution(vector<int> progresses, vector<int> speeds) {
//    vector<int> answer;
//    int all_suc_count = 0;
//    queue<int> progress_que;
//    vector<int> progress_vec;
//    int answer_idx = 0;
//    progress_vec.resize(progresses.size);
//    for (int i = 0; i < progresses.size(); i++)
//    {
//        progress_que.push(progresses[i]);
//    }
//
//    while (all_suc_count != progresses.size())
//    {
//        for (int i = 0; i < progresses.size() - all_suc_count; i++)
//        {
//            progress_que.push(speeds[i]);
//        }
//    }
//
//
//    return answer;
//
//}
//int main()
//{
//    vector<int> progresses { 93, 30, 55 };
//    vector<int> speeds{ 1, 30, 5 };
//
//    vector<int> answer;
//    for (auto iter = answer.begin(); iter != answer.end(); iter++)
//    {
//        cout << *iter << endl;
//    }
//
//}