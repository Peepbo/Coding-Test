#include <iostream>
#include <string>

using namespace std;

string sum(string& a, string& b) {
	string output;

	if (a.size() < b.size())swap(a, b);

	bool next = false;
	int sum, rem, val1, val2;
	int aIdx = a.size() - 1, bIdx = b.size() - 1;

	while (aIdx >= 0 || bIdx >= 0) {
		val1 = a[aIdx--] - '0';
		val2 = bIdx < 0 ? 0 : b[bIdx--] - '0';

		sum = next + val1 + val2;
		rem = sum % 10;

		next = sum >= 10 ? true : false;

		output = char(rem + '0') + output;
	}

	if (next)output = '1' + output;

	return output;
}

int main(void) {
	string A, B;
	cin >> A >> B;
	
	cout << sum(A, B);

	return 0;
}