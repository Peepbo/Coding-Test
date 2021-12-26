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
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, A, B;
	cin >> T;

	while (T--) {
		cin >> A >> B;
		cout << lcm(A, B) << '\n';
	}
}