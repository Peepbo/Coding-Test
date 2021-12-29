#include <iostream>
#include <queue>

using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	priority_queue<int> pq;
	int N, x;
	cin >> N;
	while (N--) {
		cin >> x;
		
		if (x != 0) {
			pq.push(x);
		}
		else {
			if (!pq.empty()) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else {
				cout << 0 << '\n';
			}
		}
	}
}