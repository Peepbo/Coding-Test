#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 2000000000

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int l = 0, r = N - 1, min = INF, output[2], sum;

	while (l < r)
	{
		sum = v[l] + v[r];

		if (abs(sum) < min)
		{
			min = abs(sum);
			output[0] = v[l];
			output[1] = v[r];
		}

		if (sum < 0)
			l++;
		else
			r--;
	}

	printf("%d %d", output[0], output[1]);
}