

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getHeight(Node* node) {
    if (node == NULL ) {
        return 0;
    }
    return node->height;
}

void updateHeight(Node* node) {
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

int getBalanceFactor(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* node) {
    Node* temp = node->left;
    node->left = temp->right;
    temp->right = node;

    updateHeight(node);
    updateHeight(temp);

    return temp;
}

Node* leftRotate(Node* node) {
    Node* temp = node->right;
    node->right = temp->left;
    temp->left = node;

    updateHeight(node);
    updateHeight(temp);

    return temp;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    updateHeight(root);

    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1 && data < root->left->data) {
        return rightRotate(root);
    }
    if (balanceFactor < -1 && data > root->right->data) {
        return leftRotate(root);
    }
    if (balanceFactor > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balanceFactor < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    return 0;
}

