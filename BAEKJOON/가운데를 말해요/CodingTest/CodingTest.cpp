#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> maxHip;
priority_queue<int, vector<int>, greater<int>> minHip;

void pushHip(int x) {
	if (maxHip.empty()) {
		maxHip.push(x);
	}
	else if (minHip.empty()) {
		if (maxHip.top() < x) {
			minHip.push(x);
		}
		else {
			maxHip.push(x);
		}
	}
	else if (maxHip.top() > x) {
		maxHip.push(x);
	}
	else if (minHip.top() < x) {
		minHip.push(x);
	}
	else { // maxHip.top() <= x <= minHip.top()
		maxHip.push(x);
	}
}

int getMedian() {
	int sub = maxHip.size() - minHip.size(), output = 0;

	if (sub == 0 || sub == 1) {
		output = maxHip.top();
	}
	else if (sub == -1) {
		output = minHip.top();
	}
	else if (sub == 2) {
		minHip.push(maxHip.top());
		maxHip.pop();
		output = maxHip.top();
	}
	else if (sub == -2) {
		maxHip.push(minHip.top());
		minHip.pop();
		output = maxHip.top();
	}

	return output;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, x;
	cin >> N;
	while (N--) {
		cin >> x;

		pushHip(x);

		cout << getMedian() << '\n';
	}
}