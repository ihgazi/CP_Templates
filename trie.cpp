#include <bits/stdc++.h>
using namespace std;

// Trie Data Structure for Strings

const int triesz = 26;
struct TrieNode {
	struct TrieNode* childNode[triesz];
	int wordEndCnt;

	TrieNode() {
		wordEndCnt = 0;
		for (int i = 0; i < 26; i++) {
			childNode[i] = NULL;
		}
	}
};

void insert_key(TrieNode* root, string key) {
	TrieNode* currentNode = root;
	
	for (auto c: key) {
		int index = c-'a';
		if (currentNode->childNode[index] == NULL) {
			TrieNode *newNode = new TrieNode();
			currentNode->childNode[index] = newNode;
		}
		currentNode = currentNode->childNode[index];
	}
	currentNode->wordEndCnt++;
}

bool search_key(TrieNode* root, string key) {
	TrieNode *currentNode = root;
	
	for (auto c: key) {
		int index = c-'a';
		if (currentNode->childNode[index] == NULL) {
			return false;
		}
		currentNode = currentNode->childNode[index];
	}

	return currentNode != NULL && currentNode->wordEndCnt > 0;
}

void delete_key(TrieNode* root, string key) {
	TrieNode *currentNode = root;

	for (auto c: key) {
		int index = c-'a';
		if (currentNode->childNode[index] == NULL) return;
		currentNode = currentNode->childNode[index];
	}

	if (currentNode != NULL && currentNode->wordEndCnt > 0) {
		currentNode->wordEndCnt--;
	}
}

int main() {
	TrieNode *root = new TrieNode();
	string s = "ant", t = "and";
	insert_key(root,s);
	insert_key(root,t);
	delete_key(root,s);
	cout << search_key(root,s);
}

