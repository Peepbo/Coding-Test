#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int idx;

bool compare(string x, string y)
{
	if (x[idx] < y[idx]) return true;
	else if (x[idx] > y[idx])return false;

	return x < y;
}

vector<string> solution(vector<string> strings, int n) {
	idx = n;
	sort(strings.begin(), strings.end(), compare);

	return strings;
}

int main()
{
}