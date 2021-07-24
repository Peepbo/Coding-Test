#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
	Node(const int& _x, const int& _y, const int& _index)
		: x{ _x }, y{ _y }, index{ _index }, left{ nullptr }, right{ nullptr }{}
public:
	int x;
	int y;
	int index;
	Node* left;
	Node* right;

	bool operator<(Node& node) {
		if (y != node.y)return y > node.y;
		return x < node.x;
	}
};

void insert(Node* parent, Node* child) {
	if (parent->x > child->x) {
		if (parent->left == nullptr)
			parent->left = child;
		else
			insert(parent->left, child);
	}

	else {
		if (parent->right == nullptr)
			parent->right = child;
		else
			insert(parent->right, child);
	}
}

vector<int> prePrint;
vector<int> postPrint;

void preorder(Node* node) {
	if (node == nullptr)return;
	prePrint.emplace_back(node->index);
	preorder(node->left);
	preorder(node->right);
}

void postorder(Node* node) {
	if (node == nullptr) return;
	postorder(node->left);
	postorder(node->right);
	postPrint.emplace_back(node->index);
}

vector<Node> tree;

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;

	for (int i = 0; i < nodeinfo.size(); i++) {
		tree.push_back({ nodeinfo[i][0],nodeinfo[i][1],i + 1 });
	}

	sort(tree.begin(), tree.end());

	Node* root = &tree[0];
	for (int i = 1; i < tree.size(); i++) {
		insert(root, &tree[i]);
	}

	preorder(root);
	postorder(root);

	answer.push_back(prePrint);
	answer.push_back(postPrint);

	return answer;
}

int main() {
	solution({ {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} });

	return 0;
}