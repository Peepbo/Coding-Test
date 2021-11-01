#include <iostream>
#include <queue>

using namespace std;

#define MAX 1'000'001
int arr[MAX];

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, num, count, n3, n2;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		arr[i] = MAX;
	}

	queue<pair<int, int>> q;
	q.push({ N, 0 });
	while (!q.empty()) {
		num = q.front().first;
		count = q.front().second;
		q.pop();

		if (num == 1) {
			cout << count;
			break;
		}

		if (num % 3 == 0) {
			n3 = num / 3;
			if (arr[n3] > count + 1) {
				arr[n3] = count + 1;
				q.push({ n3,count + 1 });
			}
		}
		if (num % 2 == 0) {
			n2 = num / 2;
			if (arr[n2] > count + 1) {
				arr[n2] = count + 1;
				q.push({ n2,count + 1 });
			}
		}

		if (arr[num - 1] > count + 1) {
			q.push({ num - 1, count + 1 });
		}

	}
	return 0;
}