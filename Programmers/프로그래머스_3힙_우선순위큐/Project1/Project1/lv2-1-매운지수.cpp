//����
//�ſ����� ��Ÿ���� K
//�ΰ��� �丮�� ������ �ſ������� ����ȸſ����� + �ι�°�ȸſ�����*2
//�϶� ��� ������ K�������� �������� �������� �ұ�


//���� ǰ, �켱���� ť priority_queue
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> scov_pq;
    for (int i = 0; i < scoville.size(); i++)
    {
        scov_pq.push(scoville[i]);
    }
    for (int i = 0; i < scoville.size() - 1; i++)
    {
        int temp = scov_pq.top();
        scov_pq.pop();
        if (temp >= K)
        {
            break;
        }

        int sum = temp + scov_pq.top() * 2;
        scov_pq.pop();
        scov_pq.push(sum);
        
        answer++;
    }
    if (scov_pq.top() < K)
    {
        return -1;
    }
    return answer;
}
int main()
{
    vector<int> scoville{ 1, 2, 3, 9, 10, 12 };
    int K = 7;

    cout << solution(scoville, K);
}



////�켱���� ť priority_queue ���
//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//using namespace std;
//int main()
//{
//    vector<int> vec{ 5, 3, 8, 7 };
//    priority_queue<int, vector<int>, greater<int>> pq;
//    for (int i = 0; i < vec.size(); i++)
//    {
//        pq.push(vec[i]);
//    }
//    for (int i = 0; i < vec.size(); i++)
//    {
//        cout <<pq.top() << " ";
//        pq.pop();
//    }
//    cout << endl;
//    cout << endl;
//    priority_queue<int, vector<int>, less<int>> pq2;
//    //priority_queue<int> pq2; �� ����
//
//    for (int i = 0; i < vec.size(); i++)
//    {
//        pq2.push(vec[i]);
//    }
//    for (int i = 0; i < vec.size(); i++)
//    {
//        cout << pq2.top() << " ";
//        pq2.pop();
//    }
//}





////���� ǰ, sort��� ȿ���� Ż��, 
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int solution(vector<int> scoville, int K) {
//    int answer = 0;
//
//    for(int i=0; i<scoville.size()-1; i++)
//    {
//        sort(scoville.begin()+i, scoville.end());
//        if (scoville[i] >= K)
//        {
//            break;
//        }
//
//        int sum = scoville[i] + scoville[i+1] * 2;
//        scoville[i+1] = sum;
//        answer++;
//    }
//
//    if (scoville[scoville.size()-1] < K)
//    {
//        return -1;
//    }
//    return answer;
//}
//int main()
//{
//    vector<int> scoville{ 1,2,3 };
//    int K = 11;
//
//    cout << solution(scoville, K);
//
//}