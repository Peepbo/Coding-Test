#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<vector<int>> scores) {
	string answer = "";
	int number_of_people = scores.size(), number_of_graders;
	int score_i_gave, maxScore, minScore, tempScore;
	float totalScore, averageScore;
	unordered_map<int, int> scoreMap;

	for (int target = 0; target < number_of_people; target++) { //점수를 받는 사람
		totalScore = 0;
		score_i_gave = scores[target][target];

		scoreMap.clear();

		maxScore = 0;
		minScore = 100;

		for (int grader = 0; grader < number_of_people; grader++) {
			tempScore = scores[grader][target];
			scoreMap[tempScore]++;

			totalScore += tempScore;

			maxScore = max(maxScore, tempScore);
			minScore = min(minScore, tempScore);
		}

		number_of_graders = number_of_people;

		if (scoreMap[score_i_gave] == 1) {
			if (score_i_gave == minScore || score_i_gave == maxScore) {
				totalScore -= score_i_gave;
				number_of_graders--;
			}
		}

		averageScore = totalScore / number_of_graders;

		if (averageScore >= 90)
			answer += 'A';
		else if (averageScore >= 80)
			answer += 'B';
		else if (averageScore >= 70)
			answer += 'C';
		else if (averageScore >= 50)
			answer += 'D';
		else
			answer += 'F';
	}

	return answer;
}

int main() {
	cout << solution({ {100,90,98,88,65},{50,45,99,85,77},{47,88,95,80,67},{61,57,100,80,65},{24,90,94,75,65} });

	return 0;
}