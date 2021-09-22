#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	const int max = arr1.size(), inerMax = arr1[0].size();
	vector<vector<int>> answer(max, vector<int>(inerMax));

	for (int i = 0; i < max; i++) {
		for (int j = 0; j < inerMax; j++) {
			answer[i][j] = arr1[i][j] + arr2[i][j];
		}
	}

	return answer;
}

int main() {

	return 0;
}