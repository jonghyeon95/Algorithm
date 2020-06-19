//����
//���μ��� 1*1���簢�� ��� �̷���� ���簢�� �ִ�.
//�밢������ ����
//�̶� ������ ���簢�� ã��
//����,���� 1�� ����

//Ǯ�� �ִ������� ������ �׻簢�� ũ�⸸ŭ ��� ��
//�� �簢���ȿ��� ������ �簢���� ����+����-1��
//�ִ����� ���ϱ� => ��Ŭ���� ȣ����
#include <iostream>
using namespace std;

long long GCD(int w, int h) //��Ŭ���� ȣ����
{
    int a = w >= h ? w : h;
    int b = w < h ? w : h;
    while (b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long solution(int w, int h) {
    long long answer;

    int gcd = GCD(w, h);

    long long total = (long long) w * (long long)h;
    int w_ = w / gcd;
    int h_ = h / gcd;

    int cut = w_ + h_ - 1;
    
    answer = total - cut * gcd;

    return answer;
}

int main()
{
    int w = 8;
    int h = 12;

    cout << solution(w, h);
}