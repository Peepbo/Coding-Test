#include <iostream>

using namespace std;

int N, W, dp[1'001][1'001];
pair<int, int> arr[1'001];

int dist(pair<int,int> a, pair<int,int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int totalDist(int a, int b) {
	if (a == W || b == W)return 0;
	if (dp[a][b] != -1)return dp[a][b];

	int next = max(a, b) + 1;
	int dist1, dist2;

	if (a == 0)dist1 = dist({ 1,1 }, arr[next]);
	else dist1 = dist(arr[a], arr[next]);

	if (b == 0)dist2 = dist({ N,N }, arr[next]);
	else dist2 = dist(arr[b], arr[next]);

	int result1 = dist1 + totalDist(next, b);
	int result2 = dist2 + totalDist(a, next);
	dp[a][b] = min(result1, result2);
	return dp[a][b];
}

void findRoute(int a, int b) {
	if (a == W || b == W)return;

	int next = max(a, b) + 1;
	int dist1, dist2;

	if (a == 0)dist1 = dist({ 1,1 }, arr[next]);
	else dist1 = dist(arr[a], arr[next]);

	if (b == 0)dist2 = dist({ N,N }, arr[next]);
	else dist2 = dist(arr[b], arr[next]);

	if (dp[next][b] + dist1 < dp[a][next] + dist2) {
		cout << 1 << '\n';
		findRoute(next, b);
	}
	else {
		cout << 2 << '\n';
		findRoute(a, next);
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tempW, x, y, index = 1;
	cin >> N >> W;
	tempW = W;

	while (tempW--) {
		cin >> x >> y;
		arr[index] = { x,y };
		index++;
	}
	memset(dp, -1, sizeof(dp));

	cout << totalDist(0, 0) << '\n';
	findRoute(0, 0);
	return 0;
}