#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int Answer, BanSize;
map<vector<int>, int> M;
vector<vector<int>> VV;

void recur(set<int> s, int depth) {
	if (depth == BanSize) {
		vector<int> list_id(s.begin(), s.end());

		if (M.find(list_id) == M.end()) {
			M[list_id]++;
			Answer++;
		}
		return;
	}

	for (const auto& num : VV[depth]) {
		auto temp = s;

		if (temp.find(num) != temp.end())continue;

		temp.insert(num);
		recur(temp, depth + 1);
	}
}

bool check(const string& id, const string& ban) {
	if (ban.size() != id.size())return false;

	for (int i = 0; i < ban.size(); i++) {
		if (ban[i] == '*')continue;
		if (ban[i] != id[i])return false;
	}

	return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
	BanSize = banned_id.size();

	VV.assign(BanSize, vector<int>());

	//가능성 구하기
	for (int ban = 0; ban < BanSize; ban++) {
		for (int id = 0; id < user_id.size(); id++) {
			if (!check(user_id[id], banned_id[ban]))continue;

			VV[ban].emplace_back(id);
		}
	}

	//조합 해보기
	for (const auto& num : VV[0]) {
		recur({ num }, 1);
	}

	return Answer;
}

int main() {
	solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" },
		{ "*rodo", "*rodo", "******" });

	return 0;
}