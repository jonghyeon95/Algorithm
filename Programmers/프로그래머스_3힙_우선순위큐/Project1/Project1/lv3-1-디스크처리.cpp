//����
//��ũó���Ϸ���, ������ �迭���� [���½ð�, �۾��ð�] �� ����
//ȿ���� ���� ����ð��� ª���� �켱���� �����Ŵ
//�̶� ��սð� ���Ͻÿ�


//�켱����ť �ٽ� ǰ
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int solution(vector<vector<int>> jobs)
{
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > jobs_pq;
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > disk_pq; 
    vector<int> time_vec;
    int time;
    bool enter_possible = true;
    int start_time;
    int end_time;
    int answer = 0;

    for (int i = 0; i < jobs.size(); i++)
    {
        jobs_pq.push(make_pair(jobs[i][0],jobs[i][1]));
    }
    time = jobs_pq.top().first;
    while (true)
    {
        if (!enter_possible && end_time == time)    //�տ���ũ�� ���ᰡ ��
        {
            enter_possible = true;
        }

        while (!jobs_pq.empty() && jobs_pq.top().first <= time)
        {
            disk_pq.push(make_pair(jobs_pq.top().second, jobs_pq.top().first));
            jobs_pq.pop();
        }
        if (enter_possible && !disk_pq.empty())
        {
            start_time = time;
            end_time = disk_pq.top().first + time;
            time_vec.push_back(start_time - disk_pq.top().second + disk_pq.top().first);
            disk_pq.pop();
            enter_possible = false;
        }
        if (jobs_pq.empty() && disk_pq.empty())
        {
            break;
        }
        time++;
    }

    for (int i = 0; i < time_vec.size(); i++)
    {
        answer += time_vec[i];
    }
    answer = answer / time_vec.size();

    return answer;
}
int main()
{
    //vector<vector<int>> job{ {1, 9},{1, 4},{1, 5 }, {1, 7}, {1, 3} };   //13
    //vector<vector<int>> job{ {24, 10}, {18, 39}, {34, 20}, {37, 5}, {47, 22}, {20, 47}, {15, 2}, {15, 34}, {35, 43}, {26, 1} };   //74
    //vector<vector<int>> job{ {0,3},{1,9},{2,6} };
    vector<vector<int>> job{ {0,3},{1,9},{500,6} };
    cout << solution(job);
}





////�켱����ť�� ǰ
//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int solution(vector<vector<int>> jobs) 
//{
//    int answer = 0;
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> jobs_pq;
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> disk_pq;
//    //first�� ���� ����, <�ɸ��½ð�, �������۽ð�>
//    
//    vector<int> time_vec;
//    int job_idx = 0;
//    int timer = 0;
//    int finish_time = -1;
//    int finish_count = 0;
//    bool open = true;
//
//    for (int i = 0; i < jobs.size(); i++)
//    {
//        jobs_pq.push(make_pair(jobs[i][0], jobs[i][1]));
//    }
//
//    while (finish_count != jobs.size())
//    {
//        while (!jobs_pq.empty() && jobs_pq.top().first == timer)
//        {
//            disk_pq.push(make_pair(jobs_pq.top().second, jobs_pq.top().first));
//            jobs_pq.pop();
//        }
//       
//        if (timer == finish_time)
//        {
//            open = true;
//            finish_count++;
//        }
//
//        if (open && !disk_pq.empty())   //�����ص� �� ���
//        {
//            finish_time = timer + disk_pq.top().first;
//            time_vec.push_back(disk_pq.top().first + timer - disk_pq.top().second);
//            disk_pq.pop();
//            open = false;
//        }
//
//
//        timer++;
//    }
//    for (int i = 0; i < time_vec.size(); i++)
//    {
//        answer += time_vec[i];
//    }
//    answer /= time_vec.size();
//    return answer;
//}
//int main()
//{
//    //vector<vector<int>> job{ {1, 9},{1, 4},{1, 5 }, {1, 7}, {1, 3} };
//    vector<vector<int>> job{ {24, 10}, {18, 39}, {34, 20}, {37, 5}, {47, 22}, {20, 47}, {15, 2}, {15, 34}, {35, 43}, {26, 1} };
//    //vector<vector<int>> job{ {0,3},{1,9},{2,6} };
//    cout << solution(job);
//}