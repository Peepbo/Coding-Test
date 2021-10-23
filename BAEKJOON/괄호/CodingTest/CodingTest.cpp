#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<string> message;

void CheckVPS() {
	stack<char> s;
	string input;

	cin >> input;
	for (const char& ch : input) {
		if (ch == '(')s.push(ch);
		else {
			if (!s.empty() && s.top() == '(')s.pop();
			else {
				message.emplace_back("NO");
				return;
			}
		}
	}

	message.emplace_back(s.empty() ? "YES" : "NO");
}

int main(void) {
	int T;
	cin >> T;

	while (T--) {
		CheckVPS();
	}

	for (const string& str : message) {
		cout << str << '\n';
	}
	
	return 0;
}