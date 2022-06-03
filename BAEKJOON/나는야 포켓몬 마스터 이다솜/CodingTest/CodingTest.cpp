#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<string, string> IllustratedBook;
	int N, M, Index = 1;
	string Input, IndexString;
	cin >> N >> M;
	while (N--)
	{
		cin >> Input;

		IndexString = to_string(Index);
		IllustratedBook[IndexString] = Input;
		IllustratedBook[Input] = IndexString;
		Index++;
	}
	while (M--)
	{
		cin >> Input;

		if (IllustratedBook.find(Input) != IllustratedBook.end())
		{
			cout << IllustratedBook[Input] << '\n';
		}
	}

	return 0;
}