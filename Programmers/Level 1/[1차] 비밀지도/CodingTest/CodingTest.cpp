#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	string str;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			str += " ";
		}
		answer.push_back(str);
		str = "";
	}
	vector<int> check;
	int num = n - 1;
	while (num >= 0)
	{
		check.push_back(pow(2, num));
		num--;
		//2의 5승,4승,3승,2승,1승,0승
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check[j] > arr1[i]) {
				continue;
			}

			answer[i][j] = '#';
			if (check[i] - arr1[j] == 0) break;
			else {
				arr1[i] -= check[j];
				continue;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check[j] > arr2[i]) {
				continue;
			}

			answer[i][j] = '#';
			if (check[i] - arr2[j] == 0) break;
			else {
				arr2[i] -= check[j];
				continue;
			}
		}
	}
	return answer;
}

int main()
{
}