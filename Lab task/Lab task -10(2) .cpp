#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() : top(NULL) {}

    void push(int value) {
        Node* newNode = new Node(value);
        if (top == NULL) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack underflow! Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedListStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display(); // Output: Stack elements: 30 20 10
    stack.pop();
    stack.display(); // Output: Stack elements: 20 10
    return 0;
}

