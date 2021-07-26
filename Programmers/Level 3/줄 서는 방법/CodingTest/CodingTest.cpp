#include <iostream>
#include <vector>

using namespace std;

long long factorial[21];
vector<int> answer;

void getFactorial(int n) {
	factorial[1] = 1;
	for (int i = 2; i <= n; i++) {
		factorial[i] = factorial[i - 1] * i;
	}
}

void solve(vector<int>& vec, const long long& n, const long long& k) {
	if (vec.size() == 1) {
		answer.emplace_back(vec.front());
		return;
	}

	const long long div = factorial[n - 1];
	const long long index = k / div;
	const long long nextK = k % div;

	answer.emplace_back(vec[index]);
	vec.erase(vec.begin() + index);

	solve(vec, n - 1, nextK);
}

vector<int> solution(int n, long long k) {
	vector<int> vec(n);
	int plus = 1;

	for (int& num : vec) {
		num = plus++;
	}

	if (k == 0) return vec;

	getFactorial(n);

	solve(vec, n, k - 1);

	return answer;
}

int main() {
	auto a = solution(3, 5);

	for (const auto& it : a) {
		cout << it << ' ';
	}

	return 0;
}