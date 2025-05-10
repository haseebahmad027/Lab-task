

#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

class LinkedListQueue {
private:
    Node* front;
    Node* rear;

public:
    LinkedListQueue() : front(NULL), rear(NULL) {}

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == NULL) {
            std::cout << "Queue underflow! Cannot dequeue." << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }

    void display() {
        if (front == NULL) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        Node* temp = front;
        std::cout << "Queue elements: ";
        while (temp != NULL) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedListQueue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display(); // Output: Queue elements: 10 20 30
    queue.dequeue();
    queue.display(); // Output: Queue elements: 20 30
    return 0;
}
