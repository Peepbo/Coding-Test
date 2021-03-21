#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

#define word first
#define depth second

using namespace std;

unordered_map<string, vector<string>> um;
int len = 0;

bool checkWord(string now, string next)
{
	vector<string> vs;
	bool checker = false;
	string temp = "";

	for (int i = 0; i < now.size(); i++)
	{
		temp = now;
		temp[i] = ' ';

		vs.emplace_back(temp);
	}

	for (int i = 0; i < vs.size(); i++)
	{
		checker = true;
		for (int j = 0; j < vs[i].size(); j++)
		{
			if (vs[i][j] != ' ' && vs[i][j] != next[j])
			{
				checker = false;
				break;
			}
		}

		if (checker)return true;
	}

	return false;
}

void dfs(string start, string target)
{
	unordered_map<string, bool> visit;
	queue<pair<string, int>> q;

	q.push({start, 0});
	visit[start] = true;

	while (!q.empty())
	{
		auto now = q.front();
		q.pop();

		if (now.word == target)
		{
			len = now.depth;
			break;
		}

		for (int i = 0; i < um[now.word].size(); i++)
		{
			string next = um[now.word][i];

			if (visit[next])continue;

			visit[next] = true;
			q.push({ next, now.depth + 1 });
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	words.emplace_back(begin);

	for (int i = 0; i < words.size(); i++)
	{
		for (int j = i + 1; j < words.size(); j++)
		{
			if (checkWord(words[i], words[j]))
			{
				um[words[i]].emplace_back(words[j]);
				um[words[j]].emplace_back(words[i]);
			}
		}
	}

	dfs(begin, target);

	return len;
}

int main()
{
	cout << solution("hit", "cog", { "hot","dot","lot","log","cog" });
	//cout << solution("hit", "cog", { "hot","dot","dog","lot","log" });

	return 0;
}