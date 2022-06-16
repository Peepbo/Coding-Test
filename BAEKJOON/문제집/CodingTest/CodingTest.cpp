#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> Link;
int InDegree[32'001];

void TopologicalSort(int N)
{
	priority_queue<int, vector<int>, greater<int>> SolutionQueue;

	for (int i = 1; i <= N; i++)
	{
		if (InDegree[i] == 0)
		{
			SolutionQueue.push(i);
		}
	}

	int Now;
	while (!SolutionQueue.empty())
	{
		Now = SolutionQueue.top();
		SolutionQueue.pop();

		cout << Now << ' ';
		for (int Next : Link[Now])
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
	cin >> N;
	Link.assign(N + 1, {});
	int A, B;

	cin >> M;
	while (M--)
	{
		cin >> A >> B;
		Link[A].emplace_back(B);
		InDegree[B]++;
	}

	TopologicalSort(N);
	return 0;
}