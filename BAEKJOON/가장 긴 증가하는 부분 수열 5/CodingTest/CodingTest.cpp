#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define INF 1'000'000'001

int arr[1'000'001];
int p[1'000'001];
vector<int> v{ -INF };

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, input, LIS, temp;
	stack<int> s;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr[i] = input;
		if (v.back() < input) {
			p[i] = v.size();
			v.emplace_back(input);
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), input);
			*it = input;
			p[i] = distance(v.begin(), it);
		}
	}

	LIS = temp = v.size() - 1;
	cout << LIS << '\n';
	
	for (int i = N - 1; i >= 0; i--) {
		if (temp == p[i]) {
			s.push(arr[i]);
			temp--;
		}
	}

	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}