#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, W, H;
	float T;
	cin >> N >> W >> H;

	const float Diagonal = sqrt(W * W + H * H);
	while (N--)
	{
		cin >> T;
		if (T <= Diagonal)
		{
			cout << "DA" << '\n';
		}
		else
		{
			cout << "NE" << '\n';
		}
	}

	return 0;
}