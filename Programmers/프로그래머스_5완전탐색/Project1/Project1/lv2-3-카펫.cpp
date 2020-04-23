////����
////ī�� �������κ��� ������ ���ٷ� �ѷ��ΰ�����
////����,������ �־����� [���α���,���α���]�� �����Ͻÿ�
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> solution(int brown, int red) 
{
    vector<int> answer;
    int all = brown + red;
    vector<pair<int, int>> vec; //���α���, ���α���

    for (int i = 1; i <= all / i; i++)
    {
        if (all % i == 0)
        {
            vec.push_back(make_pair(all / i, i));
        }
    }

    for (int i = 0; i < vec.size(); i++)
    {
        int row_num = vec[i].first - 2;
        int col_num = vec[i].second - 2;
        if (row_num * col_num == red)
        {
            answer.push_back(vec[i].first);
            answer.push_back(vec[i].second);
            break;
        }
    }
    return answer;
}
int main()
{
    int brown = 24;
    int red = 24;

    vector<int> answer = solution(brown, red);
    cout << answer[0] << ", " << answer[1] << endl;
}

