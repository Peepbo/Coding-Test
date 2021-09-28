#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer;

	for (int i = 0; i < numbers.size() - 1; i++)
	{
		int count = 0;
		for (int j = i + 1; j < numbers.size(); j++)
		{
			if (numbers[i] > numbers[j])
			{
				count++;
				break;
			}

			count++;
		}
		answer.push_back(count);
	}
	answer.push_back(0);

	return answer;
}

int main(void) {

	return 0;
}