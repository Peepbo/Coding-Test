#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int InputDice;
	int Combo = 0, ComboIndex = 0, HighIndex = 0, Money = 0;
	int Dice[7]{ 0 };

	for (int i = 0; i < 3; i++)
	{
		cin >> InputDice;
		if (Combo <= ++Dice[InputDice])
		{
			Combo = Dice[InputDice];
			ComboIndex = InputDice;
			HighIndex = max(HighIndex, InputDice);
		}
	}
	switch (Combo)
	{
	case 1:
		Money += HighIndex * 100;
		break;
	case 2:
		Money += 1'000 + ComboIndex * 100;
		break;
	case 3:
		Money += 10'000 + ComboIndex * 1'000;
		break;
	}

	cout << Money;
	return 0;
}