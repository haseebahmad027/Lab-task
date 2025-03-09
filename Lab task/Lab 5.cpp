#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display first node
    void displayFirst() {
        if (head) cout << "First node: " << head->data << endl;
        else cout << "List is empty!" << endl;
    }

    // Display last node
    void displayLast() {
        if (head) {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            cout << "Last node: " << temp->data << endl;
        } else {
            cout << "List is empty!" << endl;
        }
    }

    // Display Nth node
    void displayNth(int n) {
        Node* temp = head;
        int count = 0;
        while (temp) {
            if (count == n) {
                cout << "Nth node: " << temp->data << endl;
                return;
            }
            count++;
           temp = temp->next;
        }
        cout << "Position out of range!" << endl;
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    list.displayFirst();   
    list.displayLast();    
    list.displayNth(1);    

    return 0;
}

