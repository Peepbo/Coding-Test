#include <iostream>
#include <tuple>
#include <queue>
#include <vector>

using namespace std;

#define INF 999999999

const int mX[8]{ 1,2,2,1,-1,-2,-2,-1 };
const int mY[8]{ -2,-1,1,2,2,1,-1,-2 };
int dist[300][300];

int main(void) {
	int T, I, sX, sY, eX, eY;
	cin >> T;
	vector<int> output(T);

	for (int i = 0; i < T; i++) {
		cin >> I;
		cin >> sX >> sY;
		cin >> eX >> eY;

		for (int a = 0; a < I; a++) {
			for (int b = 0; b < I; b++) {
				dist[a][b] = INF;
			}
		}
		dist[sX][sY] = 0;

		//x,y,cost
		queue<tuple<int, int, int>> q;
		q.push(make_tuple(sX, sY, 0));
		while (!q.empty()) {
			int x = get<0>(q.front());
			int y = get<1>(q.front());
			int cost = get<2>(q.front());
			q.pop();

			if (x == eX && y == eY) {
				output[i] = cost;
				break;
			}

			for (int j = 0; j < 8; j++) {
				if (x + mX[j] < 0 || x + mX[j] >= I)continue;
				if (y + mY[j] < 0 || y + mY[j] >= I)continue;

				if (dist[x + mX[j]][y + mY[j]] > cost + 1) {
					dist[x + mX[j]][y + mY[j]] = cost + 1;

					q.push(make_tuple(x + mX[j], y + mY[j], cost + 1));
				}
			}
		}
	}

	for (const int& num : output) {
		cout << num << '\n';
	}

	return 0;
}