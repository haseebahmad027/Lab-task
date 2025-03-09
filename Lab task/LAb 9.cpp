#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
          Node* head;

public:
           CircularLinkedList() : head(nullptr) {}

              void insertAtStart(int value) {
          Node* newNode = new Node();
             newNode->data = value;
   if (!head) {
     head = newNode;
            newNode->next = head;
        } else {
                  Node* temp = head;
    while (temp->next != head) {
                temp = temp->next;
       }
                 temp->next = newNode;
         newNode->next = head;
          head = newNode;
        }
    }

    void insertAtEnd(int value) {
       Node* newNode = new Node();
            newNode->data = value;
                if (!head) {
                      head = newNode;
                 newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void displayReverse() {
        
        cout << "Cannot display in reverse order for circular list easily!" << endl;
    }
};

int main() {
    CircularLinkedList list;
    list.insertAtStart(10);
   list.insertAtEnd(20);
list.insertAtEnd(30);
    
    list.display(); 

    return 0;
}

