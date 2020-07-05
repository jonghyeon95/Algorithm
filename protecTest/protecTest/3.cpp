


//#include<iostream>
//#include<vector>
//#include<deque>
//#include<map>
//#include<algorithm>
//#include<stack>
//using namespace std;
//
//vector<int> solution(vector<vector<int>> customer, int K)
//{
//    vector<int> answer;
//    deque<int> res;
//    deque<int> wait;
//    map<int, bool> iswait;
//    for (int i = 0; i < customer.size(); i++)
//    {
//        if (customer[i][1] == 1)
//        {
//            if (res.size() < K)
//            {
//                res.push_back(customer[i][0]);
//                iswait[customer[i][0]] = false;
//            }
//            else
//            {
//                wait.push_back(customer[i][0]);
//                iswait[customer[i][0]] = true;
//            }
//        }
//
//        else
//        {
//            stack<int> sto;
//            if (iswait[customer[i][0]] == true)  //기다리는중이면
//            {
//                while (true)
//                {
//                    int num = wait.back();
//                    wait.pop_back();
//                    if (customer[i][0] == num)
//                    {
//                        while (!sto.empty())
//                        {
//                            wait.push_front(sto.top());
//                            sto.pop();
//                        }
//                        break;
//                    }
//                    else
//                    {
//                        sto.push(num);
//                    }
//                }
//            }
//            else //방 배정상태이면
//            {
//                while (true)
//                {
//                    int num = res.back();
//                    res.pop_back();
//                    if (customer[i][0] == num)
//                    {
//                        while (!sto.empty())
//                        {
//                            res.push_front(sto.top());
//                            sto.pop();
//                        }
//                        break;
//                    }
//                    else
//                    {
//                        sto.push(num);
//                    }
//                }
//                if (!wait.empty())
//                {
//                    res.push_back(wait.front());
//                    iswait[wait.front()] = false;
//                    wait.pop_front();
//                }
//            }
//        }
//    }
//
//    while (!res.empty())
//    {
//        answer.push_back(res.front());
//        res.pop_front();
//    }
//    sort(answer.begin(), answer.end());
//
//    return answer;
//}



//#include<iostream>
//#include<vector>
//#include<map>
//#include<algorithm>
//using namespace std;
//vector<int> solution(vector<vector<int>> customer, int K)
//{
//    vector<int> answer;
//    int start = 0;
//    int end = 0;
//    vector<int> room;
//    vector<int> wait;
//    int room_count = 0;
//    int wait_count = 0;
//    map<int, bool> iswait;
//
//    for (int i = 0; i < customer.size(); i++)
//    {
//        int cus = customer[i][0];
//
//        if (customer[i][1] == 1)    //예약
//        {
//            if (room_count < K)
//            {
//                room.push_back(cus);
//                iswait[cus] = false;
//                room_count++;
//            }
//            else
//            {
//                wait.push_back(cus);
//                iswait[cus] = true;
//                wait_count++;
//            }
//        }
//        else  //취소
//        {
//            if (iswait[cus] == true)    //대기자 명단이면
//            {
//                int idx = find(wait.begin(), wait.end(), cus) - wait.begin();
//                wait[idx] = -1;
//                wait_count--;
//            }
//            else  //예약성공 명단이면
//            {
//                int idx = find(room.begin(), room.end(), cus) - room.begin();
//                room[idx] = -1;
//                room_count--;
//                
//                if (wait_count > 0)
//                {
//                    int idx;
//                    for (int i = 0; i < wait.size(); i++)
//                    {
//                        if (wait[i] != -1)
//                        {
//                            idx = i;
//                            break;
//                        }
//                    }
//                    room.push_back(wait[idx]);
//                    iswait[wait[idx]] = false;
//                    room_count++;
//                    wait_count--;
//                    wait[idx] = -1;
//                }
//            }
//        }
//    }
//    for (int i = 0; i < room.size(); i++)
//    {
//        if (room[i] != -1)
//            answer.push_back(room[i]);
//    }
//    sort(answer.begin(), answer.end());
//
//    return answer;
//}

//#include<iostream>
//#include<vector>
//#include<deque>
//#include<map>
//#include<algorithm>
//using namespace std;
//
//vector<int> solution(vector<vector<int>> customer, int K)
//{
//    vector<int> answer;
//    deque<int> res;
//    deque<int> wait;
//    map<int, bool> iswait;
//    for (int i = 0; i < customer.size(); i++)
//    {
//        if (customer[i][1] == 1)
//        {
//            if (res.size() < K)
//            {
//                res.push_back(customer[i][0]);
//                iswait[customer[i][0]] = false;
//            }
//            else
//            {
//                wait.push_back(customer[i][0]);
//                iswait[customer[i][0]] = true;
//            }
//        }
//
//        else
//        {
//            if (iswait[customer[i][0]] == true)  //기다리는중이면
//            {
//                for (int j = 0; j < wait.size(); j++)
//                {
//                    if (wait[j] == customer[i][0])
//                    {
//                        wait.erase(wait.begin() + j);
//                        break;
//                    }
//                }
//            }
//            else //방 배정상태이면
//            {
//                for (int j = 0; j < res.size(); j++)
//                {
//                    if (res[j] == customer[i][0])
//                    {
//                        res.erase(res.begin() + j);
//                        break;
//                    }
//                }
//                if (!wait.empty())
//                {
//                    res.push_back(wait.front());
//                    iswait[wait.front()] = false;
//                    wait.pop_front();
//                }
//            }
//        }
//    }
//
//    while (!res.empty())
//    {
//        answer.push_back(res.front());
//        res.pop_front();
//    }
//    sort(answer.begin(), answer.end());
//
//    return answer;
//}


