//문제 큐
//트럭이 다리를 건너려고 함
//다리길이, 다리가 견딜 수 있는 무게, 트럭별 무게가 주어짐
//1초에 1씩건넘, 트럭길이1, 이때 다 지나가는 시간은?




//답지 큐사용
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int tot_w = 0;  //현재 다리무게

    int t_front = 0;    //현재 제일 앞에있는 트럭
    int t_cur = 0;      //다리에 올라간차 번호

    int sec = 0;

    queue <int> q;

    while (t_front != truck_weights.size()) {
        if (!q.empty() && (sec - q.front() == bridge_length)) { //큐가 안비어있고 제일처음께 길이랑 같으면
            tot_w -= truck_weights[t_front];    //총무게에서 지나간차를 뺌
            ++t_front;  //제일앞에있는 다음 트럭 
            q.pop();    //지나간 차뺌
        }
        if (t_cur != truck_weights.size() && tot_w + truck_weights[t_cur] <= weight) {
            tot_w += truck_weights[t_cur];  //새로운차 추가
            ++t_cur;    //다리에 올라간차 번호
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



////내가 품 (백터로만 품)
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int solution(int bridge_length, int weight, vector<int> truck_weights) 
//{
//    int answer = 0;
//    vector<pair<int,int>> truck_vec; //트럭번호,트럭이 이동한거리
//    int now_weight = 0;
//    int truck_count = 0;
//    int first_truck_count = 0;
//    int reached_truck = 0;
//    while (true)
//    {
//        answer++;
//        if (reached_truck == truck_weights.size())  //끝났는지 체크
//        {
//            break;
//        }
//        if (truck_count < truck_weights.size() && now_weight + truck_weights[truck_count] <= weight)  //트럭 추가
//        {
//            now_weight += truck_weights[truck_count];
//            truck_vec.push_back(make_pair(truck_count, 0));
//            truck_count++;
//        }
//        for (int i = 0; i < truck_vec.size(); i++)  //트럭 이동
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