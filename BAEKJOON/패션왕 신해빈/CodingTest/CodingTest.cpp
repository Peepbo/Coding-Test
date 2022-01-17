#include <iostream>
#include <map>

using namespace std;

map<string, int> m;

int calculus(int f) {
	if (f == 0)return 0;
	return (f * (f + 1)) / 2 + calculus(f - 1);
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, n, way;
	string name, kind;
	cin >> T;
	while (T--) {
		cin >> n;
		way = 1;
		m.clear();

		while (n--) {
			cin >> name >> kind;
			m[kind]++;
		}

		for (const auto& pr : m) {
			way *= pr.second + 1;
		}
		cout << way - 1 << '\n';
	}
}