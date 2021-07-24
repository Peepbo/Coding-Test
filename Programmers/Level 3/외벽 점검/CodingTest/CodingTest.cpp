#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

#define INF 999999999
using namespace std;

int minCost = INF;
int N, WeakSize;
vector<int> Weak, Dist;

void solve(int cnt, int now, int visitCnt) {
	if (cnt == Dist.size())return;
	if (cnt + 1 >= minCost) return;

	for (int i = 0; i < WeakSize; i++) {
		int next = (now + i) % WeakSize;
		int diff = Weak[next] - Weak[now];

		if (diff < 0)
			diff += N;

		if (diff > Dist[cnt])
			break;

		visitCnt |= (1 << next);
	}

	if (visitCnt == (1 << WeakSize) - 1) {
		minCost = cnt;
		return;
	}

	for (int i = 0; i < WeakSize; i++) {
		if (visitCnt & (1 << i)) continue;

		solve(cnt + 1, i, visitCnt);
	}
}

int solution(int n, vector<int> weak, vector<int> dist) {
	sort(dist.begin(), dist.end(), greater<>());
	N = n;
	Weak = weak;
	WeakSize = Weak.size();
	Dist = dist;

	for (int i = 0; i < WeakSize; i++) {
		solve(0, i, 0);
	}

	return minCost != INF ? minCost : -1;
}

int main() {
	//cout << solution(12, { 1,5,6,10 }, { 1,2,3,4 });
	cout << solution(12, { 1,3,4,9,10 }, { 3,5,7 });

	return 0;
}