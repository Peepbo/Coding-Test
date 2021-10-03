#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int M, N, sum = 0, minNum = 50000;
	cin >> M >> N;

	vector<bool> prime(10001, true);
	prime[0] = prime[1] = false;

	for (int i = 2; i <= 5000; i++) {
		if (prime[i] == false)continue;

		if (i > N) break;

		for (int j = i * 2; j <= 10000; j += i) {
			prime[j] = false;
		}
	}
	
	for (int i = M; i <= N; i++) {
		if (prime[i]) {
			sum += i;
			minNum = min(minNum, i);
		}
	}

	if (sum == 0)
		printf("-1");
	else 
		printf("%d\n%d", sum, minNum);

	return 0;
}