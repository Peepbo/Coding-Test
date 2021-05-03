#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int Node[201];

int getParent(int a)
{
    if (Node[a] == a)return a;

    return Node[a] = getParent(Node[a]);
}

void unionParent(int a, int b)
{
    int A = getParent(a);
    int B = getParent(b);

    if (A < B)
        Node[B] = Node[A];
    else
        Node[A] = Node[B];
}

int solution(int n, vector<vector<int>> computers) {
    vector<pair<int, int>> v;
    unordered_set<int> s;

    for (int i = 0; i < n; i++)
    {
        Node[i] = i;

        for (int j = 0; j < n; j++)
        {
            if (i == j || computers[i][j] == 0)continue;

            v.emplace_back(i, j);
        }
    }

    for (int i = 0; i < v.size(); i++)
        unionParent(v[i].first, v[i].second);

    for (int i = 0; i < n; i++)
        s.insert(getParent(i));

    return s.size();
}

int main()
{
    //cout << solution(3, { {1,1,0},{1,1,0},{0,0,1} });
    //cout << solution(3, { {1,1,0},{1,1,1},{0,1,1} });
    cout << solution(5, { {1, 0, 0, 0, 0},{0, 1, 0, 0, 1},{0, 0, 1, 0, 1},{0, 0, 0, 1, 1},{1, 0, 0, 0, 1} });

    return 0;
}