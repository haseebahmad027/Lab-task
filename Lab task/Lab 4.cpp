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

    void insertAtPosition(int value, int position) {
       Node* newNode = new Node();
       newNode->data = value;

           if (position == 0) { 
            newNode->next = head;
          head = newNode;
        } else {
            Node* temp = head;
                for (int i = 0; temp != nullptr && i < position - 1; i++) {
                      temp = temp->next;
            }

            if (temp == nullptr) {
                cout << "Position out of Range!" << endl;
                delete newNode;
                return;
            }

            newNode->next = temp->next;
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
};

int main() {
SinglyLinkedList list;
    list.insertAtPosition(10, 0);
     list.insertAtPosition(20, 1);
       list.insertAtPosition(30, 2);
    list.insertAtPosition(15, 1);  
    
    list.display();

    return 0;
}

