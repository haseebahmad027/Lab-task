#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void dfsTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    dfsTraversal(root->left);
    dfsTraversal(root->right);
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    cout << "DFS Traversal: ";
    dfsTraversal(root);
    return 0;
}


