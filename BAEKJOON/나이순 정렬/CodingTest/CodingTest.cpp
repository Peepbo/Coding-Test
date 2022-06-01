#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Member
{
	int UniqueNumber;
	int Age;
	string Name;
	bool operator<(const Member& M) const
	{
		if (Age != M.Age)
		{
			return Age < M.Age;
		}
		return UniqueNumber < M.UniqueNumber;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, Age, UniqueNumber = 0;
	string Name;
	cin >> N;
	vector<Member> Members(N);
	while (N--)
	{
		cin >> Age >> Name;
		Members[N] = { UniqueNumber++, Age,Name };
	}
	sort(Members.begin(), Members.end());
	for (const Member& M : Members)
	{
		cout << M.Age << ' ' << M.Name << '\n';
	}
	return 0;
}