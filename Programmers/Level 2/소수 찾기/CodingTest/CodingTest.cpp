#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int arr[10000000];
unordered_set<int> Set;

bool compare(char a, char b)
{
	return a > b;
}

void Eratos(string str)
{
	sort(str.begin(), str.end(), compare);
	int number = stoi(str);

	for (int i = 2; i <= number; i++) arr[i] = 1;

	for (int i = 2; i <= number; i++)
	{
		if (arr[i] == 0)continue;

		for (int j = i * 2; j <= number; j += i)
		{
			arr[j] = 0;
		}
	}
}



void Permutation(vector<char>& v, int start, int end)
{
	if (start == end)
	{
		string sSum;
		for (int i = 0; i < v.size(); i++)
		{
			sSum += v[i];
		}

		int choose = 1;

		while (choose <= sSum.size())
		{
			int sNum = stoi(sSum.substr(0, choose));

			Set.insert(sNum);

			choose++;
		}

		return;
	}

	for (int i = start; i < end; i++)
	{
		swap(v[start], v[i]);
		Permutation(v, start + 1, end);
		swap(v[start], v[i]);
	}
}

int solution(string numbers) {
	int answer = 0;
	Eratos(numbers);

	vector<char> v;
	for (const char& c : numbers)
		v.emplace_back(c);

	Permutation(v, 0, v.size());

	for (const auto& s : Set)
	{
		if (arr[s] == 1) answer++;
	}

	return answer;
}

int main()
{
	cout << solution("17");

	return 0;
}