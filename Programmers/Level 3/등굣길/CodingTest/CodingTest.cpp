#include <iostream>
#include <string>
#include <vector>

using namespace std;

int tile[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
	for (const auto& it : puddles)
	{
		tile[it.back()][it.front()] = -1;
	}
	
	tile[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (tile[i][j] == -1)tile[i][j] = 0;

			else
			{
				if (i != 1) tile[i][j] += tile[i - 1][j] % 1000000007;

				if (j != 1) tile[i][j] += tile[i][j - 1] % 1000000007;
			}

		}
	}

	return tile[n][m] % 1000000007;
}

int main()
{
	cout << solution(4, 3, { {2,2} });

	return 0;
}