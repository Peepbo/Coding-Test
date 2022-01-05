#include <iostream>
#include <stack>

using namespace std;

bool arr[1'000'001];

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, a, x, top, tmp, count = 0;
	stack<int> s;
	cin >> n;
	while (n--) {
		cin >> a;
		s.push(a);
		arr[a] = true;
	}
	cin >> x;

	while (!s.empty()) {
		top = s.top();
		tmp = x - top;
		s.pop();

		if (tmp <= 0)continue;
		if (tmp >= 1'000'000)continue;

		if (arr[tmp]) count++;
	}

	cout << count / 2;
}