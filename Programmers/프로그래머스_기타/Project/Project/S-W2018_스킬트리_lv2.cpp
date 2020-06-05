//스킬트리가 있을때 스킬트리중 가능한 스킬트리 갯수 구하기
//스킬트리는 첫번째 대문자 알파벳로 표현
//스킬트리의 포함안되는 스킬도 있음
//중복없음

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int i = 0; i < skill_trees.size(); i++)
    {
        int skill_order = 0;
        string skill_tree = skill_trees[i];
        bool suc = true;
        for (int j = 0; j < skill_tree.length(); j++)
        {
            char alpha = skill_tree[j];
            for (int k = skill_order; k < skill.length(); k++)
            {
                if (alpha == skill[k])
                {
                    if (k == skill_order)
                        skill_order++;
                    else
                        suc = false;
                    break;
                }
            }
            if (!suc)
                break;
        }
        if (suc)
            answer++;
    }
    return answer;
}
int main()
{
    string skill = "CBD";
    vector<string> skill_trees = { "BACDE", "CBADF", "AECB", "BDA" };

    cout << solution(skill, skill_trees) << endl;
}