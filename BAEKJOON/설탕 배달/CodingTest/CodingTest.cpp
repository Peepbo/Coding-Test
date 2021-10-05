#include <iostream>
using namespace std;
int main()
{
	int N, count = 0;
	cin >> N;
	while (true)
	{
		if (N % 5 == 0) {
			N -= 5;
			count++;
		}
		else if (N % 3 == 0) {
			N -= 3;
			count++;
		}
		else if (N - 5 >= 0) {
			N -= 5;
			count++;
		}
		else N -= 3;

		if (N > 0 && N < 3) {
			count = -1;
			break;
		}
		else if (N == 0) break;
	}
	cout << count;
}