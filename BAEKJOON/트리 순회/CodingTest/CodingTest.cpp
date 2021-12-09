#include <iostream>
#include <vector>

using namespace std;

pair<int, int> link[27];

void preorder(int index) {
	if (index == 0)return;

	cout << char(index - 1 + 'A'); // root
	preorder(link[index].first);   // left
	preorder(link[index].second);  // right
}

void inorder(int index) {
	if (index == 0)return;

	inorder(link[index].first);	   // left
	cout << char(index - 1 + 'A'); // root
	inorder(link[index].second);   // right
}

void postorder(int index) {
	if (index == 0)return;

	postorder(link[index].first);  // left
	postorder(link[index].second); // right
	cout << char(index - 1 + 'A'); // root
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	char cRoot, cLeft, cRight;
	int N, iRoot, iLeft, iRight;
	cin >> N;

	// Init
	for (int i = 1; i <= N; i++) {
		cin >> cRoot >> cLeft >> cRight;
		iRoot = cRoot - 'A' + 1;
		if (cLeft != '.') {
			link[iRoot].first = cLeft - 'A' + 1;
		}
		if (cRight != '.') {
			link[iRoot].second = cRight - 'A' + 1;
		}
	}

	preorder(1);
	cout << '\n';
	inorder(1);
	cout << '\n';
	postorder(1);
	return 0;
}