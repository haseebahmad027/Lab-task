#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
public:
    Node* head;

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

    static SinglyLinkedList merge(SinglyLinkedList& list1, SinglyLinkedList& list2) {
        SinglyLinkedList mergedList;
        Node* temp = list1.head;
        while (temp) {
            mergedList.insertAtEnd(temp->data);
            temp = temp->next;
        }

        temp = list2.head;
        while (temp) {
            mergedList.insertAtEnd(temp->data);
            temp = temp->next;
        }

        return mergedList;
    }
};

int main() {
    SinglyLinkedList list1, list2;
    list1.insertAtEnd(10);
    list1.insertAtEnd(20);
    list2.insertAtEnd(30);
    list2.insertAtEnd(40);

    SinglyLinkedList mergedList = SinglyLinkedList::merge(list1, list2);
    mergedList.display();  // Output: 10 20 30 40

    return 0;
}

