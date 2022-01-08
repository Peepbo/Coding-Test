#include <iostream>
#include <queue>

using namespace std;

#define MAXIMUM 10'000

bool visited[MAXIMUM];
int A, B;

void bfs() {
	string write;
	int num, D, S, L, R;

	queue<pair<string, int>> q;
	q.push({ "", A });
	while (!q.empty()) {
		write = q.front().first;
		num = q.front().second;
		q.pop();

		if (num == B) {
			cout << write << '\n';
			break;
		}

		D = (num * 2) % MAXIMUM;
		if (!visited[D]) {
			visited[D] = true;
			q.push({ write + 'D', D });
		}

		S = num - 1 < 0 ? MAXIMUM - 1 : num - 1;
		if (!visited[S]) {
			visited[S] = true;
			q.push({ write + 'S', S });
		}

		L = (num % 1000) * 10 + (num / 1000);
		if (!visited[L]) {
			visited[L] = true;
			q.push({ write + 'L', L });
		}

		R = (num / 10) + (num % 10) * 1000;
		if (!visited[R]) {
			visited[R] = true;
			q.push({ write + 'R', R });
		}
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;

	cin >> T;
	while (T--) {
		fill(visited, visited + MAXIMUM, false);
		cin >> A >> B;
		
		bfs();
	}
}