#include <iostream>
using namespace std;

int main(void)
{
	int N, M;
	int A[100];

	cin >> N >> M;

	int result = 0;

	for (int i = 0; i < N; i++)cin >> A[i];

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				int S = A[i] + A[j] + A[k];
				if (S <= M && result < S)
				{
					result = S;
				}
			}
		}
	}

	cout << result;

	return 0;
}