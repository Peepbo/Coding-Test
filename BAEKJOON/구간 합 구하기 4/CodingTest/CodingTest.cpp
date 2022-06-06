#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int Input;
	cin >> N >> M;
	vector<int> Arr(N), SumList(N);

	for (int i = 0; i < N; i++)
	{
		cin >> Input;
		Arr[i] = Input;

		SumList[i] = Input;
		if (i > 0)
		{
			SumList[i] += SumList[i - 1];
		}
	}

	int i, j;
	while (M--)
	{
		cin >> i >> j;
		i--; j--;

		int Sum = SumList[j];
		if (i > 0)
		{
			Sum -= SumList[i - 1];
		}
		cout << Sum << '\n';
	}

	return 0;
}