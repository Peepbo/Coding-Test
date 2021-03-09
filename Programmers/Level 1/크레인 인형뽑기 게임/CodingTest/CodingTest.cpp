#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0, wSize = board[0].size(), pick;
	vector<queue<int>> vq(wSize);
	stack<int> st;

	for (const auto& it : board)
	{
		for (int i = 0; i < it.size(); i++)
		{
			if(it[i] != 0) vq[i].push(it[i]);
		}
	}

	for (const auto& it : moves)
	{
		if (vq[it - 1].empty()) continue;

		pick = vq[it - 1].front();
		vq[it - 1].pop();

		if (st.empty() || pick != st.top())
		{
			st.push(pick);
		}
		else 
		{
			st.pop();
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