#include <iostream>
#include <vector>

using namespace std;

#define INF 10'000'000

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<int> SumList(N);

	int Input, Maximum = -INF;
	for (int i = 0; i < N; i++) 
	{
		cin >> Input;

		SumList[i] = Input;
		if (i > 0)
		{
			SumList[i] += SumList[i - 1];
		}
	}

	int s = 0, e = K - 1;
	while (e < N)
	{
		int Sum = SumList[e];
		if (s > 0)
		{
			Sum -= SumList[s - 1];
		}
		Maximum = max(Maximum, Sum);

		s++; e++;
	}

	cout << Maximum;
	return 0;
}