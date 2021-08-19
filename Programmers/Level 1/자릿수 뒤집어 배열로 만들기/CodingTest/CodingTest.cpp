#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
	vector<int> answer;
	long long number = n;
	while (number > 0)
	{
		answer.push_back(number % 10);
		number /= 10;
	}
	return answer;
}

int main() {

	return 0;
}