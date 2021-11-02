#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

#define INF 1000001

const int mX[4]{ -1,1,0,0 };
const int mY[4]{ 0,0,-1,1 };
char matrix[1001][1001];
int dist[1001][1001][2];

int main(void) {
	string input;
	int N, M, output = -1;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> input;
		for (int j = 1; j <= M; j++) {
			matrix[i][j] = input[j - 1];
			dist[i][j][0] = dist[i][j][1] = INF;
		}
	}
	dist[1][1][0] = dist[1][1][1] = 1;

	// x,y,cost,bool
	queue<tuple<int, int, int, bool>> q;
	q.push(make_tuple(1, 1, 1, true));

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int cost = get<2>(q.front());
		bool skill = get<3>(q.front());
		q.pop();

		if (x == M && y == N) {
			output = cost;
			break;
		}

		for (int i = 0; i < 4; i++) {
			if (x + mX[i] == 0 || x + mX[i] > M)continue;
			if (y + mY[i] == 0 || y + mY[i] > N)continue;

			bool useSkill = false;
			if (matrix[y + mY[i]][x + mX[i]] == '1') {
				if (skill == false)continue;
				useSkill = true;
			}

			const bool haveSkill = useSkill == false ? skill : false;

			if (dist[y + mY[i]][x + mX[i]][haveSkill] > cost + 1) {
				dist[y + mY[i]][x + mX[i]][haveSkill] = cost + 1;
				q.push(make_tuple(x + mX[i], y + mY[i], cost + 1, haveSkill));
			}
		}
	}

	cout << output;

	return 0;
}