#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, int> m1;

void checkMap(string str)
{
	if (m1.find(str) != m1.end())
	{
		m1.find(str)->second++;
	}

	else m1.insert(pair<string, int>(str, 1));
}

int solution(vector<vector<string>> clothes) {
	int answer = 0;

	for (int i = 0; i < clothes.size(); i++)
	{
		checkMap(clothes[i][1]);
	}


	map<string, int >::iterator iter;
	for (iter = m1.begin(); iter != m1.end(); ++iter)
	{
		if (answer == 0) answer += iter->second + 1;

		else answer *= (iter->second + 1);
	}

	return answer - 1;
}

void main()
{
	cout << solution({ {"yellow_hat", "headgear"}, { "blue_sunglasses", "eyewear" }, { "green_turban", "headgear" } });
}