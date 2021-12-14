#include <iostream>
#include <vector>

using namespace std;

pair<int, int> link[100'001];
int inorderList[100'001], postorderList[100'001];

struct Range {
	int start, end;
};

void findRoot(int root, const Range& inrange,
	Range& leftRange, Range& rightRange) {
	for (int i = inrange.start; i <= inrange.end; i++) {
		if (inorderList[i] == root) {
			leftRange = { inrange.start, i - 1 };
			rightRange = { i + 1, inrange.end };
			break;
		}
	}
}

void recur(Range inRange, Range postRange) {
	if (inRange.end < inRange.start ||
		postRange.end < postRange.start)return;

	int root = postorderList[postRange.end];
	Range leftRange, rightRange;
	findRoot(root, inRange, leftRange, rightRange);

	int leftIdx = postRange.start + (leftRange.end - leftRange.start);
	int rightIdx = leftIdx + 1 + (rightRange.end - rightRange.start);

	if (leftRange.end >= leftRange.start) {
		link[root].first = postorderList[leftIdx];
	}
	if (rightRange.end >= rightRange.start) {
		link[root].second = postorderList[rightIdx];
	}

	recur(leftRange, { postRange.start,leftIdx });
	recur(rightRange, { leftIdx + 1,rightIdx });
}

void preorder(int index) {
	if (index == 0)return;

	cout << index << ' ';
	preorder(link[index].first);
	preorder(link[index].second);
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// Init
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> inorderList[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> postorderList[i];
	}

	recur({ 1,n }, { 1,n });

	preorder(postorderList[n]);
	return 0;
}