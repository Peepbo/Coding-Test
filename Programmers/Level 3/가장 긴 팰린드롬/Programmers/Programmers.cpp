#include <iostream>
#include <string>

using namespace std;

int solution(string s)
{
	if (s.size() == 0)return 0;

	int maximumLength = 1, strSize = s.size(), length, left, right;

	for (int i = 1; i < strSize; i++) {
		length = 1;
		left = i - 1;
		right = i + 1;

		while ((left >= 0 && right < strSize) && s[left--] == s[right++]) {
			length += 2;
		}

		maximumLength = max(maximumLength, length);

		length = 0;
		left = i - 1;
		right = i;

		while ((left >= 0 && right < strSize) && s[left--] == s[right++]) {
			length += 2;
		}

		maximumLength = max(maximumLength, length);
	}

	return maximumLength;
}

int main()
{
	cout << solution("abcdcba") << endl;
	cout << solution("abacde");
}