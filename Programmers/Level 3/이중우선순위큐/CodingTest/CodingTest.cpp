#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
	priority_queue<int, vector<int>, less<int>> high;
	priority_queue<int, vector<int>, greater<int>> low;
	
	int len = operations.size();
	vector<int> highDel, lowDel;
	string sub;
	char ch;

	for (int i = 0; i < len; i++)
	{
		ch = operations[i][0];
		sub = operations[i].substr(2);

		switch (ch)
		{
		case 'I':
			high.push(stoi(sub));
			low.push(stoi(sub));
			break;

		case 'D':
			if (sub == "1" && !high.empty())
			{
				lowDel.emplace_back(high.top());
				high.pop();
			}

			else if (!low.empty())
			{
				highDel.emplace_back(low.top());
				low.pop();
			}
			break;
		}

		if (!high.empty() && !highDel.empty())
		{
			while (high.top() == highDel.back())
			{
				high.pop();
				highDel.pop_back();

				if (high.empty() || highDel.empty())break;
			}
		}

		if (!low.empty() && !lowDel.empty())
		{
			while (low.top() == lowDel.back())
			{
				low.pop();
				lowDel.pop_back();

				if (low.empty() || lowDel.empty())break;
			}
		}
	}

	if (high.empty() || low.empty()) return { 0,0 };
	return { high.top(),low.top() };
}

int main()
{
	solution({ "I 16","I -5643","D -1","D 1","D 1", "I 123", "D -1" });

	return 0;
}