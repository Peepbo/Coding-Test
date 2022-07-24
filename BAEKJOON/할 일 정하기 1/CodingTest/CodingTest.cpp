#include <iostream>
#include <bitset>

using namespace std;

int Arr[20][20];
int DP[1 << 20];
int N;

int Solve(int Bit, int Idx)
{
	if (Idx == N)
	{
		return 0;
	}
	if (DP[Bit] != 0)
	{
		return DP[Bit];
	}

	int Ret = 1e9;

	for (int i = 0; i < N; i++)
	{
		const bool bFlag = Bit & (1 << i);
		// i번 째 비트가 켜져있지 않으면
		if (!bFlag)
		{
			// Ret에 저장된 값과 비용 선택했을 때 최종 비용을 비교해
			// 더 작은 값을 저장한다.
			Ret = min(Ret, Arr[Idx][i] + Solve(Bit | (1 << i), Idx + 1));
		}
	}

	return DP[Bit] = Ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Arr[i][j];
		}
	}
	
	int Res = 1e9;
	for (int i = 0; i < N; i++)
	{
		Res = min(Res, Arr[0][i] + Solve(1 << i, 1));
	}

	cout << Res;
	return 0;
}