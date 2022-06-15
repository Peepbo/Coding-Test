#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string N;
	cin >> N;
	sort(N.begin(), N.end(), greater<>());

	cout << N;
	return 0;
}