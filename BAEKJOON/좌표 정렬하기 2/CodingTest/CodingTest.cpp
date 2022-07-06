#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> P1, pair<int, int> P2)
{
	if (P1.second != P2.second)
	{
		return P1.second < P2.second;
	}
	return P1.first < P2.first;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, X, Y;
	cin >> N;
	vector<pair<int,int>> Points(N);
	while (N--)
	{
		cin >> X >> Y;
		Points[N] = { X, Y };
	}
	sort(Points.begin(), Points.end(), compare);
	for (const pair<int, int>& P : Points)
	{
		cout << P.first << ' ' << P.second << '\n';
	}
	return 0;
}