//자연수 n이 있다
//n을 이진수로 변환했을때의 값을 a라고하면
//n 다음의 수는 a와 1의 갯수가 같다
//n다음의 수를 구하라

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;

    string binary = "";
    bool first = true;
    int point;
    int i = 0;
    int count = 0;

    while (n != 0)
    {
        if ((n & 1) == 1)
        {
            binary = '1' + binary;
            if (first)
            {
                point = i;
                first = false;
            }
        }
        else
        {
            binary = '0' + binary;
        }
        n = n >> 1;
        i++;
    }

    point = binary.length() - point - 1;

    if (point == 0)
    {
        binary += '0';
    }
    else
    {
        for (i = point - 1; i >= 0; i--)
        {
            if (binary[i] == '0')
            {
                binary[i] = '1';

                for (int j = i + 1; j < binary.length(); j++)
                {
                    binary[j] = '0';
                }

                for (int j = 0; j < count; j++)
                {
                    binary[binary.length() - 1 - j] = '1';
                }
                break;
            }

            if (i == 0)
            {
                if (point == binary.length() - 1)
                {
                    binary[0] = '0';
                    binary = '1' + binary;
                }
                else
                {
                    binary[0] = '0';
                    binary = '1' + binary;

                    binary[point + 1] = '0';
                    binary[binary.length() - 1] = '1';
                }
            }
            count++;
        }
    }

    for (i = 0; i < binary.length(); i++)
    {
        if (binary[binary.length() - 1 - i] == '1')
        {
            answer += 1 << i;
        }
    }

    return answer;
}
int main()
{
    int n;
    cin >> n;
    cout << solution(n);
}