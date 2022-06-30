#include <iostream>

using namespace std;

int Solve(int Number, int d)
{
	int Count = 0;
	long long TempD = d;
	while (Number / TempD > 0)
	{
		Count += Number / TempD;
		TempD *= d;
	}
	return Count;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	int NF2 = Solve(n, 2), NF5 = Solve(n, 5);
	int MF2 = Solve(m, 2), MF5 = Solve(m, 5);
	int SubF2 = Solve(n - m, 2), SubF5 = Solve(n-m,5);
	
	int Two = NF2 - (MF2 + SubF2);
	int Five = NF5 - (MF5 + SubF5);

	cout << min(Two, Five);
	return 0;
}