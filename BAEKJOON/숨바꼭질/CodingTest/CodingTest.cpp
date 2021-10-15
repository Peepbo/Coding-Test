#include <iostream>
#include <queue>

using namespace std;

#define INF 999999999
#define END 100000

int dist[END + 1];

int main(void) {
	int N, K;
	cin >> N >> K;

	if (K == 0) {
		cout << N;
	}
	else if (N > K) {
		cout << N - K;
	}
	else {
		for (int i = 0; i <= END; i++) {
			dist[i] = INF;
		}
		dist[N] = 0;

		queue<int> q;
		q.push(N);

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			if (x != K) {
				if (x > K) {
					dist[K] = min(dist[K], dist[x] + x - K);
					continue;
				}
				else {
					int nX = 0;
					for (int i = -1; i <= 1; i++) {
						if (i != 0) {
							nX = x + i;
						}
						else {
							nX = x * 2;
						}

						if (nX < 0)continue;
						if (nX > K) {
							dist[K] = min(dist[K], dist[x] + 1 + nX - K);
							continue;
						}
						if (dist[nX] <= dist[x] + 1)continue;
						dist[nX] = dist[x] + 1;
						q.push(nX);
					}
				}
			}
		}

		cout << dist[K];
	}

	return 0;
}