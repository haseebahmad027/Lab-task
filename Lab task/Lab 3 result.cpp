#include <iostream>
using namespace std;

struct Node {
      int data;
          Node* next;
};

class SinglyLinkedList 
{
private:
    Node* head;
    
public:
    SinglyLinkedList() : head(nullptr) {}

    
    void insertAtStart(int value) {
          Node* newNode = new Node();
      newNode->data = value;
    newNode->next = head;
                   head = newNode  ;
  }

    
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
};

int main() {
  SinglyLinkedList list;
    
    list.insertAtStart(10);
    list.insertAtEnd(20);
    list.insertAtStart(5);
    list.insertAtEnd(30);
    
list.display();

            return 0;
}

