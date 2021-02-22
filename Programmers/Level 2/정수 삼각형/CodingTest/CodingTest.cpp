#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int max = 0;
	int cost, value1, value2;
	
	int len = triangle.size();
	for (int h = 0; h < len; h++)
	{
		int len2 = triangle[h].size();
		for (int w = 0; w < len2; w++)
		{
			cost = triangle[h][w];

			if (h - 1 >= 0)
			{
				if (w - 1 < 0)
				{
					cost += triangle[h - 1][w];
				}
				else if (w == len2 - 1)
				{
					cost += triangle[h - 1][w - 1];
				}
				else
				{
					value1 = triangle[h - 1][w];
					value2 = triangle[h - 1][w - 1];

					value1 > value2 ? cost += value1 : cost += value2;
				}
			}

			triangle[h][w] = cost;

			if (max < cost)max = cost;
		}
	}

	return max;
}

int main()
{
	cout << solution({ {7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5} });

	return 0;
}