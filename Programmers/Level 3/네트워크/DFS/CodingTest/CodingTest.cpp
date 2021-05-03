#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visit[101];

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	vector<vector<int>> vec(n);
	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j || computers[i][j] == 0) continue;

			vec[i].emplace_back(j);
		}
	}

	for (int i = 0; i < n; i++)
	{
		q.push(i);
		visit[i] = true;

		while (!q.empty())
		{
			int now = q.front();
			q.pop();

			bool isLink = false;
			for (int j = 0; j < vec[now].size(); j++)
			{
				int next = vec[now][j];
				if (visit[next])
				{
					isLink = true;
					continue;
				}

				q.push(next);
				visit[next] = true;
			}

			if (!isLink)answer++;
		}
	}

	return answer;
}

int main()
{
	//cout << solution(3, { {1,1,0},{1,1,0},{0,0,1} });
	//cout << solution(5, { {1,0,0,0,0},{0,1,0,0,1},{0,0,1,0,1},{0,0,0,1,1},{1,0,0,0,1} });
	cout << solution(5, { {1,0,0,0,1,0},{0,1,0,1,0,0},{0,0,1,1,0,0},{0,1,1,1,0,1},{1,0,0,0,1,0} });
	//cout << solution(3, { {1,1,0},{1,1,1},{0,1,1} });
}