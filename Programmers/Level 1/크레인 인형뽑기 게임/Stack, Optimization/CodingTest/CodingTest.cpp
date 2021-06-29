#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int numbers[31];

void reverse(vector<vector<int>>& vv)
{
	int begin = 0, end = vv.size() - 1;

	while (begin < end)
	{
		swap(vv[begin++], vv[end--]);
	}
}

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0, wSize = board.size(), w, h, pick;
	stack<int> basket;

	reverse(board);

	for (int width = 0; width < wSize; width++)
	{
		for (int height = 0; height < wSize; height++)
		{
			if (board[height][width] == 0)break;

			numbers[width] = height;
		}
	}

	for (const int& move : moves)
	{
		w = move - 1;
		if (numbers[w] < 0)continue;

		h = numbers[w]--;
		pick = board[h][w];

		if (basket.empty() || pick != basket.top())
			basket.push(pick);
		else
		{
			basket.pop();
			answer += 2;
		}
	}

	return answer;
}

int main()
{
	cout << solution({ {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} }, { 1,5,3,5,1,2,1,4 });

	return 0;
}