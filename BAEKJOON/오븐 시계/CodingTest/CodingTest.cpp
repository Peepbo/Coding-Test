#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, C, Hour, Minute;
	cin >> A >> B >> C;
	Hour = A;
	Minute = B + C;

	if (Minute >= 60)
	{
		Hour += Minute / 60;
		Minute %= 60;
	}
	if (Hour >= 24)
	{
		Hour %= 24;
	}

	cout << Hour << ' ' << Minute;
	return 0;
}