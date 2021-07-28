#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;

	for (const auto& num : numbers) {
		if (num % 2 == 0) {
			answer.emplace_back(num + 1);
			continue;
		}

		long long temp = num;
		int zeroIndex = 0;
		while (temp > 0) {
			//isZero?
			if (temp % 2 == 0) break;

			zeroIndex++;
			temp /= 2;
		}

		answer.emplace_back(num + pow(2, zeroIndex) - pow(2, zeroIndex - 1));
	}

	return answer;
}

int main() {
	auto v = solution({ 13 });
	for (auto it : v) {
		cout << it << ' ';
	}

	return 0;
}