#include <iostream>
#include <vector>

using namespace std;

class LinkedList {
public:
	LinkedList(int val) :
		value{ val } {}
public:
	int value;
	LinkedList* next = nullptr;
};

class Queue {
public:
	void Read() {
		cin >> command;
		if (command == "push")Push();
		else if (command == "pop")Pop();
		else if (command == "size")Size();
		else if (command == "empty")Empty();
		else if (command == "front")Front();
		else if (command == "back")Back();
	}
	void PrintMessage() {
		for (const int& num : message) {
			cout << num << '\n';
		}
	}
private:
	void Push() {
		cin >> num;
		if (size == 0) {
			frontNode = new LinkedList(num);
			backNode = frontNode;
		}
		else {
			backNode->next = new LinkedList(num);
			backNode = backNode->next;
		}
		size++;
	}
	void Pop() {
		if (size == 0) {
			message.emplace_back(-1);
		}
		else {
			message.emplace_back(frontNode->value);
			LinkedList* delNode = frontNode;
			frontNode = frontNode->next;
			delete delNode;

			size--;
		}
	}
	void Size() {
		message.emplace_back(size);
	}
	void Empty() {
		message.emplace_back(size == 0);
	}
	void Front() {
		if (size == 0) {
			message.emplace_back(-1);
		}
		else {
			message.emplace_back(frontNode->value);
		}
	}
	void Back() {
		if (size == 0) {
			message.emplace_back(-1);
		}
		else {
			message.emplace_back(backNode->value);
		}
	}
private:
	LinkedList* frontNode = nullptr, * backNode = nullptr;
	vector<int> message;
	string command;
	int size = 0, num;
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Queue q;
	int N;
	cin >> N;
	while (N--) {
		q.Read();
	}

	q.PrintMessage();
	return 0;
}