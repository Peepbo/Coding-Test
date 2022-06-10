#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int Euclidean(int a, int b)
{
	if (a < b)
	{
		swap(a, b);
	}

	int c;
	while (b > 0)
	{
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int Input;
	vector<int> Arr(N);
	set<int> M;

	for (int i = 0; i < N; i++)
	{
		cin >> Arr[i];
	}
	sort(Arr.begin(), Arr.end());

	int gcd = Arr[1] - Arr[0];
	for (int i = 2; i < N; i++)
	{
		gcd = Euclidean(gcd, Arr[i] - Arr[i - 1]);
	}

	M.insert(gcd);
	for (int i = 2; i * i <= gcd; i++)
	{
		if (gcd % i == 0)
		{
			M.insert(i);
			M.insert(gcd / i);
		}
	}

	for (int m : M)
	{
		cout << m << ' ';
	}
	return 0;
}