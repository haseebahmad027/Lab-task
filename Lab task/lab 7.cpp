#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // Insert at the beginning
    void insertAtStart(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        newNode->prev = nullptr;

        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            newNode->prev = temp;
            temp->next = newNode;
        }
    }

    // Display list in forward order
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display list in reverse order
    void displayReverse() {
        Node* temp = head;
        if (!temp) return;

        while (temp->next) {
            temp = temp->next;
        }

        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.insertAtStart(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "List in forward order: ";
    list.display();  // Output: 10 20 30

    cout << "List in reverse order: ";
    list.displayReverse();  // Output: 30 20 10

    return 0;
}

