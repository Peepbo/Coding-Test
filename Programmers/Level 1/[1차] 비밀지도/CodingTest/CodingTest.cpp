#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> binarize(int& decimal, const int& n)
{
	vector<int> output(n);

	int idx = n - 1;

	while (decimal > 0)
	{
		output[idx--] = decimal % 2;
		decimal /= 2;
	}

	return output;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer(n);
	vector<int> mapPiece1, mapPiece2;

	for (int i = 0; i < n; i++)
	{
		mapPiece1 = binarize(arr1[i], n);
		mapPiece2 = binarize(arr2[i], n);

		for (int j = 0; j < n; j++)
		{
			if (mapPiece1[j] == 1 || mapPiece2[j] == 1)
				answer[i] += "#";
			else
				answer[i] += " ";
		}
	}

	return answer;
}

int main()
{
	int n = 5;
	vector<int> arr1{ 9,20,28,18,11 }, arr2{ 30,1,21,17,28 };
	
	vector<string> v = solution(n, arr1, arr2);

	for (const auto& it : v)
	{
		cout << it << '\n';
	}
}