#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> dq;
    unordered_map<string, int> um;

    for (int i = 0; i < cities.size(); i++)
    {
        for (int j = 0; j < cities[i].size(); j++)
        {
            cities[i][j] = tolower(cities[i][j]);
        }

        if (um.find(cities[i]) != um.end())//있으면
        {
            answer++;

            int idx = um[cities[i]];
            dq.erase(dq.begin() + idx); // 해당 값을 지우고
            dq.push_back(cities[i]); // 다시 뒤로 푸시

            for (int j = 0; j < dq.size(); j++)
            {
                um[dq[j]] = j;
            }
        }
        else//없으면
        {
            answer += 5;

            um[cities[i]] = dq.size();
            dq.push_back(cities[i]); // 뒤에 넣고

            if (dq.size() > cacheSize) // 크기가 초과하면
            {
                um.erase(dq.front());
                dq.pop_front(); //앞을 pop한다.

                for (int j = 0; j < dq.size(); j++)
                {
                    um[dq[j]] = j;
                }
            }
        }
    }

    return answer;
}

int main()
{
    cout << solution(3, { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" });

    return 0;
}