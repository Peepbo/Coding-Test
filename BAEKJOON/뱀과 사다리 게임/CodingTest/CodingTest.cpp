#include <iostream>
#include <queue>

using namespace std;

#define MAX 100

int Board[101];
int Link[101];

int GetLink(int Index)
{
	if (Link[Index] == Index)
	{
		return Index;
	}
	return GetLink(Link[Index]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	int x, y;
	
	while (N--)
	{
		cin >> x >> y;
		Link[x] = y;
	}
	while (M--)
	{
		cin >> x >> y;
		Link[x] = y;
	}

	// Init
	for (int i = 1; i <= 100; i++)
	{
		Board[i] = MAX;

		if (Link[i] == 0)
		{
			Link[i] = i;
		}
	}

	queue<pair<int, int>> GameQueue;
	GameQueue.push({ 0, 1 });
	while (!GameQueue.empty())
	{
		int Count = GameQueue.front().first;
		int Index = GameQueue.front().second;
		GameQueue.pop();

		int NextIndex, NextCount = Count + 1;
		for (int i = 6; i >= 1; i--)
		{
			NextIndex = Index + i > MAX ? MAX : GetLink(Index + i);

			if (Board[NextIndex] > NextCount)
			{
				Board[NextIndex] = NextCount;

				if (NextIndex != MAX)
				{
					GameQueue.push({ NextCount,NextIndex });
				}
			}
		}
	}

	cout << Board[100];
	return 0;
}