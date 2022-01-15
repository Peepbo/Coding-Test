#include <iostream>
#include <string>

int num[51];
char oper[51];
int lastOperIdx;

using namespace std;

int dfs(int sum, int last, bool bMinus, int idx) {
	if (lastOperIdx == idx) {
		sum += last * (bMinus ? -1 : 1);
		return sum;
	}

	if (oper[idx] == '-') {
		sum += last * (bMinus ? -1 : 1);
		return dfs(sum, num[idx + 1], true, idx + 1);
	}
	else if (oper[idx] == '+') {
		last += num[idx + 1];
		return dfs(sum, last, bMinus, idx + 1);
	}
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string input;
	int s = 0, number, idx = 0;
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '+' || input[i] == '-') {
			number = stoi(input.substr(s, i - s));
			num[idx] = number;
			oper[idx] = input[i];
			idx++;
			s = i + 1;
		}
	}
	number = stoi(input.substr(s, input.size() - s));
	num[idx] = number;
	lastOperIdx = idx;

	cout << dfs(0, num[0], false, 0);
	return 0;
}