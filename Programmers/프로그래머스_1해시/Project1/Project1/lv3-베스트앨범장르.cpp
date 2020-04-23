//����
//���ϸ��� ����� �帣 �� ������� �� �뷡 2�� ���
//�״��� ���� ����� �帣 �� ������� �� �뷡 2�� ��� ..


////����
//#include <string>
//#include <vector>
//#include <map>
//#include <algorithm>
//#include <iostream>
//using namespace std;
//
//bool cmp(pair<string, int> a, pair<string, int> b) {
//	return a.second > b.second;
//}
//
//vector<int> solution(vector<string> genres, vector<int> plays) {
//	vector<int> answer;
//	map<string, int>genres_count;
//	vector <pair<string, int>> v;
//
//	for (int i = 0; i < genres.size(); i++) //�帣 �� ���Ƚ�� ī��Ʈ
//		genres_count[genres[i]] += plays[i];
//	map<string, int>::iterator iter = genres_count.begin();
//	for (iter = genres_count.begin(); iter != genres_count.end(); ++iter) //sort�� ���� ���� ���Ϳ� ����
//		v.push_back(make_pair(iter->first, iter->second));
//
//	sort(v.begin(), v.end(), cmp); //��� Ƚ�� �������� ��Ʈ
//	for (int i = 0; i < v.size(); i++) { //�帣 ��, ���� ����� �� �� ã��
//		int f = 0; int s = 0; int fn = 0; int sn = 0;
//		for (int j = 0; j < genres.size(); j++) {
//			if (genres[j] == v[i].first) {
//				if (plays[j] > f) {
//					s = f;
//					sn = fn;
//					f = plays[j];
//					fn = j;
//				}
//				else if (plays[j] > s) {
//					s = plays[j];
//					sn = j;
//				}
//			}
//		}
//		answer.push_back(fn);
//		if (s > 0) //�帣�� 2�� �̻��� ���� ���� ��쿡�� �ٹ��� �ֱ�
//			answer.push_back(sn);
//	}
//	return answer;
//
//}
//int main()
//{
//    vector<string> genres{ "classic", "pop", "classic", "pop","classic", "classic" };
//    vector<int> plays{ 400,     600,      150,    2500,   500,        500 };
//    //vector<string> genres{ "a","b","c","d","e","f"};
//    //vector<int> plays{ 1,2,3,4,5,6}; 
//    //7,6 ,4,3 , 8
//
//    vector<int> answer = solution(genres, plays);
//
//    for (int i = 0; i < answer.size(); i++)
//    {
//        cout << answer[i] << "  ";
//        if (i % 2 == 1)
//            cout << endl;
//    }
//
//
//}





//����Ǭ��3 ������
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool genresSort(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    map<string, int> chart_map;

    //���̵��� �帣 ã��
    for (int i = 0; i < genres.size(); i++)
    {
        chart_map[genres[i]] += plays[i];
    }

    vector<pair<string, int>> song_vec;

    for (auto iter = chart_map.begin(); iter != chart_map.end(); iter++)
    {
        song_vec.push_back(make_pair(iter->first, iter->second));
    }
    sort(song_vec.begin(), song_vec.end(), genresSort);


    //���̵��� �뷡 ã��
    for (int i = 0; i < song_vec.size(); i++)
    {
        int max_idx = -1;
        int max_val = -1;
        int sec_max_idx = -1;
        int sec_max_val = -1;

        for (int j = 0; j < genres.size(); j++)
        {
            if (song_vec[i].first == genres[j]) 
            {
                if (plays[j] > max_val)
                {
                    sec_max_val = max_val;
                    sec_max_idx = max_idx;

                    max_val = plays[j];
                    max_idx = j;
                }
                else if (plays[j] > sec_max_val)
                {
                    sec_max_val = plays[j];
                    sec_max_idx = j;
                }
            }
        }
        answer.push_back(max_idx);
        if (sec_max_idx != -1)
            answer.push_back(sec_max_idx);
    }
    return answer;
}
int main()
{
    //vector<string> genres{ "classic", "pop", "classic", "pop","classic", "classic" };
    //vector<int> plays{       400,     600,      150,    2500,   500,        500 };
    vector<string> genres{ "a","b","b","a","b","c","d","e","e","b" };
    vector<int> plays{ 1,2000,3,4,5,6,100,30,30,1000 };
    //4,2  5  3 0 

    vector<int> answer = solution(genres, plays);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << "  ";
        if (i % 2 == 1)
            cout << endl;
    }
}









