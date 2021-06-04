#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer;

	map<string,int> m;
	m.insert({ gems[0],1 });

	vector<string> temp(gems.begin(), gems.end());
	sort(temp.begin(),temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());

	int maximum = temp.size();

	int low = 100, high = 1;

	for (int i = 1; i < gems.size(); i++)
	{
		if (m.size() == maximum)break;

		high = i + 1;
		m[gems[i]] = high;
	}


	for (const auto& it : m)
	{
		if (low > it.second)low = it.second;
	}

	return { low,high };
}

int main()
{
	//dia,0
	//ruby,0


	//          0     0      1      1     2       0          0       3     
	solution({"DIA","RUBY","RUBY","DIA","DIA","EMERALD","SAPPHIRE","DIA"});
}