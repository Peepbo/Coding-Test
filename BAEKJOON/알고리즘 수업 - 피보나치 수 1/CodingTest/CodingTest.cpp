#include <iostream>

using namespace std;

int Fib1CallCount, Fib2CallCount;

int fib(int n)
{
	if (n == 1 || n == 2)
	{
		Fib1CallCount++;

		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

int F[2]{ 1,1 };

int fibonacci(int n)
{
	for (int i = 3; i <= n; i++)
	{
		Fib2CallCount++;

		int Temp = F[1];
		F[1] = F[0] + F[1];
		F[0] = Temp;
	}

	return F[1];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	fib(n);
	fibonacci(n);
	
	cout << Fib1CallCount << ' ' << Fib2CallCount;
	return 0;
}