//#include<iostream>
//#include<vector>
//#include<map>
//#include<algorithm>
//using namespace std;
//vector<int> solution(vector<vector<int>> customer, int K)
//{
//    vector<int> answer;
//    int start = 0;
//    int end = 0;
//    vector<int> room;
//    vector<int> wait;
//    int room_count = 0;
//    int wait_count = 0;
//    map<int, bool> iswait;
//
//    for (int i = 0; i < customer.size(); i++)
//    {
//        int cus = customer[i][0];
//
//        if (customer[i][1] == 1)    //예약
//        {
//            if (room_count < K)
//            {
//                room.push_back(cus);
//                iswait[cus] = false;
//                room_count++;
//            }
//            else
//            {
//                wait.push_back(cus);
//                iswait[cus] = true;
//                wait_count++;
//            }
//        }
//        else  //취소
//        {
//            if (iswait[cus] == true)    //대기자 명단이면
//            {
//                int idx = find(wait.begin(), wait.end(), cus) - wait.begin();
//                wait.erase(wait.begin() + idx);
//                wait_count--;
//            }
//            else  //예약성공 명단이면
//            {
//                int idx = find(room.begin(), room.end(), cus) - room.begin();
//                room.erase(room.begin() + idx);
//                room_count--;
//                
//                if (wait_count > 0)
//                {
//                    int val = wait[0];
//                    wait.erase(wait.begin());
//                    room.push_back(val);
//                    iswait[val] = false;
//                    room_count++;
//                    wait_count--;
//                }
//            }
//        }
//    }
//    for (int i = 0; i < room.size(); i++)
//    {
//        answer.push_back(room[i]);
//    }
//    sort(answer.begin(), answer.end());
//
//    return answer;
//}


//#include<iostream>
//#include<vector>
//#include<deque>
//#include<map>
//#include<set>
//#include<algorithm>
//using namespace std;
//
//vector<int> solution(vector<vector<int>> customer, int K)
//{
//    vector<int> answer;
//    deque<int> res;
//    deque<int> wait;
//    map<int, bool> isWait;
//    map<int, bool> isRes;
//    map<int, bool> isExist;
//    int res_count = 0;
//    int wait_count = 0;
//
//    for (int i = 0; i < customer.size(); i++)
//    {
//        if (customer[i][1] == 1)
//        {
//            if (res_count < K)
//            {
//                res.push_back(customer[i][0]);
//                isWait[customer[i][0]] = false;
//                isRes[customer[i][0]] = true;
//                res_count++;
//            }
//            else
//            {
//                wait.push_back(customer[i][0]);
//                isWait[customer[i][0]] = true;
//                wait_count++;
//            }
//            isExist[customer[i][0]] = true;
//        }
//
//        else
//        {
//            isExist[customer[i][0]] = false;
//            isRes[customer[i][0]] = false;
//
//            if (isWait[customer[i][0]] == true)  //기다리는중이면
//            {
//                wait_count--;
//            }
//            else //방 배정상태이면
//            {
//                res_count--;
//                if (wait_count > 0)
//                {
//                    while (true)
//                    {
//                        int num = wait.front();
//                        wait.pop_front();
//                        if (isExist[num] == true)
//                        {
//                            res.push_back(num);
//                            isRes[num] = true;
//                            res_count++;
//                            wait_count--;
//                            isWait[num] = false;
//                            break;
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//    set<int> setanswer;
//    while (!res.empty())
//    {
//        if (isExist[res.front()] && isRes[res.front()])
//        {
//            setanswer.insert(res.front());
//        }
//        res.pop_front();
//    }
//
//    for (auto iter = setanswer.begin(); iter != setanswer.end(); iter++)
//    {
//        answer.push_back(*iter);
//    }
//
//    sort(answer.begin(), answer.end());
//
//    return answer;
//}


