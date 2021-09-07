#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Boxer {
	bool operator< (const Boxer& boxer) const {
		if (winRate != boxer.winRate)return winRate > boxer.winRate;
		if (heavyWin != boxer.heavyWin) return heavyWin > boxer.heavyWin;
		if (weight != boxer.weight) return weight > boxer.weight;
		return num < boxer.num;
	}
	int num, weight, heavyWin = 0;
	float winRate;
};

vector<int> solution(vector<int> weights, vector<string> head2head) {
	int number = weights.size(), total, win;
	char matchResult;
	vector<int> answer(number);
	vector<Boxer> boxers(number);

	for (int i = 0; i < number; i++) {
		boxers[i].num = i + 1;
		boxers[i].weight = weights[i];

		total = win = 0;

		for (int j = 0; j < number; j++) {
			matchResult = head2head[i][j];

			if (matchResult == 'N') continue;

			total++;

			if (matchResult != 'W') continue;

			win++;

			if (weights[i] < weights[j]) {
				boxers[i].heavyWin++;
			}
		}

		boxers[i].winRate = total == 0 ? 0 : ((float)win / total);
	}

	sort(boxers.begin(), boxers.end());

	for (int i = 0; i < number; i++) {
		answer[i] = boxers[i].num;
	}

	return answer;
}

int main() {
	//vector<int> weights{ 50,82,75,120 };
	//vector<string> head2head{ "NLWL","WNLL","LWNW","WWLN" };
	//vector<int> weights{ 145,92,86 };
	//vector<string> head2head{ "NLW","WNL","LWN" };
	vector<int> weights{ 60,70,60 };
	vector<string> head2head{ "NNN","NNN","NNN" };

	solution(weights, head2head);

	return 0;
}