////����Ǭ��2 pair���
//#include <string>
//#include <vector>
//#include <iostream>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//bool genresSort(pair<string, int> a, pair<string, int> b)
//{
//    return a.second > b.second;
//}
//vector<int> solution(vector<string> genres, vector<int> plays) 
//{
//    vector<int> answer;
//    map<string, int> chart_map;
//
//    //���̵��� �帣 ã��
//    for (int i = 0; i < genres.size(); i++)
//    {
//        chart_map[genres[i]] += plays[i];
//    }
//
//    vector<pair<string,int>> song_vec;
//
//    for (auto iter = chart_map.begin(); iter != chart_map.end(); iter++)
//    {
//        song_vec.push_back(make_pair(iter->first, iter->second));
//    }
//    sort(song_vec.begin(), song_vec.end(), genresSort);
//
//
//    //���̵��� �뷡 ã��
//    for (int i = 0; i < song_vec.size(); i++)
//    {
//        int max_idx = -1;
//        int sec_max_idx = -1;
//        bool first = true;
//        bool second = true;
//
//        for (int j = 0; j < genres.size(); j++)
//        {
//            if (genres[j] == song_vec[i].first)
//            {
//                if (!first && second)
//                {
//                    sec_max_idx = j;
//                    second = false;
//                }
//                if (first)
//                {
//                    max_idx = j;
//                    first = false;
//                }
//                if (plays[j] > plays[max_idx])  //1�� �ٲ�
//                {
//                    sec_max_idx = max_idx;
//                    max_idx = j;
//                }
//                else if (!second && plays[j] > plays[sec_max_idx])  //2�� �ٲ�
//                {
//                    sec_max_idx = j;
//                }
//                else if (plays[max_idx] == plays[j] && !second) //1�� �����������
//                {
//                    sec_max_idx = j;
//                }
//            }
//        }
//        answer.push_back(max_idx);
//        if (sec_max_idx != -1)
//            answer.push_back(sec_max_idx);
//    }
//    return answer;
//}
//int main()
//{
//    //vector<string> genres{ "classic", "pop", "classic", "pop","classic", "classic" };
//    //vector<int> plays{       400,     600,      150,    2500,   500,        500 };
//    vector<string> genres{ "a","b","b","a","b","c","d","e","e","b"};    
//    vector<int> plays{ 1,2000,3,4,5,6,100,30,30,1000}; 
//    //4,2  5  3 0 
//
//    vector<int> answer = solution(genres, plays);
//
//    for (int i = 0; i < answer.size(); i++)
//    {
//        cout << answer[i] << "  ";
//        if (i % 2 == 1)
//            cout << endl;
//    }
//}






////����Ǭ��1. ����
//#include <string>
//#include <vector>
//#include <iostream>
//#include <map>
//using namespace std;
//
//vector<int> solution(vector<string> genres, vector<int> plays) 
//{
//    vector<int> answer;
//    map<string, int> chart_map;
//
//    //���̵��� �帣 ã��
//    for (int i = 0; i < genres.size(); i++)
//    {
//        chart_map[genres[i]] += plays[i];
//    }
//
//    vector<string> genres_str_vac;
//    vector<int> genres_int_vac;
//    for (auto iter = chart_map.begin(); iter != chart_map.end(); iter++)
//    {
//        genres_str_vac.push_back(iter->first);
//        genres_int_vac.push_back(iter->second);
//    }
//    for (int i = 0; i < genres_str_vac.size()-1; i++)
//    {
//        for (int j = i+1; j < genres_str_vac.size(); j++)
//        {
//            if (genres_int_vac[i] < genres_int_vac[j])
//            {
//                swap(genres_int_vac[i], genres_int_vac[j]);
//                swap(genres_str_vac[i], genres_str_vac[j]);
//            }
//        }
//    }
//
//    //���̵��� �뷡 ã��
//    for (int i = 0; i < genres_str_vac.size(); i++)
//    {
//        int max_idx=-1;
//        int sec_max_idx=-1;
//        bool first = true;
//        bool second = true;
//        for (int j = 0; j < genres.size(); j++)
//        {
//            if (genres[j] == genres_str_vac[i])
//            {
//                if (!first && second)
//                {
//                    sec_max_idx = j;
//                    second = false;
//                }
//                if (first)
//                {
//                    max_idx = j;
//                    first = false;
//                }
//                
//                if (plays[j] > plays[max_idx])  //�ƽ�ã��
//                {
//                    sec_max_idx = max_idx;
//                    max_idx = j;
//                }
//                else if (plays[j] == plays[max_idx] && !second)    //�ƽ��� �Ȱ�����
//                {
//                    sec_max_idx = j;
//                }
//            }
//        }
//        answer.push_back(max_idx);
//        if(!(sec_max_idx==-1))
//            answer.push_back(sec_max_idx);
//    }
//    return answer;
//}
//int main()
//{
//    //vector<string> genres{ "classic", "pop", "classic", "pop","classic", "classic" };
//    //vector<int> plays{       400,     600,      150,    2500,   500,        500 };
//    vector<string> genres{ "a","b","b","a","b","c" };
//    vector<int> plays{ 1,2,3,4,5,6 };
//    //4,2  5  3,0
//
//    vector<int> answer = solution(genres, plays);
//
//    for (int i = 0; i < answer.size(); i++)
//    {
//        cout << answer[i] << "  ";
//        if (i % 2 == 1)
//            cout << endl;
//    }
//}