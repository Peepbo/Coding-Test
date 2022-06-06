#include <iostream>

using namespace std;

int SumMatrix[1025][1025];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int Input;
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			cin >> Input;
			SumMatrix[x][y] = Input;

			if (x > 1)
			{
				SumMatrix[x][y] += SumMatrix[x - 1][y];
			}
		}
	}

	int x1, y1, x2, y2;
	int Sum;
	while (M--)
	{
		cin >> y1 >> x1 >> y2 >> x2;

		Sum = 0;

		if (x1 == x2 && y1 == y2)
		{
			Sum = SumMatrix[x1][y1];
			
			if (x1 > 1)
			{
				Sum -= SumMatrix[x1 - 1][y1];
			}
		}
		else
		{
			for (int y = y1; y <= y2; y++)
			{
				Sum += SumMatrix[x2][y];
				if (x1 > 1)
				{
					Sum -= SumMatrix[x1 - 1][y];
				}
			}
		}

		cout << Sum << '\n';
	}

	return 0;
}