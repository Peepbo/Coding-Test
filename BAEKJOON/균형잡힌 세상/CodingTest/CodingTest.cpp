#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

vector<string> message;

const bool isBracket(const char& ch) {
	return ch == '[' || ch == ']' || ch == '(' || ch == ')';
}

const char oppositeDirection(const char& ch) {
	if (ch == ')')return '(';
	return '[';
}

void checkBracket(const string& str) {
	stack<char> s;

	for (const char& ch : str) {
		if (isBracket(ch)) {
			if (ch == '(' || ch == '[') {
				s.push(ch);
			}
			else {
				if (!s.empty() && s.top() == oppositeDirection(ch))s.pop();
				else {
					message.emplace_back("no");
					return;
				}
			}
		}
	}

	message.emplace_back(s.empty() ? "yes" : "no");
}

int main(void) {
	string input;

	while (true) {
		getline(cin, input);
		if (input == ".")break;

		checkBracket(input);
	}

	for (const string& str : message) {
		cout << str << '\n';
	}
	
	return 0;
}