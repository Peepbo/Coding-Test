#include <iostream>
#include <vector>

using namespace std;

class SinglyLinkedList {
public:
	SinglyLinkedList(const int& val) :
		value{ val }, next{ nullptr }{};
public:
	int value;
	SinglyLinkedList* next;
};

class Queue {
public:
	void push(const int& value) {
		if (back != nullptr) {
			back->next = new SinglyLinkedList(value);
			back = back->next;
		}
		else {
			front = new SinglyLinkedList(value);
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
		SinglyLinkedList* nextFront = front->next;
		const int value = front->value;
		delete front;
		front = nextFront;

		return value;
	}
	SinglyLinkedList* reusePop() {
		SinglyLinkedList* returnNode = front;
		front = front->next;
		return returnNode;
	}
private:
	SinglyLinkedList* front = nullptr, * back = nullptr;
};

int main(void) {
	Queue q;
	int N, K, arrIdx = -1;
	cin >> N >> K;
	vector<int> arr(N);

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (N--) {
		for (int i = 0; i < K - 1; i++) {
			SinglyLinkedList* node = q.reusePop();
			q.pushNode(node);
		}
		const int value = q.pop();
		arr[++arrIdx] = value;
	}

	cout << '<';
	for (int i = 0; i <= arrIdx; i++) {
		cout << arr[i];
		if (i != arrIdx)cout << ", ";
	}
	cout << '>';

	return 0;
}