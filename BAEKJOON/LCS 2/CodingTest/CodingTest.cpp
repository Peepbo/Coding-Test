#include <iostream>
#include <vector>

using namespace std;

int dp[1001][1001];

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string A, B;
	int maximum, temp;
	vector<char> LCS_reverse;
	cin >> A >> B;
	A = " " + A;
	B = " " + B;

	for (int i = 1; i <= A.size() - 1; i++) {
		for (int j = 1; j <= B.size() - 1; j++) {
			if (A[i] != B[j]) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
		}
	}

	maximum = temp = dp[A.size() - 1][B.size() - 1];
	cout << maximum;
	if (maximum > 0) {
		cout << '\n';

		for (int i = B.size() - 1; i >= 1; i--) {
			if (temp == 0)break;

			for (int j = A.size() - 1; j >= 1; j--) {
				if (B[i] == A[j] && dp[j][i] == temp) {
					LCS_reverse.emplace_back(B[i]);
					temp--;
					break;
				}
			}
		}

		for (int i = LCS_reverse.size() - 1; i >= 0; i--) {
			cout << LCS_reverse[i];
		}
	}
	return 0;
}