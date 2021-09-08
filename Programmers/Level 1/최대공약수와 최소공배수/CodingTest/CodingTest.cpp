#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
	vector<int> answer;
	int num = n;
	while (num != 0)
	{
		if (m % num == 0)
		{
			answer.push_back(num);
			break;
		}
		else num--;
		while (n % num != 0) num--;
	}
	num = 1;
	int cul = m, inc = 1;
	while (true)
	{
		if (n * num < cul)
		{
			num++;
			continue;
		}
		else if (n * num == cul)
		{
			answer.push_back(cul);
			break;
		}
		else
		{
			num = 1;
			inc++;
			cul = m * inc;
		}
	}
	return answer;
}

int main() {
	return 0;
}