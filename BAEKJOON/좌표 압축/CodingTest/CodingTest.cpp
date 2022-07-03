#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, X;
	cin >> N;
	map<int, int> SmallerValueMap;
	vector<int> Arr(N);
	for (int& i : Arr)
	{
		cin >> X;
		i = X;
		SmallerValueMap[i] = 0;
	}

	int SmallerValue = 0;
	for (auto& Iter : SmallerValueMap)
	{
		Iter.second = SmallerValue++;
	}

	for (const int& M : Arr)
	{
		cout << SmallerValueMap[M] << ' ';
	}
	return 0;
}