#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

#define INF 999999999

int dist[101][101];
int prevIdx[101][101];
int n, m;

void Init() {
	fill(dist[0], dist[101], INF);

	int a, b, c;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		if (dist[a][b] > c) {
			dist[a][b] = c;
		}
	}

	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}
}

void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || dist[i][j] == INF) {
				cout << "0 ";
			}
			else {
				cout << dist[i][j] << ' ';
			}
		}
		cout << '\n';
	}

	int totalDist;
	for (int i = 1; i <= n; i++) { // start
		for (int j = 1; j <= n; j++) { // end
			totalDist = dist[i][j];

			if (i == j || totalDist == INF) {
				cout << "0\n";
			}
			else {
				int a = i, b = j, c;

				stack<int> s;
				s.push(b);

				while (c = prevIdx[a][b]) {
					s.push(c);
					b = c;
				}
				s.push(a);

				cout << s.size();
				while (!s.empty()) {
					cout << ' ' << s.top();
					s.pop();
				}
				cout << '\n';
			}
		}
	}
}

void Floyd_Warshall() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];

					prevIdx[i][j] = prevIdx[k][j] != 0 ? prevIdx[k][j] : k;
				}
			}
		}
	}
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	Init();

	Floyd_Warshall();

	print();
	return 0;
}