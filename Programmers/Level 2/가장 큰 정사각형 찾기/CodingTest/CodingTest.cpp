#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    int max = 0, cmp;

    if (board.size() == 1)return board[0][0];

    for (int i = 1; i < board.size(); i++)
    {
        for (int j = 1; j < board[0].size(); j++)
        {
            if (board[i][j] == 0)continue;

            cmp = min(min(board[i][j - 1], board[i - 1][j]), board[i - 1][j - 1]) + 1;
            board[i][j] = cmp;
            if (max < cmp)max = cmp;
        }
    }

    return max * max;
}

int main()
{
    //cout << solution({ { 0,1,1,1 }, { 1,1,1,1 }, { 1,1,1,1 }, { 0,0,1,0 } });
    cout << solution({ {0,0,1,1} ,{1,1,1,1} });

	return 0;
}