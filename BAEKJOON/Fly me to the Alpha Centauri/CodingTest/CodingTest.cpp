#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<long long> output;
	long long T, x, y, sub, num, mul = 0, rem, cnt;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> x >> y;
		sub = y - x;

		num = 1;
		while (sub >= (num * num)) {
			mul = num * num;
			num++;
		}
		num--;

		cnt = num * 2 - 1;
		rem = sub - mul;

		if (rem > 0) {
			if (rem <= num)
				cnt++;
			else 
				cnt += 2;
		}

		output.emplace_back(cnt);
	}

	for (const int& count : output) {
		cout << count << '\n';
	}

	return 0;
}