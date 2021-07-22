#include <iostream>

#include <string>
#include <vector>

using namespace std;

bool isDigit(const char& ch) {
	return ch >= '0' && ch <= '9';
}

int solution(string s) {
	int answer = 0, startIndex, ten = 10;
	bool isPositive = s[0] == '-' ? false : true;
	startIndex = isDigit(s[0]) ? 0 : 1;

	for (int index = startIndex; index < s.size(); index++) {
		answer *= ten;
		answer += (s[index] - '0');
	}

	return isPositive ? answer : -answer;
}

int main() {
	cout << solution("+1234") << endl;
	cout << solution("-1234") << endl;

	return 0;
}