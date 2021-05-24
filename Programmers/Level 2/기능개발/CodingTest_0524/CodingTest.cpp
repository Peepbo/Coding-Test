#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int loopSize = progresses.size(), save = 0, remain, work;

    for (int i = 0; i < loopSize; i++)
    {
        remain = 100 - progresses[i];
        work = remain / speeds[i];

        if (remain % speeds[i] != 0) work++;

        if (save != 0 && save >= work)
        {
            answer[answer.size() - 1]++;
        }
        else
        {
            answer.emplace_back(1);
            save = work;
        }
    }

    return answer;
}

int main()
{
    //auto vec = solution({ 93,30,55 }, { 1,30,5 });
    auto vec = solution({ 95,90,99,99,80,99 }, { 1,1,1,1,1,1 });
    for (auto& it : vec)
    {
        cout << it << ' ';
    }
}