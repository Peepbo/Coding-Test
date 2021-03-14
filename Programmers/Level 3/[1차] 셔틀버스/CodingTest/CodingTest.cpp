#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <unordered_set>

using namespace std;

int arr[101][101];
bool visit[101];
int minCost = -1;
unordered_set<int> s;

void DP(const int& number, int cost,const int& cycle)
{
    if (s.size() == cycle)
    {
        for (const auto& it : s)
        {
            cout << it << ' ';
        }
        cout << '\n';
        cout << "end!" << '\n';

        if (minCost == -1)minCost = cost;
        else minCost = min(minCost, cost);
        cout << "minCost : " << minCost << "\n\n";
        return;
    }

    cout << "num : " << number << '\n';
    cout << "now cost : " << cost << "\n\n";

    s.insert(number);

    for (const auto& it : s)
    {
        cout << it << '-';
    }
    cout << "\n\n";

    for (int i = 0; i < cycle; i++)
    {
        if (arr[number][i] == 0 && visit[i]) continue;

        int plus;
        if (!visit[i])
        {
            plus = arr[number][i];
        }
        else plus = 0;

        cout << number << "->" << i << '\n';

        //cost += plus;
        arr[number][i] = 0;
        visit[i] = true;

        DP(i, cost + plus, cycle);

        //cost -= plus;
        arr[number][i] = plus;
        visit[i] = false;
    }

    s.erase(number);
}

int solution(int n, vector<vector<int>> costs) {
    int temp;
    for (const auto& it : costs)
    {
        int land0 = it[0];
        int land1 = it[1];
        int cost = it[2];

        arr[land0][land1] = cost;
        arr[land1][land0] = cost;
    }

    visit[0] = true;
    temp = 0;
    DP(0, temp, n);

    return minCost;
}

int main()
{
    //cout<< solution(4, { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} });
    cout << solution(5, { {0,1,1},{3,1,1},{0,2,2},{0,2,2},{0,3,2},{0,4,100} });
 
    return 0;
}