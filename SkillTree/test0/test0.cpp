#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSkillTree(string str, char c)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)return true;
    }

    return false;
}


int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int i = 0; i < skill_trees.size(); i++)
    {
        int order = 0;
        bool can = true;

        for (int j = 0; j < skill_trees[i][j]; j++)
        {
            bool check = isSkillTree(skill, skill_trees[i][j]);

            //스킬트리에 존재함
            if (check)
            {
                if (skill[order] == skill_trees[i][j])
                {
                    if(order < skill.length()) order++;
                }

                else
                {
                    can = false;
                    break;
                }
            }
        }

        if (can)answer++;
    }

    return answer;
}

void main()
{
    cout << solution("CBD", { "BACDE","CBADF","AECB","BDA" });
}