#include <iostream>

using namespace std;

int main(void) {
	string N;
	int answer = 0, count = 1;
	
	cin >> N;

	for (int i = N.size() - 1; i >= 0; i--) {
		if (N[i] != '0') {
			if (N[i] >= 'A') {
				answer += (N[i] - 'A' + 10) * count;
			}
			else {
				answer += (N[i] - '0') * count;
			}
		}
		count *= 16;
	}

	cout << answer;

	return 0;
}