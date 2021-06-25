#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
	vector<int> answer;

	sort(arr.begin(), arr.end());

	for (const auto& num : arr)
	{
		if (num % divisor == 0)answer.push_back(num);
	}

	if (answer.empty())answer.emplace_back(-1);
	return answer;
}

int main()
{

}