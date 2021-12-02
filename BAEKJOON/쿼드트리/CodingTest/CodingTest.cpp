#include <iostream>
#include <string>

using namespace std;

string video[64];

void quadCompression(const int& sX, const int& sY, const int& size) {
	if (size == 1) {
		cout << video[sY][sX];
		return;
	}

	int zeroCnt = 0, oneCnt = 0;
	for (int x = sX; x < sX + size; x++) {
		for (int y = sY; y < sY + size; y++) {
			if (video[y][x] == '0')
				zeroCnt++;
			else 
				oneCnt++;
		}
	}

	if (oneCnt == 0)
		cout << 0;
	else if(zeroCnt == 0)
		cout << 1;
	else {
		cout << '(';
		const int halfSize = size / 2;
		// Left Top
		quadCompression(sX, sY, halfSize);
		// Right Top
		quadCompression(sX + halfSize, sY, halfSize); 
		// Left Down
		quadCompression(sX, sY + halfSize, halfSize); 
		// Right Down
		quadCompression(sX + halfSize, sY + halfSize, halfSize);
		cout << ')';
	}
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, tempN, idx = 0;
	string read;
	cin >> N;
	tempN = N;
	while (tempN--) {
		cin >> video[idx++];
	}

	quadCompression(0, 0, N);
	return 0;
}