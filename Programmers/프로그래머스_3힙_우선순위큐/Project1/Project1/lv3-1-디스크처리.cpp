//문제
//디스크처리하려함, 이차원 배열에는 [들어온시간, 작업시간] 이 있음
//효율을 위해 실행시간이 짧은것 우선으로 실행시킴
//이때 평균시간 구하시오


//우선순위큐로 품
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> jobs) 
{
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> jobs_pq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> disk_pq;
    //first에 의해 결정, <걸리는시간, 원래시작시간>
    
    vector<int> time_vec;
    int job_idx = 0;
    int timer = 0;
    int finish_time = -1;
    int finish_count = 0;
    bool open = true;

    for (int i = 0; i < jobs.size(); i++)
    {
        jobs_pq.push(make_pair(jobs[i][0], jobs[i][1]));
    }

    while (finish_count != jobs.size())
    {
        while (!jobs_pq.empty() && jobs_pq.top().first == timer)
        {
            disk_pq.push(make_pair(jobs_pq.top().second, jobs_pq.top().first));
            jobs_pq.pop();
        }
       
        if (timer == finish_time)
        {
            open = true;
            finish_count++;
        }

        if (open && !disk_pq.empty())   //실행해도 될 경우
        {
            finish_time = timer + disk_pq.top().first;
            time_vec.push_back(disk_pq.top().first + timer - disk_pq.top().second);
            disk_pq.pop();
            open = false;
        }


        timer++;
    }
    for (int i = 0; i < time_vec.size(); i++)
    {
        answer += time_vec[i];
    }
    answer /= time_vec.size();
    return answer;
}
int main()
{
    //vector<vector<int>> job{ {1, 9},{1, 4},{1, 5 }, {1, 7}, {1, 3} };
    vector<vector<int>> job{ {24, 10}, {18, 39}, {34, 20}, {37, 5}, {47, 22}, {20, 47}, {15, 2}, {15, 34}, {35, 43}, {26, 1} };
    //vector<vector<int>> job{ {0,3},{1,9},{2,6} };
    cout << solution(job);
}