#include <iostream>
#include <unordered_set>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_set<string> WordList;
	string Word, SubWord;
	cin >> Word;

	/* s : 시작, e : 끝 */
	for (int s = 0; s < Word.length(); s++)
	{
		for (int e = s; e < Word.length(); e++)
		{
			SubWord = Word.substr(s, e - s + 1);

			WordList.insert(SubWord);
		}
	}

	cout << WordList.size();
	return 0;
}