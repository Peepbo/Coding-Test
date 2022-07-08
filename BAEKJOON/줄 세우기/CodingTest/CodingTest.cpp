#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int InDegree[32'001];
vector<vector<int>> Link;

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

	while (!SolutionQueue.empty())
	{
		int Select = SolutionQueue.front();
		SolutionQueue.pop();

		cout << Select << ' ';
		for (int Next : Link[Select])
		{
			if (--InDegree[Next] == 0)
			{
				SolutionQueue.push(Next);
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int A, B;
	Link.assign(N + 1, {});
	
	while (M--)
	{
		cin >> A >> B;
		Link[A].emplace_back(B);
		InDegree[B]++;
	}

	TopologySort(N);

	return 0;
}