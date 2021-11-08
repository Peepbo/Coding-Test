#include <iostream>
#include <vector>

using namespace std;

class Stack {
public:
	void Command(string command) {
		if (command == "push") Push();
		else if (command == "pop") Pop();
		else if (command == "size") Size();
		else if (command == "empty") Empty();
		else if (command == "top") Top();
	}
	void PrintMessage() {
		for (const int& me : message) {
			cout << me << '\n';
		}
	}
private:
	void Push() {
		int number;
		cin >> number;
		arr.emplace_back(number);
	}
	void Pop() {
		if (arr.empty()) message.emplace_back(-1);
		else {
			message.emplace_back(arr.back());
			arr.pop_back();
		}
	}
	void Top() {
		if (arr.empty()) message.emplace_back(-1);
		else {
			message.emplace_back(arr.back());
		}
	}
	void Size() {
		message.emplace_back(arr.size());
	}
	void Empty() {
		message.emplace_back(arr.empty());
	}
private:
	vector<int> arr, message;
};

int main(void) {
	Stack stack;
	string input;
	int N;
	cin >> N;

	while (N--) {
		cin >> input;
		stack.Command(input);
	}

	stack.PrintMessage();
	return 0;
}