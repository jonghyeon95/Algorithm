//����
//124���󿡴� �ڿ����� ����
//10���� 124����
//1		1
//2		2
//3		4
//4		11
//5		12
//6		15
//7		21
//8		22
//9		24
//10	41
//�϶� �ڿ��� n�� �־����� 124������ڷ� return�ض�
//n<=500000000

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) {
    string answer = "";

    while (n > 0)
    {
        int nam = n % 3;
        if (nam == 0)
            answer = "4" + answer;
        else if (nam == 1)
            answer = "1" + answer;
        else if (nam == 2)
            answer = "2" + answer;

        n--;
        n = n / 3;
    }
    return answer;
}
int main()
{
    int n;
    cin >> n;

    cout << solution(n);

}