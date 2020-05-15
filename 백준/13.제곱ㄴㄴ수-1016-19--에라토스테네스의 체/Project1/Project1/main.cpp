//x�� 1���� ū �������� ������ �������� ���� ��, ������������� ��
//min, max�϶� ������������ ������?
//1<=min<=1000000000000
//min<=max<=min+1000000
//44 52 3
//32 70 24

//#include <stdio.h>
//typedef long long ll;
//
//bool chk[1000001], aux[1000001];
//
//int main() {
//	ll a, b;
//	scanf_s("%lld %lld", &a, &b);
//
//	int ans = b - a + 1;
//	for (ll i = 2; i * i <= b; i++) {
//		if (aux[i]) continue;
//		for (ll j = i; j * j <= b; j += i) aux[j] = 1;
//		for (ll j = ((a - 1) / (i * i) + 1) * i * i; j <= b; j += i * i)
//			if (!chk[j - a]) chk[j - a] = 1, ans--;
//	}
//
//	printf("%d", ans);
//
//	return 0;
//}


#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    long long min;
    long long max;

    cin >> min;
    cin >> max;

    //�� �ʱ�ȭ
    //bool* arr = new bool[1000001];
    vector<bool> arr(max - min + 1, true);


    //�˰���
    for (long long i = 2; i <= sqrt(max); i++)
    {
        long long pow = i * i;
        long long start = ((min - 1) / pow) * pow + pow;

        for (long long j = start; j <= max; j += pow)
        {
            arr[j - min] = false;
        }
    }

    //���
    int count = 0;
    for (long long i = 0; i <= max - min; i++)
    {
        if (arr[i] == true)
        {
            count++;
        }
    }
    cout << count;
}



//
//
////�ð��ʰ�
//#include <iostream>
//#include <cmath>
//using namespace std;
//int main()
//{
//    long long min;
//    long long max;
//
//    cin >> min;
//    cin >> max;
//
//    bool* arr = new bool[1000001];
//    for (int i = 0; i <= max-min; i++)
//    {
//        arr[i] = true;
//    }
//
//    for (long long i = 2; i <= sqrt(max); i++)
//    {
//        if (arr[i] == false)
//            continue;
//        long long Pow = i * i;
//        long long start = min;
//        while (start % Pow != 0)
//        {
//            start++;
//        }
//
//        for (long long j = start; j <= max; j += Pow)
//        {
//            if (arr[j - min] == 0)
//                continue;
//            arr[j-min] = 0;
//        }
//    }
//
//    int count = 0;
//    for (long long i = 0; i <= max - min; i++)
//    {
//        if (arr[i] != 0)
//        {
//            count++;
//        }
//    }
//    cout << count;
//}





////�ε������� �ʰ�
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int main()
//{
//    long long min;
//    long long max;
//
//    cin >> min;
//    cin >> max;
//
//    long long* arr = new long long[max + 1];
//    for (int i = 1; i <= max; i++)
//    {
//        arr[i] = i;
//    }
//
//    for (long long i = 2; i <= sqrt(max); i++)
//    {
//        long long Pow = i * i;
//        if (arr[Pow] == 0)
//            continue;
//
//        for (long long j = Pow; j <= max; j += Pow)
//        {
//            arr[j] = 0;
//        }
//    }
//
//    int count = 0;
//    for (long long i = min; i <= max; i++)
//    {
//        if (arr[i] != 0)
//        {
//            count++;
//        }
//    }
//    cout << count;
//}



////�ð��ʰ�
//#include <iostream>
//#include <set>
//using namespace std;
//int main()
//{
//    long long min;
//    long long max;
//    long long count = 0;
//    set<long long> Set;
//
//    cin >> min;
//    cin >> max;
//
//    for (long long i = 2; i * i <= max; i++)
//    {
//        long long Pow = i * i;
//        for (long long j = min/Pow; Pow * j <= max; j++)
//        {
//            if (Pow * j >= min && Pow * j <= max)
//            {
//                Set.insert(Pow * j);
//            }
//        }
//    }
//    cout << (max - min + 1) - Set.size();
//}




////�ð��ʰ�
//#include <iostream>
//using namespace std;
//int main()
//{
//    long long min;
//    long long max;
//    long long count = 0;
//
//    cin >> min;
//    cin >> max;
//
//    for (long long i = min; i <= max; i++)
//    {
//        for (int j = 2; j <= max; j++)
//        {
//            int Pow = j * j;
//            if (Pow > max)
//            {
//                break;
//            }
//            if (i % Pow == 0)
//            {
//                count++;
//                break;
//            }
//        }
//    }
//    cout << (max - min + 1) - count;
//}