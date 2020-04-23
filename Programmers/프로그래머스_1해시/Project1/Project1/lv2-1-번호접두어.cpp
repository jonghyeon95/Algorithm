//문제. 어느 한문자가 다른문자의 접두어가 되는걸 찾아라

//답지
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phoneBook) {
    bool answer = true;

    sort(phoneBook.begin(), phoneBook.end());

    for (int i = 0; i < phoneBook.size() - 1; i++)
    {
        if (phoneBook[i] == phoneBook[i + 1].substr(0, phoneBook[i].size()))
        {
            answer = false;
            break;
        }
    }

    return answer;
}
int main()
{
    vector<string> phone_book{ "1195", "1194", "97674223", "1195524421" };

    cout << solution(phone_book);
}


////수정본
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//using namespace std;
//bool Strlen(string a, string b)
//{
//    return a.length() < b.length();
//}
//bool solution(vector<string> phone_book)
//{
//    bool answer = true;
//    sort(phone_book.begin(), phone_book.end(), Strlen);
//
//    for (int i = 0; i < phone_book.size() - 1; i++)
//    {
//        for (int j = i + 1; j < phone_book.size(); j++)
//        {
//            if (phone_book[i] == phone_book[j].substr(0, phone_book[i].length()))
//            {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//int main()
//{
//    vector<string> phone_book{ "119", "97674223", "1195524421" };
//    cout << solution(phone_book);
//}




//처음코드
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//using namespace std;
//bool Strlen(string a, string b)
//{
//    return a.length() < b.length();
//}
//bool solution(vector<string> phone_book)
//{
//    bool answer = true;
//    sort(phone_book.begin(), phone_book.end(), Strlen);
//
//    for (int i = 0; i < phone_book.size()-1; i++)
//    {
//        for (int j = i+1; j < phone_book.size(); j++)
//        {
//            bool un_correct = true;
//            for (int k = 0; k < phone_book[i].size(); k++)
//            {
//                if (phone_book[i][k] == phone_book[j][k])
//                {
//                    un_correct = false;
//                }
//                else
//                {
//                    un_correct = true;
//                    break;
//                }
//            }
//            if (un_correct == false)
//            {
//                return false;
//            }
//        }
//    }
//
//    return true;
//}
//int main()
//{
//    vector<string> phone_book{ "119", "97674223", "1195524421" };
//    cout<<solution(phone_book);
//}
