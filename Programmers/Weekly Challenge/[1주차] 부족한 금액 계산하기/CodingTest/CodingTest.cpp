using namespace std;

long long solution(int price, int money, int count)
{
	long long need = 0, nextPrice = 0;

	while (count--) {
		nextPrice += price;
		need += nextPrice;
	}

	return money - need >= 0 ? 0 : need - money;
}

int main() {
	solution(3, 20, 4);

	return 0;
}