#include <iostream>
#include <deque>

using namespace std;

int main(void) {
	deque<int> dq, leftDp, rightDp;
	int N, M, num, cost = 0, leftMove, rightMove;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	while (M--) {
		cin >> num;

		if (dq.front() == num) {
			dq.pop_front();
		}

		else {
			leftDp = rightDp = dq;
			leftMove = rightMove = 0;

			while (leftDp.front() != num) {
				leftDp.push_back(leftDp.front());
				leftDp.pop_front();
				leftMove++;
			}

			while (rightDp.front() != num) {
				rightDp.push_front(rightDp.back());
				rightDp.pop_back();
				rightMove++;
			}

			cost += min(leftMove, rightMove);
			dq = leftDp;
			dq.pop_front();
		}
	}

	cout << cost;
	return 0;
}