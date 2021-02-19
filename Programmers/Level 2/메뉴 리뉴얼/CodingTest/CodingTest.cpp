#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool Select[20];
unordered_map<string, int> makeCourse;
unordered_map<int, int> maxCourse;

void DFS(string str,int r, int idx, int cnt)
{
    int len = str.size();

    if (cnt == r)
    {
        string make = "";

        for (int i = 0; i < len; i++)
        {
            if (Select[i] == true)
            {
                make += str[i];
            }
        }

        int count = ++makeCourse[make];

        if (maxCourse[make.size()] < count)
        {
            maxCourse[make.size()] = count;
        }

        return;
    }

    for (int i = idx; i < len; i++)
    {
        if (Select[i] == true)continue;
        Select[i] = true;

        DFS(str, r, i, cnt + 1);
        Select[i] = false;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    int ordersLen = orders.size();
    int courseLen = course.size();

    for (int i = 0; i < ordersLen; i++)
    {
        sort(orders[i].begin(), orders[i].end());
    }

    for (int i = 0; i < ordersLen; i++)
    {
        for (int j = 0; j < courseLen; j++)
        {
            if (orders[i].size() < course[j]) break;

            memset(Select, 0, 20);

            DFS(orders[i], course[j], 0, 0);
        }
    }

    for (const auto& m : makeCourse)
    {
        if (m.second > 1)
        {
            if (maxCourse[m.first.size()] != m.second)continue;

            answer.emplace_back(m.first);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    auto output = solution({ "ACD","CDE","ACDE" }, { 2,3,4 });

    //for (const auto& it : output)
    //{
    //    cout << it << '\n';
    //}
	return 0;
}