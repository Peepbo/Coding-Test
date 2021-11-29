#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	stack<int> s;
	int K, N, sum = 0;
	cin >> K;

	while (K--) {
		cin >> N;
		if (N != 0) {
			s.push(N);
		}
		else {
			s.pop();
		}
	}

	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum;
	return 0;
}