#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	map<string, int> m1;

	for (string name : participant)
	{
		m1[name]++;
	}
	for (string name : completion)
	{
		m1[name]--;
	}
	for (auto pair : m1)
	{
		if (pair.second > 0) return pair.first;
	}
}

int main()
{

}