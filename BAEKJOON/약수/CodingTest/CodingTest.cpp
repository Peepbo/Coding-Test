#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, num, low = 1'000'000, high = 2;
	cin >> N;
	while (N--) {
		cin >> num;
		low = min(low, num);
		high = max(high, num);
	}
	cout << low * high;
}