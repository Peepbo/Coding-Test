#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

vector<int> split(string str, char ch) {
	vector<int> output;
	int idx = 0, cnt = 0, start = 0;
	if (!str.empty()) {
		while (idx <= str.size()) {
			if (str[idx] == ch || idx == str.size()) {
				output.emplace_back(stoi(str.substr(start, cnt)));
				start = idx + 1;
				cnt = 0;
			}
			else {
				cnt++;
			}
			idx++;
		}
	}

	return output;
}

void applyCommand(deque<int>& dq, const string& command, bool& isLeft) {
	int cIdx = 0;
	while (cIdx < command.size()) {
		if (command[cIdx++] == 'R') {
			isLeft = !isLeft;
		}

		else {
			if (!dq.empty()) {
				if (isLeft) dq.pop_front();
				else dq.pop_back();
			}

			else {
				cout << "error" << '\n';
				return;
			}
		}
	}

	cout << '[';
	if (isLeft) {
		for (int i = 0; i < dq.size(); i++) {
			cout << dq[i];
			if (i != dq.size() - 1)cout << ',';
		}
	}
	else {
		for (int i = dq.size() - 1; i >= 0; i--) {
			cout << dq[i];
			if (i != 0)cout << ',';
		}
	}
	cout << ']' << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> dq;
	string p, arrStr;
	int T, n, cIdx;

	cin >> T;
	while (T--) {
		cin >> p >> n >> arrStr;
		const auto vec = split(arrStr.substr(1, arrStr.size() - 2), ',');
		dq.assign(vec.begin(), vec.end());
		bool isLeft = true;
		applyCommand(dq, p, isLeft);
	}



	return 0;
}