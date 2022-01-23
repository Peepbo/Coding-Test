#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SinglyLinkedList {
public:
	SinglyLinkedList(const int& val, const int& imp) :
		value{ val }, importance{ imp }, next{ nullptr }{};
public:
	int value, importance;
	SinglyLinkedList* next;
};

class Queue {
public:
	void push(const int& value, const int& importance) {
		if (back != nullptr) {
			back->next = new SinglyLinkedList(value, importance);
			back = back->next;
		}
		else {
			front = new SinglyLinkedList(value, importance);
			back = front;
		}
	}
	void pushNode(SinglyLinkedList* node) {
		if (front == nullptr) {
			front = node;
		}

		node->next = nullptr;
		back->next = node;
		back = node;
	}

	const int pop() {
		SinglyLinkedList* nextFront = nullptr;
		if (front->next != nullptr) {
			nextFront = front->next;
		}
		const int value = front->value;
		
		delete front;

		if (nextFront != nullptr) {
			front = nextFront;
		}
		else {
			front = back = nullptr;
		}

		return value;
	}
	SinglyLinkedList* reusePop() {
		SinglyLinkedList* returnNode = front;
		front = front->next;
		return returnNode;
	}

	const SinglyLinkedList* getFront() {
		return front;
	}

	const bool empty() {
		return front == nullptr;
	}
private:
	SinglyLinkedList* front = nullptr, * back = nullptr;
};

int main(void) {
	vector<int> print;
	Queue q;
	int T, N, M;
	cin >> T;

	while (T--) {
		cin >> N >> M; //M번째 문서는 언제 프린트되나?
		vector<int> order(N);
		int idx = 0, oIdx = 0, printOrder = 1, importance;

		while (N--) {
			cin >> importance;
			order[idx] = importance;
			q.push(idx++, importance);
		}
		sort(order.begin(), order.end(), greater<>());

		while (true) {
			if (q.getFront()->importance == order[oIdx]) {
				if (q.getFront()->value == M) {
					print.emplace_back(printOrder);
					break;
				}
				q.pop();
				oIdx++;
				printOrder++;
			}
			else {
				auto node = q.reusePop();
				q.pushNode(node);
			}
		}

		while (!q.empty()) {
			q.pop();
		}
	}

	for (const int& num : print) {
		cout << num << '\n';
	}

	return 0;
}