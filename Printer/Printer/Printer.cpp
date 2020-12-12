#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int, int>> q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++)
    {
        q.push(pair<int, int>(i,priorities[i]));
        pq.push(priorities[i]);
    }

    while (q.empty() == false)
    {
        int i = q.front().first;
        int p = q.front().second;
        q.pop();

        if (p == pq.top())
        {
            pq.pop();
            answer++;

            if (i == location)break;
        }
        else q.push(pair<int, int>(i, p));
    }

    return answer;
}

int main()
{
    cout << solution({ 2,1,3,2 }, 2);
}