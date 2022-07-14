#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> Link;
vector<int> Weight;
int DP[10'001][2];
vector<int> Path;

void DFS(int Index, int Prev)
{
	const bool bReturn = DP[Index][0] + DP[Index][1] > 0;
	if (bReturn)
	{
		return;
	}
	DP[Index][1] = Weight[Index];

	for (int Next : Link[Index])
	{
		if (Next == Prev)
		{
			continue;
		}

		DFS(Next, Index);

		DP[Index][0] += max(DP[Next][0], DP[Next][1]);
		DP[Index][1] += DP[Next][0];
	}
}

void BackTrace(int Index, int Prev, bool PrevVisit)
{
	bool bVisit = false;
	if (DP[Index][0] < DP[Index][1] && !PrevVisit)
	{
		bVisit = true;
		Path.emplace_back(Index);
	}

	for (int Next : Link[Index])
	{
		if (Next != Prev)
		{
			BackTrace(Next, Index, bVisit);
		}
	}
}

void Init()
{
	int n;
	cin >> n;
	int u, v;

	Link.assign(n + 1, {});
	Weight.assign(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> Weight[i];
	}
	for (int i = 1; i < n; i++)
	{
		cin >> u >> v;
		Link[u].emplace_back(v);
		Link[v].emplace_back(u);
	}
}

void Print()
{
	cout << max(DP[1][0], DP[1][1]) << '\n';
	for (int Idx : Path)
	{
		cout << Idx << ' ';
	}
}

void Solve()
{
	Init();

	DFS(1, 0);
	BackTrace(1, 0, false);

	sort(Path.begin(), Path.end());
} 

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();
	Print();

	return 0;
}