#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* insert(Node* node, int newData) {
	if (node == NULL) {
		node = new Node();
		node->data = newData;
		node->left = NULL;
        node->right = NULL;
	}
    // 재귀
    // 현재 노드의 값보다 작은 경우
	else if (newData < node->data)
		node->left = insert(node->left, newData);
    // 현재 노드의 값보다 큰 경우
	else if (newData > node->data)
		node->right = insert(node->right, newData);

	return node;
}

void postOrder(Node* node) {
	if (node->left != NULL)
		postOrder(node->left);
	if (node->right != NULL)
		postOrder(node->right);
	cout << node->data << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Node* root = NULL;
	int val;

	while (cin >> val) {
		root = insert(root, val);
	}
	
	postOrder(root);

	return 0;
}