#include <iostream>

using namespace std;

int matrix[128][128];
int half[129];
int whiteCnt, blueCnt;

void toSplit(int x, int y, int size) {
	if (size == 1) {
		if (matrix[y][x] == 0)whiteCnt++;
		else blueCnt++;
		return;
	}

	int wCnt = 0, bCnt = 0;
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (matrix[i][j] == 0)wCnt++;
			else bCnt++;

			if (wCnt > 1 && bCnt > 1)break;
		}
	}

	if (bCnt == 0) {
		whiteCnt++;
	}
	else if(wCnt == 0) {
		blueCnt++;
	}
	else {
		toSplit(x, y, half[size]);							 // left up
		toSplit(x + half[size], y, half[size]);				 // right up
		toSplit(x, y + half[size], half[size]);				 // left down
		toSplit(x + half[size], y + half[size], half[size]); // left down
	}
}

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];

			if (matrix[i][j] == 0)whiteCnt++;
			else blueCnt++;
		}
	}
	
	if (whiteCnt == N * N) {
		whiteCnt = 1;
		blueCnt = 0;
	}
	else if (blueCnt == N * N) {
		whiteCnt = 0;
		blueCnt = 1;
	}
	else {
		whiteCnt = blueCnt = 0;
		for (int i = 2; i <= N; i *= 2) {
			half[i] = i / 2;
		}

		toSplit(0, 0, half[N]);				// left up
		toSplit(half[N], 0, half[N]);		// right up
		toSplit(0, half[N], half[N]);		// left down
		toSplit(half[N], half[N], half[N]); // left down
	}

	printf("%d\n%d", whiteCnt, blueCnt);
	return 0;
}