#include <iostream>

using namespace std;

// 최대공약수, 유클리드 호제법
int gcd(int x, int y) {
	int a = max(x, y), b = min(x, y), c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

// 최소공배수
int lcm(int x, int y, int gcdValue) {
	return x * y / gcdValue;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b, gcdValue, lcmValue;
	cin >> a >> b;
	gcdValue = gcd(a, b);
	lcmValue = lcm(a, b, gcdValue);

	printf("%d\n%d", gcdValue, lcmValue);
}