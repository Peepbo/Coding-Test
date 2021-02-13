#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;

	s = s.substr(1, s.size() - 2);

	string numberStr;
	vector<pair<int,vector<int>>> vv;

	int inIdx;
	while ((inIdx = s.find('{')) != -1)
	{
		int outIdx = s.find('}');

		numberStr = s.substr(1, outIdx - 1);

		vector<int> v;
		string sNum;
		for (int j = 0; j < numberStr.size(); j++)
		{
			if (numberStr[j] != ',') sNum += numberStr[j];

			else
			{
				v.emplace_back(stoi(sNum));
				sNum.clear();
			}
		}

		if (!sNum.empty()) v.emplace_back(stoi(sNum));

		vv.emplace_back(make_pair(v.size(), v));
		s.erase(0, outIdx + 2);
	}

	sort(vv.begin(), vv.end());

	set<int> st;
	for (auto pr : vv)
	{
		for (int num : pr.second)
		{
			if (st.find(num) == st.end())
			{
				st.insert(num);
				answer.push_back(num);
			}
		}
	}

	return answer;
}

int main()
{
	vector<int> output = solution("{{20,111},{111}}");

	for (int i = 0; i < output.size(); i++)
		cout << output[i] << ',';

	return 0;
}