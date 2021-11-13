#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void) {
	stack<int> s; // idx
	int A, idx = 0;
	cin >> A;

	vector<int> sequence(A), NGE(A, -1);
	for (int i = 0; i < A; i++) {
		cin >> sequence[i];
	}

	s.push(idx++);

	while (idx < A) {
		int now = sequence[idx];
		int last = s.empty() ? now + 1 : sequence[s.top()];

		if (last < now) {
			NGE[s.top()] = now;
			s.pop();
		}
		else {
			s.push(idx++);
		}
	}

	for (const int& num : NGE) {
		cout << num << ' ';
	}

	return 0;
}