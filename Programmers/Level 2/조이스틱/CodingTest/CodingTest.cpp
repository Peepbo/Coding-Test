#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string str;

int pivot;
int cost;
int L, R;

int MinimumIndex()
{
	int nPivot = pivot;
	int right = 0, left = 0;

	while (1)
	{
		if (str[nPivot] != 'A') break;
		nPivot++;
		right++;
		if (nPivot > str.size() - 1)nPivot = 0;
	}

	nPivot = pivot;
	while (1)
	{
		if (str[nPivot] != 'A') break;
		nPivot--;
		left++;
		if (nPivot < 0)nPivot = str.size() - 1;
	}
	
	R = (pivot + right) % str.size();
	L = pivot - left < 0 ? (pivot - left) + str.size() : pivot - left;

	if (right > left)
	{
		cost += left;
		return L;
	}
	else
	{
		cost += right;
		return R;
	}
}

int solution(string name) {
	int remain = name.size();
	str = name;
	pivot = 0;

	for (int i = 0; i < name.size(); i++)
	{
		if (name[i] == 'A') remain--;
	}

	while (remain > 0)
	{
		pivot = MinimumIndex();

		cost += min(name[pivot] - 'A', 'Z' - name[pivot] + 1);

		str[pivot] = 'A';
		remain--;
	}
	
	return cost;
}

int main()
{
	cout << solution("JAN");

	return 0;
}