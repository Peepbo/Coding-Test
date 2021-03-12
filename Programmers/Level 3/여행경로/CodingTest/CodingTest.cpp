#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> output;

void DFS(string start, vector<string>& save,vector<vector<string>>& tickets, vector<bool>& visit, int depth, const int& end)
{
    save.emplace_back(start);

    if (depth == end)
    {
        if (!output.empty())return;
        output = save;

        return;
    }

    for (int i = 0; i < tickets.size(); i++)
    {
        if (start == tickets[i][0] &&!visit[i])
        {
            visit[i] = true;
            DFS(tickets[i][1], save, tickets, visit, depth + 1, end);
            visit[i] = false;
        }
    }

    save.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {

    vector<bool> visit(tickets.size());
    vector<string> write;
    sort(tickets.begin(), tickets.end());
    DFS("ICN", write, tickets, visit, 0, tickets.size());

    return output;
}

int main()
{
    //auto a = solution({ {"ICN","JFK"},{"HND","IAD"},{"JFK","HND"} });
    auto a = solution({ {"ICN","SFO"},{"ICN","ATL"},{"SFO","ATL"},{"ATL","ICN"},{"ATL","SFO"} });

    for (const auto& it : a)
    {
        cout << it << ' ';
    }
    //cout << "\n\n";
    return 0;
}