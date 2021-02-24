#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int score;

void ChangeBoard(vector<string>& board, int h, int w)
{
	if (board[h][w] != ' ')
	{
		board[h][w] = ' ';
		score++;
	}
}

int solution(int m, int n, vector<string> board) {
	bool* checkLine = new bool[n] {false, };
	stack<pair<int, int>> s;
	pair<int, int> pivot;
	int top;

	while (1)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == ' ')continue;
				
				if (i - 1 >= 0 && j - 1 >= 0)
				{
					if (board[i][j] == board[i - 1][j - 1] &&
						board[i][j] == board[i - 1][j] &&
						board[i][j] == board[i][j - 1])
					{
						s.push({ i, j });
						checkLine[j] = true;
						checkLine[j - 1] = true;
					}
				}
			}
		}

		if (s.empty()) break;

		else
		{
			while (!s.empty())
			{
				ChangeBoard(board, s.top().first, s.top().second);
				ChangeBoard(board, s.top().first - 1, s.top().second);
				ChangeBoard(board, s.top().first, s.top().second - 1);
				ChangeBoard(board, s.top().first - 1, s.top().second - 1);

				s.pop();
			}

			for (int i = m - 1; i > 0; i--)
			{
				for (int j = n - 1; j >= 0; j--)
				{
					if (checkLine[j] == false)continue;

					if (board[i][j] == ' ')
					{
						pivot = { i - 1,j };

						top = 0;

						while (pivot.first >= 0)
						{
							if (board[pivot.first][pivot.second] != ' ')
							{
								board[i - top][j] = board[pivot.first][pivot.second];
								board[pivot.first][pivot.second] = ' ';
								top++;
							}

							pivot.first--;
						}
					}
				}
			}

			for (int i = 0; i < n; i++) checkLine[i] = false;
		}
	}

	return score;
}

int main()
{
	cout << solution(4, 5, { "CCBDE","AAADE","AAABF","CCBBF" });

	return 0;
}