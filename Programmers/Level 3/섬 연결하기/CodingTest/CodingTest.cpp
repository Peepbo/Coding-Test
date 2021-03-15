#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int father[101];

struct Edge {
    int dist; //distance
    int s, e; //start, end

    void AddEdge(int a, int b, int c)
    {
        dist = a;
        s = b;
        e = c;
    }
};

// Search parent node
int getParent(int x)
{
    if (father[x] == x) return x;
    return father[x] = getParent(father[x]);
}

// Union to parent node
void unionParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);

    if (a < b)father[b] = a;
    else father[a] = b;
}

// return whether same parent exists or not
bool findParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);

    if (a == b) return true;
    
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int len = costs.size();
    vector<Edge> v(len);

    for (auto& it : costs)
        swap(it[0], it[2]);

    sort(costs.begin(), costs.end());

    for (int i = 0; i < len; i++)
        v[i].AddEdge(costs[i][0], costs[i][1], costs[i][2]);

    for (int i = 0; i < n; i++)
        father[i] = i;

    for (int i = 0; i < len; i++)
    {
        if (findParent(v[i].s, v[i].e)) continue;

        answer += v[i].dist;
        unionParent(v[i].s, v[i].e);
    }

    v.clear();

    return answer;
}

int main()
{
    //cout<< solution(4, { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} });
    //cout << solution(5, { {0,1,1},{2,3,1},{3,4,2},{1,2,2},{0,4,100} });
    cout << solution(6, { {0,1,5},{0,3,2},{0,4,3},{1,4,1},{3,4,10},{1,2,2},{2,5,3},{4,5,4} });
 
    return 0;
}