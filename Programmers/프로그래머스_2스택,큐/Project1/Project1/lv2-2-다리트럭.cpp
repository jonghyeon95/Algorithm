//���� ť
//Ʈ���� �ٸ��� �ǳʷ��� ��
//�ٸ�����, �ٸ��� �ߵ� �� �ִ� ����, Ʈ���� ���԰� �־���
//1�ʿ� 1���ǳ�, Ʈ������1, �̶� �� �������� �ð���?




//���� ť���
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int tot_w = 0;  //���� �ٸ�����

    int t_front = 0;    //���� ���� �տ��ִ� Ʈ��
    int t_cur = 0;      //�ٸ��� �ö��� ��ȣ

    int sec = 0;

    queue <int> q;

    while (t_front != truck_weights.size()) {
        if (!q.empty() && (sec - q.front() == bridge_length)) { //ť�� �Ⱥ���ְ� ����ó���� ���̶� ������
            tot_w -= truck_weights[t_front];    //�ѹ��Կ��� ���������� ��
            ++t_front;  //���Ͼտ��ִ� ���� Ʈ�� 
            q.pop();    //������ ����
        }
        if (t_cur != truck_weights.size() && tot_w + truck_weights[t_cur] <= weight) {
            tot_w += truck_weights[t_cur];  //���ο��� �߰�
            ++t_cur;    //�ٸ��� �ö��� ��ȣ
            q.push(sec);
        }
        ++sec;
    }

    answer = sec;

    return answer;
}
int main()
{
    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights{ 7, 4, 5, 6 };

    cout << solution(bridge_length, weight, truck_weights);
}



////���� ǰ (���ͷθ� ǰ)
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int solution(int bridge_length, int weight, vector<int> truck_weights) 
//{
//    int answer = 0;
//    vector<pair<int,int>> truck_vec; //Ʈ����ȣ,Ʈ���� �̵��ѰŸ�
//    int now_weight = 0;
//    int truck_count = 0;
//    int first_truck_count = 0;
//    int reached_truck = 0;
//    while (true)
//    {
//        answer++;
//        if (reached_truck == truck_weights.size())  //�������� üũ
//        {
//            break;
//        }
//        if (truck_count < truck_weights.size() && now_weight + truck_weights[truck_count] <= weight)  //Ʈ�� �߰�
//        {
//            now_weight += truck_weights[truck_count];
//            truck_vec.push_back(make_pair(truck_count, 0));
//            truck_count++;
//        }
//        for (int i = 0; i < truck_vec.size(); i++)  //Ʈ�� �̵�
//        {
//            truck_vec[i].second += 1;
//        }
//        if (truck_vec[0].second == bridge_length)
//        {
//            truck_vec.erase(truck_vec.begin());
//            now_weight -= truck_weights[first_truck_count++];
//            reached_truck++;
//        }
//    }
//    return answer;
//}
//int main()
//{
//    int bridge_length = 2;
//    int weight =10;
//    vector<int> truck_weights { 7, 4, 5, 6 };
//
//    cout << solution(bridge_length, weight, truck_weights);
//}