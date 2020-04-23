//�� ����
//���� ["����ǰ", "����"]
//������ �ߺ��ȵǰ� ���� �Դ� ����� �� ���ϱ�
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> map_clothes;
    for (int i = 0; i < clothes.size(); i++)
    {
        map_clothes[clothes[i][1]]++;
    }
    //for (map<string, int>::iterator iter = map_clothes.begin(); iter != map_clothes.end(); iter++)
    //{
    //    answer *= iter->second + 1;
    //}
    for (auto iter = map_clothes.begin(); iter != map_clothes.end(); iter++)
    {
        answer *= iter->second + 1;
    }
    answer--;

    return answer;
}
int main()
{
    //vector<vector<string>> clothes{ {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };
    vector<vector<string>> clothes{ {"1", "a"},{"2", "b"},{"3", "c"},{"4","b"},{"5","a"},{"6","a"},{"7","c"} };

    cout << solution(clothes);
}






////��Ʈ+ǰ
//#include <string>
//#include <vector>
//#include <iostream>
//#include <map>
//using namespace std;
//int solution(vector<vector<string>> clothes) {
//    int answer = 0;
//    int result = 1;
//    vector<int> kinds_clothes;
//    map<string, int> map_clothes;
//    for (int i = 0; i < clothes.size(); i++)
//    {
//        map_clothes[clothes[i][1]]++;
//    }
//    for (map<string, int>::iterator iter = map_clothes.begin(); iter != map_clothes.end(); iter++)
//    {
//        kinds_clothes.push_back(iter->second + 1);
//    }
//    for (int i = 0; i < kinds_clothes.size(); i++)
//    {
//        result *= kinds_clothes[i];
//    }
//    
//    answer = result - 1;
//
//    return answer;
//}
//int main()
//{
//    //vector<vector<string>> clothes{ {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };
//    vector<vector<string>> clothes{ {"1", "a"},{"2", "b"},{"3", "c"},{"4","b"},{"5","a"},{"6","a"},{"7","c"} };
//
//    cout << solution(clothes);
//}