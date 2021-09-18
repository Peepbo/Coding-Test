#include <string>
#include <vector>
#include <set>

using namespace std;

int Answer, Banned_Size;
set<set<int>> Candidate;
vector<vector<int>> Candidate_list;

bool isCandidate(const string& id, const string& banned_id) {
	if (banned_id.size() != id.size())return false;

	for (int i = 0; i < banned_id.size(); i++) {
		if (banned_id[i] != '*' && banned_id[i] != id[i])return false;
	}

	return true;
}

void backTracking(set<int>& s, int depth) {
	if (depth == Banned_Size) {
		if (Candidate.find(s) == Candidate.end()) {
			Candidate.insert(s);
			Answer++;
		}
		return;
	}

	for (const int& num : Candidate_list[depth]) {
		if (s.find(num) != s.end())continue;

		s.insert(num);
		backTracking(s, depth + 1);
		s.erase(num);
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	Banned_Size = banned_id.size();

	Candidate_list.assign(Banned_Size, vector<int>());

	//후보자 구하기
	for (int banned = 0; banned < Banned_Size; banned++) {
		for (int user = 0; user < user_id.size(); user++) {
			if (isCandidate(user_id[user], banned_id[banned]) == false)continue;

			Candidate_list[banned].emplace_back(user);
		}
	}

	//조합 해보기
	for (const int& num : Candidate_list[0]) {
		set<int> s{ num };
		backTracking(s, 1);
	}

	return Answer;
}

int main() {
	solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" },
		{ "*rodo", "*rodo", "******" });

	return 0;
}