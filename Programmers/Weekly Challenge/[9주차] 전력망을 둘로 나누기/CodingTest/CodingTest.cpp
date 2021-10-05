#include <string>
#include <vector>

using namespace std;

const int INF = 999999999;
vector<vector<int>> list;

void dfs(const int& start, const int& exclu, vector<bool>& visited, int& count) {
	if (visited[start] || start == exclu)return;
	visited[start] = true;

	count++;

	for (int num : list[start]) {
		dfs(num, exclu, visited, count);
	}
}

int getCount(int link1, int link2) {
	int link1Count = 0, link2Count = 0;

	vector<bool> visited(list.size(), false);
	//link 1의 연결된 노드 개수 구하기 (2와 연결된 곳은 제외하고)
	dfs(link1, link2, visited, link1Count);

	//link 2의 연결된 노드 개수 구하기 (1과 연결된 곳은 제외하고)
	dfs(link2, link1, visited, link2Count);

	return abs(link1Count - link2Count);
}

int solution(int n, vector<vector<int>> wires) {
	int answer = INF;

	list.assign(n + 1, {});

	for (const vector<int>& vec : wires) {
		list[vec[0]].emplace_back(vec[1]);
		list[vec[1]].emplace_back(vec[0]);
	}

	for (const vector<int>& vec : wires) {
		//getCount(a,b) = a,b가 끊어졌을 때, abs(a의 연결된 개수 - b의 연결된 개수)
		answer = min(answer, getCount(vec[0], vec[1]));
	}

	return answer;
}