// BST Hard with duplicate elements only on the right child
// Karthik Balaji Keshavamurthi

#include <algorithm>
#include <iostream>
#include <vector>
#include<map>


using namespace std;


struct Node {
	int key;
	int left;
	int right;

	Node() : key(0), left(-1), right(-1) {}
	Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBST(const vector<Node>& tree, int max, int min, int index) {
	if (index == -1) {
		return true;
	}
	if (tree[index].key < min || tree[index].key >= max) {
		return false;
	}
	else {
		return (IsBST(tree, tree[index].key, min, tree[index].left) && IsBST(tree, max, tree[index].key, tree[index].right));
	}
}

bool IsBinarySearchTree(const vector<Node>& tree) {
	int max = INT_MAX;
	int min = INT_MIN;
	if (tree.size() < 1) {
		return true;
	}
	return IsBST(tree, max,min ,0);
	// Implement correct algorithm here
	
}

int main() {
	int nodes;
	cin >> nodes;
	vector<Node> tree;
	for (int i = 0; i < nodes; ++i) {
		int key, left, right;
		cin >> key >> left >> right;
		tree.push_back(Node(key, left, right));
	}
	if (IsBinarySearchTree(tree)) {
		cout << "CORRECT" << endl;
	}
	else {
		cout << "INCORRECT" << endl;
	}
	return 0;
}
