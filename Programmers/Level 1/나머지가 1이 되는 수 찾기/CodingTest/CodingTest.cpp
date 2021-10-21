#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    const int half = n / 2;
    vector<pair<bool, int>> decimal(n + 1, { true, 0 });
    decimal[0] = decimal[1] = { false, 1 };

    for (int i = 2; i <= half; i++) {
        for (int j = i * 2; j <= n; j += i) {
            if (decimal[j].second != 0)continue;

            decimal[j] = { false, i };
        }
    }

    return decimal[n - 1].first ? n - 1 : decimal[n - 1].second;
}

int main(void) {
    for (int i = 3; i <= 100; i++) {
        cout << i << ':' << solution(i) << '\n';
    }

	return 0;
}