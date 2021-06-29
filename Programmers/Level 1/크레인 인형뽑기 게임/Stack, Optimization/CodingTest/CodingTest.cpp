#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int numbers[31];

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0, wSize = board.size(), hSize = wSize / 2, h, pick;
	stack<int> basket;

	for (int width = 0; width < wSize; width++)
	{
		for (int height = 0; height < wSize; height++)
		{
			if (board[height][width] != 0 && numbers[width] == 0)
			{
				numbers[width] = (wSize - height) - 1;
			}
		}
	}

	for (int i = 0; i < hSize; i++)
	{
		if (i == (wSize - 1) - i)break;

		swap(board[i], board[(wSize - 1) - i]);
	}

	for (int& w : moves)
	{
		w--;
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
	cout << solution({
		{ 0,0,0,0,0 },
		{ 0,0,1,0,3 },
		{ 0,2,5,0,1 },
		{ 4,2,4,4,2 },
		{ 3,5,1,3,1 }},

		{ 1,5,3,5,1,2,1,4 });
}