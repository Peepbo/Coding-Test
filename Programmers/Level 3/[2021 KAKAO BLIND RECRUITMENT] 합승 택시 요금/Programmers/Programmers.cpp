#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define INF 999999999

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	vector<vector<int>> matrix(n + 1, vector<int>(n + 1, INF));

	int answer = INF, c, d, f;

	//최초 정보 삽입
	for (const auto& fare : fares) {
		c = fare[0];
		d = fare[1];
		f = fare[2];

		matrix[c][d] = matrix[d][c] = f;
		matrix[c][c] = matrix[d][d] = 0;
	}

	//플로이드 와샬 알고리즘
	for (int _k = 1; _k <= n; _k++) {
		for (int _s = 1; _s <= n; _s++) {
			for (int _e = _s + 1; _e <= n; _e++) {
				matrix[_s][_e] = matrix[_e][_s] = min(matrix[_s][_e], matrix[_s][_k] + matrix[_k][_e]);
			}
		}
	}

	// 두 명이 k 위치까지 합승했다가 개별로 집으로 가는 요금
	// matrix[s][k] + matrix[k][a] + matrix[k][b];
	for (int k = 1; k <= n; k++) {
		// 이동이 불가능한 경우는 제외
		if (matrix[s][k] == INF || matrix[k][a] == INF || matrix[k][b] == INF)continue;

		answer = min(answer, matrix[s][k] + matrix[k][a] + matrix[k][b]);
	}

	//최소 요금 반환
	return answer;
}

int main()
{
	//vector<vector<int>> fares{ {4,1,10},{3,5,24},{5,6,2},{3,1,41},{5,1,24},{4,6,50},{2,4,66},{2,3,22},{1,6,25} };
	//solution(6, 4, 6, 2, fares);
	cout << solution(7, 3, 4, 1,{ {5, 7, 9}, { 4,6,4 }, { 3,6,1 }, { 3,2,3 }, { 2,1,6 }});
}