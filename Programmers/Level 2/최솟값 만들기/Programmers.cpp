#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool compare(int A, int B)
{
	return A > B;
}

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), compare);

	int maxSize = A.size();
	for (int i = 0; i < maxSize; i++)
	{
		answer += A[i] * B[i];
	}

	return answer;
}

int main()
{
	cout << solution({ 1,4,2 }, { 5,4,4 });

	return 0;
}