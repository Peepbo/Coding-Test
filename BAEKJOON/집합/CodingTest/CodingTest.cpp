#include <iostream>

using namespace std;

class BitMask20 {
public:
	bool IsActive(int idx) {
		return Mask & (1 << idx);
	}
	void Add(int idx) {
		Mask |= (1 << idx);
	}
	void Remove(int idx) {
		if (IsActive(idx)) {
			Mask &= ~(1 << idx);
		}
	}
	void Check(int idx) {
		cout << (IsActive(idx) ? "1\n" : "0\n");
	}
	void Toggle(int idx) {
		IsActive(idx) ? Remove(idx) : Add(idx);
	}
	void All() {
		Mask = (1 << 21) - 1;
	}
	void Empty() {
		Mask = 0;
	}
private:
	int Mask = 0;
};

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	BitMask20 BitMask;
	int M, idx;
	string Command;
	cin >> M;
	while (M--)
	{
		cin >> Command;

		if (Command == "all") {
			BitMask.All();
		}
		else if (Command == "empty") {
			BitMask.Empty();
		}
		else {
			cin >> idx;
			if (Command == "add") {
				BitMask.Add(idx);
			}
			else if (Command == "remove") {
				BitMask.Remove(idx);
			}
			else if (Command == "check") {
				BitMask.Check(idx);
			}
			else if (Command == "toggle") {
				BitMask.Toggle(idx);
			}
		}
	}

	return 0;
}