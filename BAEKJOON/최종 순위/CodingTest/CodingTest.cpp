#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

int InDegree[501];
vector<int> Link[501];
int Rank[501];

void TopologySort(int N)
{
	queue<int> SolutionQueue;
	for (int i = 1; i <= N; i++)
	{
		if (InDegree[i] == 0)
		{
			SolutionQueue.push(i);
		}
	}

	vector<int> PrintVector;

	while (!SolutionQueue.empty())
	{
		if (SolutionQueue.size() > 1)
		{
			cout << '?' << '\n';
			return;
		}

		int Select = SolutionQueue.front();
		SolutionQueue.pop();

		PrintVector.emplace_back(Select);
		for (int Next : Link[Select])
		{
			if (--InDegree[Next] == 0)
			{
				SolutionQueue.push(Next);
			}
		}
	}

	if (PrintVector.size() != N)
	{
		cout << "IMPOSSIBLE" << '\n';
		return;
	}
	for (int Order : PrintVector)
	{
		cout << Order << ' ';
	}
	cout << '\n';
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	int n, t, m, a, b;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			Link[i].clear();
		}

		for (int i = 1; i <= n; i++)
		{
			cin >> t;
			Rank[i] = t;
			InDegree[i] = 0;
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				Link[Rank[i]].emplace_back(Rank[j]);
				InDegree[Rank[j]]++;
			}
		}

		cin >> m;
		while (m--)
		{
			cin >> a >> b;

			// b가 a앞에 있을 때
			auto It = find(Link[b].begin(), Link[b].end(), a);
			if (It != Link[b].end())
			{
				Link[b].erase(It);
				Link[a].emplace_back(b);
				InDegree[a]--;
				InDegree[b]++;
			}
			else
			{
				It = find(Link[a].begin(), Link[a].end(), b);
				Link[a].erase(It);
				Link[b].emplace_back(a);
				InDegree[b]--;
				InDegree[a]++;
			}
		}

		TopologySort(n);
	}

	return 0;
}