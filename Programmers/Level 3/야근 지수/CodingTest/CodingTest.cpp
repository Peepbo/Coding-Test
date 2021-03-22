#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<long long> pq;

    for (const auto& it : works)
        pq.push(it);

    for (int i = 0; i < n; i++)
    {
        if (pq.empty())break;

        int top = pq.top() - 1;
        pq.pop();

        if (top != 0)pq.push(top);
    }

    if (pq.empty()) return answer;

    else
    {
        while (!pq.empty())
        {
            answer += pq.top() * pq.top();
            pq.pop();
        }
    }

    return answer;
}

int main()
{
    //cout << solution(4, { 4,3,3 });
    //cout << solution(1, { 2,1,2 });
    cout << solution(3, { 1,1 });

    return 0;
}