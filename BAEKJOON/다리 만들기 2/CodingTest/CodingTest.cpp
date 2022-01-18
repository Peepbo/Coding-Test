#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

const int Mx[4]{ -1,1,0,0 };
const int My[4]{ 0,0,-1,1 };

int Matrix[11][11];
vector<pair<int, int>> Land[7];
vector<pair<int, pair<int, int>>> Dist;

int LandSize;
vector<int> Parent;

#define INF_DIST 100

void DFS(const int& idx,
	int x, int y) {
	if (x == 0 || x > M ||
		y == 0 || y > N ||
		Matrix[x][y] != 1)return;

	Land[idx].emplace_back(x, y);
	Matrix[x][y] = -1;

	for (int i = 0; i < 4; i++) {
		DFS(idx, x + Mx[i], y + My[i]);
	}
}

bool CheckBlock(bool isSameX, pair<int,int> p, int r) {
	int sX = p.first;
	int sY = p.second;

	if (isSameX) {
		if (sY > r)swap(sY, r);

		for (int y = sY + 1; y < r; y++) {
			if (Matrix[sX][y] != 0) {
				return false;
			}
		}
	}
	else {
		if (sX > r)swap(sX, r);

		for (int x = sX + 1; x < r; x++) {
			if (Matrix[x][sY] != 0) {
				return false;
			}
		}
	}

	return true;
}

int ShortestDist(int a, int b) {
	int answer = INF_DIST;
	int x1, y1, x2, y2;
	int d1, d2;

	for (const auto& p1 : Land[a]) {
		x1 = p1.first; y1 = p1.second;
		for (const auto& p2 : Land[b]) {
			x2 = p2.first; y2 = p2.second;

			d1 = abs(x1 - x2) - 1;
			d2 = abs(y1 - y2) - 1;

			// x축이 같음, 다리 길이가 1이 아님
			if (x1 == x2 && d2 > 1) {
				
				// 가로막고 있는 블록 없음
				if (CheckBlock(true, p1, y2)) {
					answer = min(answer, d2);
				}
			}
			// y축이 같음, 다리 길이가 1이 아님
			else if (y1 == y2 && d1 > 1) {

				// 가로막고 있는 블록 없음
				if (CheckBlock(false, p1, x2)) {
					answer = min(answer, d1);
				}
			}
		}
	}

	return answer;
}

void Init() {
	bool isFill;
	int landIdx = 1, distance;
	cin >> N >> M;

	// 섬 위치 파악하기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> isFill;

			Matrix[j][i] = isFill ? 1 : 0;
		}
	}

	// 섬 좌표 구분하기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (Matrix[j][i] == 1) {
				DFS(landIdx++, j, i);
			}
		}
	}

	LandSize = landIdx - 1;

	// 섬 i와 섬 j 사이의 최단 거리 구하기
	for (int i = 1; i < LandSize; i++) {
		for (int j = i + 1; j <= LandSize; j++) {
			distance = ShortestDist(i, j);

			if (distance != INF_DIST) {
				Dist.emplace_back(distance, make_pair(i, j));
			}
		}
	}

	sort(Dist.begin(), Dist.end());
}

int GetParent(int a) {
	if (a == Parent[a])return a;
	return Parent[a] = GetParent(Parent[a]);
}

void UnionParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);

	if (a < b)Parent[b] = a;
	else Parent[a] = b;
}

bool SameParent(int a, int b) {
	return GetParent(a) == GetParent(b);
}

int kruskal() {
	int total = 0;
	int dist, a, b;
	bool allLink = true;

	Parent = vector<int>(LandSize + 1);
	for (int i = 1; i <= LandSize; i++) {
		Parent[i] = i;
	}

	for (const auto& it : Dist) {
		dist = it.first;
		a = it.second.first;
		b = it.second.second;

		if (SameParent(a, b) == false) {
			total += dist;

			UnionParent(a, b);
		}
	}
	
	// 링크 확인
	for (int i = 1; i <= LandSize; i++) {
		if (GetParent(i) != 1) {
			allLink = false;
			break;
		}
	}

	return allLink ? total : -1;
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Init();

	cout << kruskal();
	return 0;
}