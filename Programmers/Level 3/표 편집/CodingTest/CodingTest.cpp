#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
	int cnt;

	string answer(n, 'X');
	set<int> table;
	stack<int> hist;

	for (int i = 0; i < n; i++) {
		table.insert(i);
	}

	auto cur = table.find(k);

	for (const string& command : cmd) {
		switch (command[0])
		{
		case 'U':
		case 'D':
			cnt = stoi(command.substr(2));

			if (command[0] == 'U') {
				while (cnt--) {
					cur = prev(cur);
				}
			}
			else {
				while (cnt--) {
					cur = next(cur);
				}
			}
			break;
		case 'C':
			hist.push(*cur);
			cur = table.erase(cur);

			if (cur == table.end()) {
				cur = prev(cur);
			}
			break;
		case 'Z':
			table.insert(hist.top());
			hist.pop();
			break;
		default:
			return "";
		}
	}

	for (const auto& num : table) {
		answer[num] = 'O';
	}

	return answer;
}

int main() {
	//cout << solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" });
	cout << solution(8, 2, { "D 2", "C","U 3","C","D 4","C","U 2","Z","Z","U 1","C" });

	return 0;
}