#include <iostream>
using namespace std;

int main()
{
	int N, M, K;
	cin >> N >> M >> K;

	int count = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (count == K)
			{
				cout << i << " " << j;
				return 0;
			}

			count++;
		}
	}
}