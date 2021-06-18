#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer;

	set<int> _set;
	set<int>::iterator iter;

	for (int i = 0; i < numbers.size() - 1; i++)
	{
		for (int j = i + 1; j < numbers.size(); j++)
		{
			_set.insert(numbers[i] + numbers[j]);
		}
	}

	for (iter = _set.begin(); iter != _set.end(); ++iter)
	{
		answer.push_back(*iter);
	}

	return answer;
}

int main()
{

}