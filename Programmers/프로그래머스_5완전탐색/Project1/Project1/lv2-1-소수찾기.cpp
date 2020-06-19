//����
//0~9���� �迭(���ڿ�) ������
//�̸� �����ؼ� ������ �Ҽ��� ���� ã��
//0<=n<=9999999
//1.������ִ� �ִ밪�� �����
//2.�ִ밪������ �Ҽ��� ��� ã�´�
//3.�ִ밪������ �Ҽ��� ������ִ��� üũ�Ѵ�
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int sosoo[10000000];    //1�̸� �Ҽ�, 0�̸� �Ҽ��ƴ�
void findsosoo(int max)
{
    sosoo[1] = 0;
    for (int i = 2; i <= max; i++)
    {
        sosoo[i] = 1;
    }
    for (int i = 2; i <= sqrt(max); i++)
    {
        if (sosoo[i] == 0)
            continue;
        for (int j = i * i; j <= max; j += i)
        {
            sosoo[j] = 0;
        }
    }
}
bool compare(int a, int b)
{
    return a > b;
}
int solution(string numbers) {
    int answer = 0;
    string max_str = "";
    int max_int;
    vector<int> vec;
    for (int i = 0; i < numbers.size(); i++)
    {
        vec.push_back(numbers[i]-'0');
    }
    sort(vec.begin(), vec.end(), compare);

    for (int i = 0; i < vec.size(); i++)
    {
        max_str += to_string(vec[i]);
    }
    max_int = atoi(max_str.c_str());
    findsosoo(max_int);

    for (int i = 2; i <= max_int; i++)
    {
        if (sosoo[i] == 1)
        {
            bool suc = true;
            vector<int> storage(vec.begin(), vec.end());
            int j = i;
            while (j > 0)
            {
                int a = j % 10;
                int index = find(storage.begin(), storage.end(), a) - storage.begin();
                if (index == storage.size()) //��ã����
                {
                    suc = false;
                    break;
                }
                storage.erase(storage.begin() + index);
                j /= 10;
            }
            if (suc == true)
                answer++;
        }
    }

    return answer;
}
int main()
{
    string numbers = "011";
    cout << solution(numbers);
}