#include <iostream>
#include <string>
#include <vector>

#define MAX 999999999

using namespace std;

int main(){
	int N, M, a, b, c;
	cin >> N >> M;
	
	const vector<int> temp(N + 1, MAX);
	vector<vector<int>> matrix(N + 1, temp);

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (y == x)
				matrix[y][x] = 0;
		}
	}
	
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		matrix[a][b] = min(matrix[a][b], c);
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (matrix[y][x] == MAX)
				matrix[y][x] = 0;
			
			cout << matrix[y][x] << ' ';
		}
		cout << '\n';
	}

	return 0;
}