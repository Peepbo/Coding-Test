#include <iostream>
#include <deque>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	deque<int> dq;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	while (--N) {
		dq.pop_front();
		dq.push_back(dq.front());
		dq.pop_front();
	}

	cout << dq.front();
	return 0;
}