#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	int inc = 1;
	answer.push_back(arr[0]);
	for (int i = 1; i < arr.size(); i++)
	{
		if (answer[i - inc] != arr[i]) answer.push_back(arr[i]);
		else inc++;
	}

	return answer;
}

int main()
{

}