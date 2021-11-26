#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[501];

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, tempN, a, b;
	int nA, cA, nB, cB, LIS = 1;
	cin >> N;
	tempN = N;

	vector<pair<int, int>> vec(1); // {A, B}
	while (tempN--) {
		cin >> a >> b;
		vec.emplace_back(a, b);
		dp[a] = 1;
	}

	/*
	* <LIS를 사용해서 풀 수 있는 이유>
	* 올바르게 전선들이 연결되려면 1,2,4,8 과 같이 증가 수열이여야 한다.
	* 맨 끝 부터 최대로 만들 수 있는 전선 개수를 구한다.
	* 인덱스가 A 기준으로 정렬되어 있어야 하기 때문에 정렬을 해준다.
	* 
	* 자신보다 큰 인덱스 중 자신 보다 큰 값을 가리키는 전선만 겹치지 않게된다. (그림을 그려보면 이해됨)
	* 자신보다 오른쪽에 있는 수 중에 가장 많이 만들 수 있는 전선 개수를 가져와 1(자기 자신)을 더한다.
	* 
	* LIS를 매번 최대 값이 나올 때 업데이트하여 반복문이 끝나면 최대 LIS를 구하도록 한다.
	* 최대 전선 개수 N에 LIS를 빼면 최소 제거 전선 개수를 구할 수 있다.
	*/
	
	/* default less */
	sort(vec.begin(), vec.end());

	for (int i = N - 1; i >= 1; i--) {
		nA = vec[i].first;
		nB = vec[i].second;

		for (int j = i + 1; j <= N; j++) {
			cA = vec[j].first;
			cB = vec[j].second;

			// 증가 수열이 만들어 질 때
			if (nB < cB) {
				// 이전에 저장된 LIS값 보다 더 클 때
				if (dp[nA] < dp[cA] + 1) {
					// 정보 업데이트
					dp[nA] = dp[cA] + 1;
					LIS = max(LIS, dp[nA]);
				}
			}
		}
	}

	/* number of all wires - longest increasing sequence = minimum number of wires removed */
	/* 모든 전선 개수 - 가장 긴 증가 수열 = 최소 제거 전선 개수 */
	cout << N - LIS;
	return 0;
}