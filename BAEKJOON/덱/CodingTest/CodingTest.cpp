#include <iostream>
#include <vector>

using namespace std;

class SinglyLinkedList {
public:
	SinglyLinkedList(int val) :
		value{ val }, prev{ nullptr }, next{ nullptr }{}
public:
	int value;
	SinglyLinkedList* prev, * next;
};

typedef void(*func)(void);

class Deque {
public:
	void command() {
		cin >> input;
		if (input.size() == 4) {
			if (input == "size")size();
			else back();
		}
		else if (input.size() == 5) {
			if (input == "empty")empty();
			else front();
		}
		else {
			if (input == "push_front")push_front();
			else if (input == "push_back")push_back();
			else if (input == "pop_front")pop_front();
			else pop_back();
		}
	}
	void print() {
		for (const int& num : message) {
			cout << num << '\n';
		}
	}
private:
	void push_front() {
		cin >> num;
		SinglyLinkedList* newNode = new SinglyLinkedList(num);
		if (frontNode == nullptr) {
			frontNode = newNode;
			backNode = frontNode;
		}
		else {
			frontNode->prev = newNode;
			newNode->next = frontNode;
			frontNode = newNode;
		}
		nodeCount++;
	}
	void push_back() {
		cin >> num;
		SinglyLinkedList* newNode = new SinglyLinkedList(num);
		if (backNode == nullptr) {
			backNode = newNode;
			frontNode = backNode;
		}
		else {
			backNode->next = newNode;
			newNode->prev = backNode;
			backNode = newNode;
		}
		nodeCount++;
	}
	void pop_front() {
		if (nodeCount == 0) {
			message.emplace_back(-1);
		}
		else {
			SinglyLinkedList* delNode = frontNode;
			message.emplace_back(delNode->value);

			if (nodeCount == 1) {
				delete delNode;
				frontNode = backNode = nullptr;
			}
			else {
				frontNode = frontNode->next;
				frontNode->prev = nullptr;
				delete delNode;
			}

			nodeCount--;
		}
	}
	void pop_back() {
		if (nodeCount == 0) {
			message.emplace_back(-1);
		}
		else {
			SinglyLinkedList* delNode = backNode;
			message.emplace_back(delNode->value);

			if (nodeCount == 1) {
				delete delNode;
				frontNode = backNode = nullptr;
			}
			else {
				backNode = backNode->prev;
				backNode->next = nullptr;
				delete delNode;
			}

			nodeCount--;
		}
	}
	void size() {
		message.emplace_back(nodeCount);
	}
	void empty() {
		message.emplace_back(nodeCount == 0);
	}
	void front() {
		message.emplace_back(nodeCount == 0 ? -1 : frontNode->value);
	}
	void back() {
		message.emplace_back(nodeCount == 0 ? -1 : backNode->value);
	}
private:
	vector<int> message;
	string input;
	int num, nodeCount = 0;

	SinglyLinkedList* frontNode = nullptr, * backNode = nullptr;
};

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Deque dq;
	int N;
	cin >> N;
	while (N--) {
		dq.command();
	}

	dq.print();
	return 0;
}