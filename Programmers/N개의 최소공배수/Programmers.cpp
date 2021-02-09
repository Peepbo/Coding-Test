#include <iostream>
#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b!=0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcs(int a, int b)
{
	return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
	int answer = arr.front();
	int size   = arr.size();
	for (int i = 1; i < size; i++)
	{
		answer = lcs(answer, arr[i]);
	}

	return answer;
}

int main()
{
	cout << solution({ 3,4,9,16 });

	return 0;
}