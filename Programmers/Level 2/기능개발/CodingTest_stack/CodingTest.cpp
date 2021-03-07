#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int workingDays(const int& progress, const int& speed)
{
    if ((100 - progress) % speed == 0) return (100 - progress) / speed;
    return (100 - progress) / speed + 1;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> st;
    int idx = 0, len = progresses.size();
    st.push(workingDays(progresses[0], speeds[0]));
    answer.emplace_back(1);

    for (int i = 1; i < len; i++)
    {
        if (st.top() < workingDays(progresses[i], speeds[i]))
        {
            st.push(workingDays(progresses[i], speeds[i]));
            answer.emplace_back(1);
            idx++;
        }
        else
        {
            answer[idx]++;
        }
    }

    return answer;
}

int main()
{
    auto output = solution({ {93,30,55} }, { 1,30,5 });

    for (auto& it : output)
    {
        cout << it << ' ';
    }

    return 0;
}