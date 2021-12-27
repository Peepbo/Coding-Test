#include <iostream>
#include <vector>

using namespace std;

int arr[101];

vector<int> get(int a) {
	vector<int> output{ a };

	for (int i = a / 2; i > 1; i--) {
		if (a % i == 0) {
			output.emplace_back(i);
		}
	}

	return output;
}

void solve(int a, int b) {
	vector<int> way = get(b);
	bool isEnd = true;

	if (way.front() != 1) {
		for (const int& w : way) {
			if (a % w == 0) {
				solve(a / w, b / w);
				isEnd = false;
				break;
			}
		}
	}

	if (isEnd) {
		cout << a << '/' << b << '\n';
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	cin >> arr[1];
	
	for (int i = 2; i <= N; i++) {
		cin >> arr[i];
		solve(arr[1], arr[i]);
	}
}