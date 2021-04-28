#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int getRank(int value)
{
    if (value > 1) return 7 - value;
    return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int max = 0, min = 0;

    unordered_set<int> uSet;
    for (const int& num : win_nums)
    {
        uSet.insert(num);
    }

    for (const int& num : lottos)
    {
        if (num == 0)max++;

        else if (uSet.find(num) != uSet.end())
        {
            max++;
            min++;
        }
    }

    return { getRank(max),getRank(min) };
}

int main()
{
    auto vec = solution({ 45,4,35,20,3,9 }, { 20,9,3,45,4,35 });

    for (const auto& it : vec)
    {
        cout << it << ' ';
    }
}