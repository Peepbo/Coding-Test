#include <iostream>

using namespace std;

class binaryData {
public:
	int value = 0;
	binaryData* left = nullptr, * right = nullptr;
};

binaryData binaryTree[10'001];

void insertData(binaryData* now, int val, int index) {
	if (now->value == 0) {
		now->value = val;
	}
	else if (val > now->value) {
		if (now->right == nullptr) {
			now->right = &binaryTree[index];
			now->right->value = val;
		}
		else {
			insertData(now->right, val, index);
		}
	}
	else if (val < now->value) {
		if (now->left == nullptr) {
			now->left = &binaryTree[index];
			now->left->value = val;
		}
		else {
			insertData(now->left, val, index);
		}
	}
}

void postorder(binaryData* now) {
	if (now == nullptr)return;

	postorder(now->left);
	postorder(now->right);
	cout << now->value << '\n';
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int idx = 1, value;
	while (cin >> value) {
		insertData(&binaryTree[1], value, idx++);
	}

	postorder(&binaryTree[1]);

	return 0;
}