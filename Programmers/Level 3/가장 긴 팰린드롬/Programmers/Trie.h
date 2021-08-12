#pragma once
#include <unordered_map>
#include <stack>

struct TrieNode {
	bool isEnd = false;
	std::unordered_map<char, TrieNode*> link;
};

struct EraseData {
	TrieNode* parent;
	char ch;
};

class Trie {
public:
	Trie() : root{ newNode() } {}
	~Trie() {
		while (!nodePtrs.empty()) {
			delete nodePtrs.top();
			nodePtrs.pop();
		}
	}
public:
	void Add(std::string word) {
		Add_recur(root, std::move(word));
	}
	bool Find(std::string word) {
		return Find_recur(root, std::move(word));
	}
	void Erase(std::string word) {
		if (!Find(word))return;

		auto cur = root;

		std::stack<EraseData> eraseDatas;

		while (!word.empty()) {
			eraseDatas.push({ cur,word[0] });

			cur = cur->link[word[0]];
			word = word.substr(1);
		}

		cur->isEnd = false;

		while (!eraseDatas.empty()) {
			auto data = eraseDatas.top();
			eraseDatas.pop();

			data.parent->link.erase(data.ch);

			if (!data.parent->link.empty()) break;
		}
	}
private:
	void Add_recur(TrieNode* node, std::string word) {
		if (word.empty()) {
			node->isEnd = true;
			return;
		}

		auto nextLink = node->link[word[0]];

		if (nextLink == nullptr) {
			nextLink = newNode();
			node->link[word[0]] = nextLink;
		}

		Add_recur(nextLink, word.substr(1));
	}
	bool Find_recur(TrieNode* node, std::string word) {
		if (word.empty()) return node->isEnd;
		if (node == nullptr) return false;

		auto nextLink = node->link[word[0]];

		if (nextLink == nullptr) return false;

		return Find_recur(nextLink, word.substr(1));
	}
	TrieNode* newNode() {
		nodePtrs.push(new TrieNode);
		return nodePtrs.top();
	}
private:
	TrieNode* root;
	std::stack<TrieNode*> nodePtrs;
};