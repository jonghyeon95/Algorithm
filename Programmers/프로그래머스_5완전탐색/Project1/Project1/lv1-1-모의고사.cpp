//문제
//수포자 3명 모의고사 찍는데 제일 많이 맞춘사람의 번호뽑기
//1번 : 1 2 3 4 5 / 1 2 3 4 5                        (5)
//2번 : 2 1 2 3 2 4 2 5 / 2 1 2 3 2 4 2 5            (8)
//3번 : 3 3 1 1 2 2 4 4 5 5 / 3 3 1 1 2 2 4 4 5 5    (10)

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    queue<int> stu[3];
    vector<int> collect(3, 0);
    vector<pair<int, int>> answers_vec; //점수,인덱스

    for (int i = 0; i < 5; i++)
    {
        stu[0].push(i+1);
    }

    int k = 1;
    for (int i = 0; i < 8; i++)
    {
        if (i % 2 != 0)
        {
            if (k == 2)
                k++;
            stu[1].push(k);
            k = k % 5 + 1;
        }
        else
        {
            stu[1].push(2);
        }
    }

    stu[2].push(3);
    stu[2].push(3);
    stu[2].push(1);
    stu[2].push(1);
    stu[2].push(2);
    stu[2].push(2);
    stu[2].push(4);
    stu[2].push(4);
    stu[2].push(5);
    stu[2].push(5);
   
    for (int i = 0; i < answers.size(); i++)
    {
        int answer = answers[i];
        for (int j = 0; j < 3; j++)
        {
            if (stu[j].front() == answer)
                collect[j]++;
            stu[j].push(stu[j].front());
            stu[j].pop();
        }
    }

    for (int i = 0; i < collect.size(); i++)
    {
        answers_vec.push_back(make_pair(collect[i], i + 1));
    }
    sort(answers_vec.begin(), answers_vec.end(), compare);
    for (int i = 0; i < collect.size(); i++)
    {
        answer.push_back(answers_vec[i].second);
        if (i == collect.size() - 1 || answers_vec[i].first != answers_vec[i + 1].first)
            break;
    }
    return answer;
}
int main()
{
    vector<int> answers = { 1,3,2,4,2 };
    vector<int> answer = solution(answers);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
}