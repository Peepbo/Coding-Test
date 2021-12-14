#include <iostream>
#include <vector>
#include <queue>

int dp[1'000'001];

using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue<vector<int>> q;
	int N;
	cin >> N;
	fill(dp, dp + N + 1, 500'000);

	q.push({ {N} });
	while (!q.empty()) {
		auto vec = q.front();
		q.pop();

		if (dp[vec.back()] <= vec.size())continue;
		dp[vec.back()] = vec.size();

		if (vec.back() == 1) {
			cout << vec.size() - 1 << '\n';
			for (const int& num : vec) {
				cout << num << ' ';
			}
			break;
		}

		if (vec.back() % 3 == 0) {
			vec.emplace_back(vec.back() / 3);
			q.push(vec);
			vec.pop_back();
		}
		if (vec.back() % 2 == 0) {
			vec.emplace_back(vec.back() / 2);
			q.push(vec);
			vec.pop_back();
		}
		vec.emplace_back(vec.back() - 1);
		q.push(vec);
		vec.pop_back();
	}

	return 0;
}