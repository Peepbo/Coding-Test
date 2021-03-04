#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> m;
int pNum;

bool alphbetChecker(const string& str)
{
	pNum = -1;
	if (!isalpha(str.front())) pNum = 0;
	if (!isalpha(str.back())) pNum = 1;

	return pNum == -1;
}

void lowerChanger(string& str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
}

double J(const string& a,const string& b)
{
	string write;
	int interCount = 0, unionCount = 0;
	int notAlpha = 0;

	for (int i = 1; i < a.size(); i++)
	{
		write = a.substr(i - 1, 2);
		if (!alphbetChecker(write)) 
		{
			i += pNum;
			continue;
		}
		unionCount++;

		lowerChanger(write);
		m[write]++;
	}

	for (int i = 1; i < b.size(); i++)
	{
		write = b.substr(i - 1, 2);
		if (!alphbetChecker(write))
		{
			i += pNum;
			continue;
		}
		unionCount++;

		lowerChanger(write);
		if (m[write] > 0)
		{
			cout << write << '\n';
			interCount++;
			unionCount--;
			m[write]--;
		}
	}

	//for (auto& it : m)
	//{
	//	cout << it.first << ' ' << it.second << '\n';
	//}
	cout << "inter : " << interCount << '\n';
	cout << "union : " << unionCount << '\n';

	if (interCount == 0 && unionCount == 0)return 1;

	return (float)interCount / unionCount;
}

int solution(string str1, string str2) {
	return 65536 * J(str1, str2);
}

int main()
{
	cout << solution("aa1+aa2", "AAAA12");

	return 0;
}