#include <string>
#include <vector>

using namespace std;

#define INF 10000000001

vector<string> solution(vector<vector<int>> line) {
	vector<string> answer;
	vector<pair<int, int>> save;
	int N = line.size();
	int minX = INF, minY = INF, maxX = -INF, maxY = -INF;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			long long A = line[i][0], B = line[i][1], E = line[i][2];
			long long C = line[j][0], D = line[j][1], F = line[j][2];

			long long div = A * D - B * C;
			if (div == 0)continue;

			long long topX = B * F - E * D;
			long long topY = E * C - A * F;
			if (topX % div != 0 || topY % div != 0)continue;

			int x = topX / div;
			int y = topY / div;

			minX = min(minX, x);
			maxX = max(maxX, x);
			minY = min(minY, y);
			maxY = max(maxY, y);

			save.emplace_back(x, y);
		}
	}

	string temp(maxX - minX + 1, '.');
	answer.assign(maxY - minY + 1, temp);
	for (const auto& pr : save) {
		answer[maxY - pr.second][pr.first - minX] = '*';
	}

	return answer;
}

int main(void) {

	return 0;
}