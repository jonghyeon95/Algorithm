#include <string>
#include <vector>
#include<iostream>
using namespace std;
int solution(string key, vector<string> arr) {
    int answer = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        string str = arr[i];
        int keyidx = 0;
        bool suc = true;

        for (int j = 0; j < str.length(); j++)
        {
            if (suc)
            {
                for (int k = 0; k < key.length(); k++) 
                {
                    if (str[j] == key[k])
                    {
                        if (keyidx == k)
                        {
                            keyidx++;
                        }
                        else
                        {
                            suc = false;
                        }
                        break;
                    }
                }
            }
            else
            {
                suc = true;
                break;
            }
            if (j == str.length() - 1 && suc==true)
                answer++;
        }
    }

    return answer;
}
int main(void)
{
    //vector<string> arr = {"walbed", "ablkdc", "wac", "walbkcm", "wablcdq"}; //2°³
    vector<string> arr = { "walbed", "ablkdc", "wac", "walbkcm", "wablcdq" }; //2°³
    string key = "abcd";
    cout << solution(key,arr) << endl;
}