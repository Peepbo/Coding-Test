#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N, M, minDraw = 64;
	cin >> N >> M;
	vector<string> board(N);

	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < N; i++) { //start y
		for (int j = 0; j < M; j++) { //start x

			if (i + 8 > N)break;
			if (j + 8 > M)continue;

			int need1 = 0, need2 = 0; //W first, B first

			for (int k = i; k < i + 8; k++) { //continue y
				for (int l = j; l < j + 8; l++) { //continue x

					if (k % 2 == l % 2) {
						if (board[k][l] != 'W') {
							need1++;
						}
						else {
							need2++;
						}
					}
					else {
						if (board[k][l] != 'B') {
							need1++;
						}
						else {
							need2++;
						}
					}
				}
			}

			minDraw = min(minDraw, min(need1, need2));
		}
	}

	cout << minDraw;
	return 0;
}