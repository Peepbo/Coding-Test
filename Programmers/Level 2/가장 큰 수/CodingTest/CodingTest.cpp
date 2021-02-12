#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string strNum[2];
int leftNum, rightNum;

bool compare(int x, int y)
{
	strNum[0] = to_string(x);
	strNum[1] = to_string(y);

	if (strNum[0].size() == strNum[1].size())
	{
		return x > y;
	}

	else
	{
		leftNum = stoi(strNum[0] + strNum[1]);
		rightNum = stoi(strNum[1] + strNum[0]);

		return leftNum > rightNum;
	}
}

string solution(vector<int> numbers) {
	string answer = "";

	int lop = numbers.size() - 1;
	int end = numbers.size();

	sort(numbers.begin(), numbers.end(), compare);

	for (int i = 0; i < lop + 1; i++) 
		answer += to_string(numbers[i]);

	if (answer.front() == '0')answer = '0';

	return answer;
}

int main()
{
	cout << solution({ 0,0,0,0,0 });

	return 0;
}