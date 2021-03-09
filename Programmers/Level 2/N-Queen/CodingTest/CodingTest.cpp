#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ways, maxNum;

vector<vector<int>> matrix;

void setMatrix(int value, int h, int w)
{
	matrix[h][w] += value;
	for (int j = 1; j < maxNum - h; j++)
	{
		matrix[h + j][w] += value;

		if (h + j < maxNum)
		{
			if (w + j < maxNum) matrix[h + j][w + j] += value;
			if (w - j >= 0) matrix[h + j][w - j] += value;
		}
	}
}

void BT(int depth)
{
	if (depth == maxNum)
	{
		ways++;
		return;
	}

	for (int i = 0; i < maxNum; i++)
	{
		if (matrix[depth][i] != 0) continue;

		setMatrix(1, depth, i);
		BT(depth + 1);
		setMatrix(-1, depth, i);
	}
}

int solution(int n) {
	maxNum = n;

	for (int i = 0; i < n; i++) 
		matrix.emplace_back(n);

	BT(0);
	return ways;
}

int main()
{
	cout << solution(4);

	return 0;
}