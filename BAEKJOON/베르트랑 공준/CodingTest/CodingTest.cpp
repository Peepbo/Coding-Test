#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	const int decimalSize = 123456 * 2, halfSize = 123456;

	vector<int> output;
	vector<bool> isDecimal(decimalSize + 1, true);

	isDecimal[0] = isDecimal[1] = false;

	for (int i = 2; i <= halfSize; i++) {
		if (isDecimal[i] == false) continue;

		for (int j = i * 2; j <= decimalSize; j += i) {
			isDecimal[j] = false;
		}
	}

	while (true) {
		int N, count = 0;
		cin >> N;

		if (N == 0)break;

		for (int i = N + 1; i <= 2 * N; i++) {
			if (isDecimal[i])count++;
		}

		output.emplace_back(count);
	}

	for (const int& num : output) {
		cout << num << '\n';
	}

	return 0;
}