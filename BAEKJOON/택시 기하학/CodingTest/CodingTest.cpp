#include <iostream>

using namespace std;

#define PI 3.14159265359

int main(void) {
	double R;
	cin >> R;
	const double R2 = R * R;

	printf("%lf\n%lf", PI * R2, R2 * 2);

	return 0;
}