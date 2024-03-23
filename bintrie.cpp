#include <bits/stdc++.h>
using namespace std;

// Binary Trie to store number

class node {
	public:
	node *left;
	node *right;
	node() {
		left = NULL;
		right = NULL;
	}
};

void insert(int x, node *head) {
	node *curr = head;
	for (int i = 30; i >= 0; i--) {
		int val = (x>>i)&1;

		if (val == 0) {
			if (!curr->left) curr->left = new node();
			curr = curr->left;
		}
		else {
			if (!curr->right) curr->right = new node();
			curr = curr->right;
		}
	}
}

int findMaximumXOR(int arr[], int n) {
	node *head = new node();
	
	for (int i = 0; i < n; i++) {
		insert(arr[i],head);
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		int currxor = 0;
		node *curr = head;

		for (int j = 30; j >= 0; j--) {
			int val = (arr[i] >> j) & 1;
			if (val == 0) {
				if (curr->right) {
					currxor += (1<<j);
					curr = curr->right;
				}
				else curr = curr->left;
			}
			else {
				if (curr->left) {
					currxor += (1<<j);
					curr = curr->left;
				}
				else {
					curr = curr->right;
				}
			}
		}
		ans = max(ans,currxor);
	}
	
	return ans;
}


int main() {
	int arr[] = {1,2,3,4};
	cout << findMaximumXOR(arr,4);
	return 0;
}

