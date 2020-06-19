//문제
//가로세로 1*1정사각형 들로 이루어진 직사각형 있다.
//대각선으로 찢음
//이때 멀쩡한 정사각형 찾기
//가로,세로 1억 이하

//풀이 최대공약수로 나누면 그사각형 크기만큼 계속 됨
//그 사각형안에서 찢어진 사각형은 가로+세로-1임
//최대공약수 구하기 => 유클리드 호제법
#include <iostream>
using namespace std;

long long GCD(int w, int h) //유클리드 호제법
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