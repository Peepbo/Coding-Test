#include <iostream>
#include <queue>

using namespace std;

#define MAX 999'999

int Dist[200'001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i <= 200'000; i++)
	{
		Dist[i] = MAX;
	}

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({ 0,N });
	Dist[N] = 0;
	while (!pq.empty())
	{
		int cnt = pq.top().first;
		int pos = pq.top().second;
		pq.pop();

		if (pos == K)
		{
			if (Dist[K] > cnt)
			{
				Dist[K] = cnt;
				break;
			}
		}
		else if (pos > K)
		{
			if (Dist[K] > cnt + pos - K)
			{
				Dist[K] = cnt + pos - K;
			}
			continue;
		}

		int tPos = pos * 2;
		if (Dist[tPos] > cnt)
		{
			Dist[tPos] = cnt;
			pq.push({ cnt, tPos });
		}
		if (Dist[pos + 1] > cnt + 1)
		{
			Dist[pos + 1] = cnt + 1;
			pq.push({ cnt + 1, pos + 1 });
		}
		if (Dist[pos - 1] > cnt + 1)
		{
			Dist[pos - 1] = cnt + 1;
			pq.push({ cnt + 1, pos - 1 });
		}
	}

	cout << Dist[K];
	return 0;
}