#include <iostream>

using namespace std;

int main(void) {
	int x, y, w, h, case1, case2;
	cin >> x >> y >> w >> h;

	case1 = min(x, y);
	case2 = min(abs(x - w), abs(y - h));

	cout << min(case1, case2);

	return 0;
}