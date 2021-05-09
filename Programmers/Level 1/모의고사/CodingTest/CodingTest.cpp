#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> input) {
	vector<int> answer;
	int A[5] = { 1,2,3,4,5 };
	int B[8] = { 2,1,2,3,2,4,2,5 };
	int C[10] = { 3,3,1,1,2,2,4,4,5,5 };
	int aScore, bScore, cScore;
	aScore = bScore = cScore = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (A[i % 5] == input[i])aScore++;
		if (B[i % 8] == input[i])bScore++;
		if (C[i % 10] == input[i])cScore++;
	}
	int highScore = aScore;
	if (highScore < bScore)highScore = bScore;
	if (highScore < cScore)highScore = cScore;

	int arr[3] = { aScore,bScore,cScore };
	int child[3] = { 1,2,3 };
	for (int i = 0; i < 3; i++)
	{
		if (arr[i] == highScore)answer.push_back(child[i]);
	}

	return answer;
}

int main()
{
}