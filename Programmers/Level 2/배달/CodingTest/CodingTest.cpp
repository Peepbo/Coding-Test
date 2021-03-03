#include <iostream>
#include <string>
#include <vector>

using namespace std;

int visit[51];
int dist[51];
vector<pair<int, int>> a[51];

void dfs(int idx, int sum, int K)
{
	for (int i = 0; i < a[idx].size(); i++)
	{
		int next = a[idx][i].first;
		int now = a[idx][i].second;

		if (now + sum > K)continue; //내 자식 인덱스의 비용과 내 비용을 더한게 제한을 넘어서면 컨티뉴
		if (dist[next] != 0 && dist[next] < now + sum)continue; //dist[next] != 0이면 이미 방문한 노드이며, dist에 저장되어있는 값보다 now+sum의 값이 더 크면
		//비용이 더 들어가는 경로이므로 continue

		//여기까지 오는 경우가 1. dist[next] == 0 이거나, dist[next] >= now + sum 일때이다.

		//1. dist[next] == 0
		//방문을 처음 하는 곳이다. 이미 now + sum이 K보다 작거나 같다는것은 18번줄에서 걸러졌다.
		//고로 배달이 가능한 곳이므로 방문을 했다고 표시해준다.
		//dist에 값이 처음 들어왔거나, 원래 값보다 더 작은 값이 들어왔다. dist를 업데이트 해준다.

		//dfs 함수를 재귀하는데, 가리키는 노드와, 더한 코스트, 제한 값 등을 전달해준다.

		visit[next] = 1;
		dist[next] = sum + now;
		dfs(next, sum + now, K);
	}
}

void linkNode(int idx0, int idx1, int time)
{
	a[idx0].emplace_back(idx1, time);
	a[idx1].emplace_back(idx0, time);
}

int solution(int N, vector<vector<int>> road, int K)
{
	int answer = 0;

	for (const auto& it : road)
	{
		int idx0 = it[0];
		int idx1 = it[1];
		int cost = it[2];

		linkNode(idx0, idx1, cost);
	}

	visit[1] = 1;
	dfs(1, 0, K);

	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == 1)answer++;
	}

	return answer;
}

int main()
{
	cout << solution(5, { { 1,2,1 }, { 2,3,3 }, { 5,2,2 }, { 1,4,2 }, { 5,3,1 }, { 5,4,2 } }, 3);

	return 0;
}