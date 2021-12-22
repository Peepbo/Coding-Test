#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt[2][4'001];

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, sum = 0;
	float avr;
	int iAvr, center, most = 0, range;
	int value, mostCnt = 0, lastMost = 0;
	vector<int> mostOrder;
	bool isEss;
	cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> vec[i];

		sum += vec[i];

		isEss = vec[i] > 0;
		value = abs(vec[i]);
		cnt[isEss][value]++;

		if (mostCnt < cnt[isEss][value]) {
			mostCnt = cnt[isEss][value];
			mostOrder.clear();
			mostOrder.emplace_back(vec[i]);
		}
		else if(mostCnt == cnt[isEss][value]) {
			mostOrder.emplace_back(vec[i]);
		}
	}
	avr = (float)sum / N;
	int avrTemp = abs(avr * 10);
	if (avrTemp % 10 >= 5) {
		iAvr = (int)avr + (avr > 0 ? 1 : -1);
	}
	else {
		iAvr = avr;
	}

	sort(vec.begin(), vec.end());
	sort(mostOrder.begin(), mostOrder.end());

	center = vec[N / 2];
	range = abs(vec.front() - vec.back());
	most = mostOrder.size() == 1 ? mostOrder[0] : mostOrder[1];

	printf("%d\n%d\n%d\n%d", iAvr, center, most, range);
}