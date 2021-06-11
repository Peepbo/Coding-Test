#include <iostream>
#include <string>
#include <vector>

using namespace std;

int board[10001];

int main()
{
	int N, M, sum = 0, collect = 0, s = 0, e = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> board[i];

	while (e <= N)
	{
		if (sum >= M)
			sum -= board[s++];
		else if (sum < M)
			sum += board[e++];
		if (sum == M)
			collect++;
	}

	cout << collect;
}