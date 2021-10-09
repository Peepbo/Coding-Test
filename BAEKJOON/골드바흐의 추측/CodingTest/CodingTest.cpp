#include <iostream>
#include <vector>

using namespace std;

#define INF 99999999

int main(void) {
	const int maxSize = 10000, halfSize = 5000;
	int T, n;

	vector<pair<int, int>> output;
	vector<int> decimalNum;
	vector<bool> decimal(maxSize + 1, true);
	decimal[0] = decimal[1] = false;

	for (int i = 2; i <= halfSize; i++) {
		if (decimal[i] == false)continue;

		for (int j = i * 2; j <= maxSize; j += i) {
			decimal[j] = false;
		}
	}

	for (int i = 2; i <= maxSize; i++) {
		if (decimal[i]) {
			decimalNum.emplace_back(i);
		}
	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		pair<int, int> minPartition;
		int diff = INF;

		for (const int& dNum : decimalNum) {
			if (dNum > n - dNum)break;

			if (decimal[n - dNum]) {
				if (diff > (n - dNum) - dNum) {
					diff = (n - dNum) - dNum;
					minPartition = { dNum, n - dNum };
				}
			}
		}

		output.emplace_back(minPartition);
	}

	for (const pair<int, int>& pr : output) {
		printf("%d %d\n", pr.first, pr.second);
	}

	return 0;
}