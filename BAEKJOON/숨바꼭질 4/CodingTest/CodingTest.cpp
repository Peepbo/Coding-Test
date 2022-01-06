#include <iostream>
#include <queue>
#include <stack>

using namespace std;

#define MAXIMUM 200'000
#define MAXIMUM_K 100'000

int dp[MAXIMUM + 1];
int prevDp[MAXIMUM + 1];
int N, K;

queue<pair<int, int>> q;
stack<int> s;

void MoveCharacter(int now, int next, int cnt) {
	if (dp[next] <= cnt + 1) return;

	dp[next] = cnt + 1;
	prevDp[next] = now;
	q.push({ next, cnt + 1 });
}

void pathBacktracking() {
	int tmp = K;
	
	while (tmp != N) {
		s.push(tmp);
		tmp = prevDp[tmp];
	}
	s.push(N);
}

void printShortestPath() {
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	fill(dp, dp + MAXIMUM, MAXIMUM);
	
	q.push({ N, 0 });
	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (now == K) {
			cout << cnt << '\n';
			break;
		}

		if (now > MAXIMUM_K)continue;
		if (now < 0)continue;

		MoveCharacter(now, now * 2, cnt);
		MoveCharacter(now, now + 1, cnt);
		MoveCharacter(now, now - 1, cnt);
	}

	pathBacktracking();

	printShortestPath();
}