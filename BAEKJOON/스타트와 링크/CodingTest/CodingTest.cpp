#include <iostream>
#include <vector>

using namespace std;

#define INF 999999999;

int N, halfN, arr[21][21], diff = INF;

int getDiff(int startTeamBitMask) {
	vector<int> sTeam, lTeam;
	int sTeamValue = 0, lTeamValue = 0;

	for (int i = 1; i <= N; i++) {
		if (startTeamBitMask & (1 << i)) { //bit on
			sTeam.emplace_back(i);
		}
		else {
			lTeam.emplace_back(i);
		}
	}

	for (const int& num1 : sTeam) {
		for (const int& num2 : sTeam) {
			if (num1 == num2)continue;

			sTeamValue += arr[num1][num2];
		}
	}

	for (const int& num1 : lTeam) {
		for (const int& num2 : lTeam) {
			if (num1 == num2)continue;

			lTeamValue += arr[num1][num2];
		}
	}

	return abs(sTeamValue - lTeamValue);
}

// bitmask
void solve(int count, int startTeam, int index) {
	if (count == halfN) {
		diff = min(diff, getDiff(startTeam));
		return;
	}

	solve(count + 1, startTeam | (1 << index), index + 1);
	if (N - index >= halfN - count) {
		solve(count, startTeam, index + 1);
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	halfN = N / 2;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	solve(0, 0, 1);

	cout << diff;
	return 0;
}