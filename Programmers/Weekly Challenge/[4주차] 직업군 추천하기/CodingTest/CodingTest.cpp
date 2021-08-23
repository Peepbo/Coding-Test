#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
	map<string, int> preference_Map;
	istringstream ss;
	string occupation, high_occupation, language;
	int preference_Size = preference.size(), table_Size = table.size(), score, language_score, high_score = 0;

	for (int i = 0; i < preference_Size; i++) {
		preference_Map[languages[i]] = preference[i];
	}

	for (int i = 0; i < table_Size; i++) {
		ss.str(table[i]);
		ss.clear();

		ss >> occupation;

		score = 0;
		language_score = 5;

		while (ss >> language) {
			score += preference_Map[language] * language_score--;
		}

		if ((high_occupation.empty() || high_score < score) ||
			(high_score == score && high_occupation > occupation)) {
			high_occupation = occupation;
			high_score = score;
		}
	}

	return high_occupation;
}

int main() {

	return 0;
}