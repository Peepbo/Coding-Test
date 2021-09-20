#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
	bool answer = true;

	int cul = 0;
	int num = x;
	while (num > 0)
	{
		cul += num % 10;
		num /= 10;
	}
	if (x % cul != 0)answer = false;

	return answer;
}

int main() {

	return 0;
}