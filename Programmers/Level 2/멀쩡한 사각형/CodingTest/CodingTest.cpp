#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
	int c;
	if (b > a)
	{
		c = a;
		a = b;
		b = c;
	}

	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long solution(int w, int h) {
	long long max = (long long)w * h;
	
	int div = gcd(w, h);

	long long bW = w / div;
	long long bH = h / div;

	long long bNum = (bW + bH - 1) * div;

	return max - bNum;
}

int main()
{
	cout << solution(10, 5);

	return 0;
}