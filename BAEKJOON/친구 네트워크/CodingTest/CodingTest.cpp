#include <iostream>
#include <map>

using namespace std;

struct SFriend {
	// Minimum Index Friend
	int MIF;
	// Number of Friends
	int NOF;
};

SFriend Friend[200'010];
map<string, int> FriendMap;

int GetFriend(int a) {
	if (a == Friend[a].MIF)return a;
	return Friend[a].MIF = GetFriend(Friend[a].MIF);
}

bool IsSameFriend(int a, int b) {
	a = GetFriend(a);
	b = GetFriend(b);
	return a == b;
}

void UnionFriend(int a, int b) {
	a = GetFriend(a);
	b = GetFriend(b);
	if (a < b) {
		Friend[b].MIF = a;
		Friend[a].NOF += Friend[b].NOF;
	}
	else {
		Friend[a].MIF = b;
		Friend[b].NOF += Friend[a].NOF;
	}
}

bool isValid(string name) {
	return FriendMap.find(name) != FriendMap.end();
}

void Kruskal() {
	int F, FriendIndex;
	string F1, F2;
	int FIdx1, FIdx2;
	int MIF1, MIF2;
	int NOF1, NOF2;
	int printNumber;

	for (int i = 1; i <= 200'009; i++) {
		Friend[i].MIF = i;
		Friend[i].NOF = 1;
	}

	cin >> F;

	FriendIndex = 1;
	for (int i = 1; i <= F; i++) {
		cin >> F1 >> F2;

		if (!isValid(F1)) FriendMap[F1] = FriendIndex++;
		if (!isValid(F2)) FriendMap[F2] = FriendIndex++;

		FIdx1 = FriendMap[F1];
		FIdx2 = FriendMap[F2];
		if (!IsSameFriend(FIdx1, FIdx2)) {
			UnionFriend(FIdx1, FIdx2);

			MIF1 = Friend[FIdx1].MIF;
			MIF2 = Friend[FIdx2].MIF;

			NOF1 = Friend[MIF1].NOF;
			NOF2 = Friend[MIF2].NOF;

			printNumber = max(NOF1, NOF2);
		}
		else {
			MIF1 = Friend[FIdx1].MIF;
			NOF1 = Friend[MIF1].NOF;

			printNumber = NOF1;
		}

		cout << printNumber << '\n';
	}
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		FriendMap.clear();
		Kruskal();
	}
	return 0;
}