//#include<iostream>
//#include<vector>
//#include<list>
//#include<map>
//#include<algorithm>
//using namespace std;
//
//vector<int> solution(vector<vector<int>> customer, int K)
//{
//    vector<int> answer;
//    list<int> res;
//    list<int> wait;
//    map<int, bool> iswait;
//    for (int i = 0; i < customer.size(); i++)
//    {
//        if (customer[i][1] == 1)
//        {
//            if (res.size() < K)
//            {
//                res.push_back(customer[i][0]);
//                iswait[customer[i][0]] = false;
//            }
//            else
//            {
//                wait.push_back(customer[i][0]);
//                iswait[customer[i][0]] = true;
//            }
//        }
//
//        else
//        {
//            if (iswait[customer[i][0]] == true)  //기다리는중이면
//            {
//                for (auto iter = wait.begin(); iter != wait.end(); iter++)
//                {
//                    if (*iter == customer[i][0])
//                    {
//                        wait.erase(iter);
//                        break;
//                    }
//                }
//            }
//            else //방 배정상태이면
//            {
//                for (int j = 0; j < res.size(); j++)
//                {
//                    for (auto iter = res.begin(); iter != res.end(); iter++)
//                    {
//                        if (*iter == customer[i][0])
//                        {
//                            res.erase(iter);
//                            break;
//                        }
//                    }
//                }
//                if (!wait.empty())
//                {
//                    res.push_back(wait.front());
//                    iswait[wait.front()] = false;
//                    wait.pop_front();
//                }
//            }
//        }
//    }
//
//    while (!res.empty())
//    {
//        answer.push_back(res.front());
//        res.pop_front();
//    }
//    sort(answer.begin(), answer.end());
//
//    return answer;
//}


//#include<iostream>
//#include<vector>
//#include<map>
//#include<algorithm>
//#include<queue>
//#include<stack>
//using namespace std;
//
//vector<int> solution(vector<vector<int>> customer, int K)
//{
//    vector<int> answer;
//    queue<int> res;
//    queue<int> wait;
//    map<int, bool> iswait;
//    for (int i = 0; i < customer.size(); i++)
//    {
//        int cus = customer[i][0];
//        if (customer[i][1] == 1)
//        {
//            if (res.size() < K)
//            {
//                res.push(cus);
//                iswait[cus] = false;
//            }
//            else
//            {
//                wait.push(cus);
//                iswait[cus] = true;
//            }
//        }
//
//        else
//        {
//            stack<int> sto;
//            if (iswait[cus] == true)  //기다리는중이면
//            {
//                while (true)
//                {
//                    int num = wait.front();
//                    wait.pop();
//                    if (cus == num)
//                    {
//                        while (!sto.empty())
//                        {
//                            wait.push(sto.top());
//                            sto.pop();
//                        }
//                        break;
//                    }
//                    else
//                    {
//                        sto.push(num);
//                    }
//                }
//            }
//            else //방 배정상태이면
//            {
//                while (true)
//                {
//                    int num = res.back();
//                    res.pop();
//                    if (cus == num)
//                    {
//                        while (!sto.empty())
//                        {
//                            res.push(sto.top());
//                            sto.pop();
//                        }
//                        break;
//                    }
//                    else
//                    {
//                        sto.push(num);
//                    }
//                }
//                if (!wait.empty())
//                {
//                    res.push(wait.front());
//                    iswait[wait.front()] = false;
//                    wait.pop();
//                }
//            }
//        }
//    }
//
//    while (!res.empty())
//    {
//        answer.push_back(res.front());
//        res.pop();
//    }
//    sort(answer.begin(), answer.end());
//
//    return answer;
//}
#include<iostream>
#include<vector>
#include<deque>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> solution(vector<vector<int>> customer, int K)
{
    vector<int> answer;
    deque<int> res;
    deque<int> wait;
    map<int, bool> iswait;
    for (int i = 0; i < customer.size(); i++)
    {
        if (customer[i][1] == 1)
        {
            if (res.size() < K)
            {
                res.push_back(customer[i][0]);
                iswait[customer[i][0]] = false;
            }
            else
            {
                wait.push_back(customer[i][0]);
                iswait[customer[i][0]] = true;
            }
        }

        else
        {
            if (iswait[customer[i][0]] == true)  //기다리는중이면
            {
                for (int j = 0; j < wait.size(); j++)
                {
                    if (wait[j] == customer[i][0])
                    {
                        wait.erase(wait.begin() + j);
                        break;
                    }
                }
            }
            else //방 배정상태이면
            {
                for (int j = 0; j < res.size(); j++)
                {
                    if (res[j] == customer[i][0])
                    {
                        res.erase(res.begin() + j);
                        break;
                    }
                }
                if (!wait.empty())
                {
                    res.push_back(wait.front());
                    iswait[wait.front()] = false;
                    wait.pop_front();
                }
            }
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    while (!res.empty())
    {
        pq.push(res.front());
        res.pop_front();
    }

    while (!pq.empty())
    {
        answer.push_back(pq.top());
        pq.pop();
    }
    
    return answer;
}
int main()
{
    //vector<vector<int>> customer = { {1,1},{2,1},{3,1},{2,0},{2,1} };
    //int K = 2;
    int K = 2;
    vector<vector<int>> customer = { {2, 1},{3, 1},{4, 1},{3, 0},{1, 1},{2, 0},{4, 0},{2, 1} };

    //vector<vector<int>> customer = { {2, 1},{1, 1},{3, 1},{1, 0},{1, 1},{2, 0},{2, 1} };
    //int K = 1;

    vector<int> answer = solution(customer, K);

    for (int i : answer)
    {
        cout << i << "  ";
    }

	return 0;
}