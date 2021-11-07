#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void) {
	vector<char> message;
	stack<int> s;
	int n, ptr = 0, num = 1;
	cin >> n;

	vector<int> sequence(n);
	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	while (ptr < n) {
		if (s.empty() || s.top() < sequence[ptr]) {
			s.push(num++);
			message.emplace_back('+');
		}
		else if (s.top() == sequence[ptr]) {
			s.pop();
			message.emplace_back('-');
			ptr++;
		}
		else {
			cout << "NO";
			return 0;
		}
	}

	for (const char& ch : message) {
		cout << ch << '\n';
	}
	return 0;
}