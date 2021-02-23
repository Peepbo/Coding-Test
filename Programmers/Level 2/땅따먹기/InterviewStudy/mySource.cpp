#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[100001][4];

int solution(vector<vector<int> > land)
{
	int order = 0;
	for (const auto& f : land.front())
	{
		arr[0][order] = f;
		order++;
	}

	int max = 0;

	order = 1;
	int len = land.size();
	while (order < len)
	{
		for (int i = 0; i < 4; i++)
		{
			int chs = arr[order - 1][i];

			for (int j = 0; j < 4; j++)
			{
				if (i == j)continue;

				int sum = chs + land[order][j];

				if (arr[order][j] < sum)
				{
					arr[order][j] = sum;

					if (order == len - 1)
					{
						if (max < sum) max = sum;
					}
				}
			}
		}
		order++;
	}

	return max;
}

int main()
{
	cout << solution({ {1,2,3,5},{5,6,7,8},{4,3,2,1} });

	return 0;
}