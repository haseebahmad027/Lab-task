

#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

class ArrayQueue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    ArrayQueue() : front(0), rear(-1) {}

    void enqueue(int value) {
        if (rear >= MAX_SIZE - 1) {
            std::cout << "Queue overflow! Cannot enqueue " << value << std::endl;
            return;
        }
        arr[++rear] = value;
    }

    void dequeue() {
        if (front > rear) {
            std::cout << "Queue underflow! Cannot dequeue." << std::endl;
            return;
        }
        front++;
    }

    void display() {
        if (front > rear) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        std::cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    ArrayQueue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display(); // Output: Queue elements: 10 20 30
    queue.dequeue();
    queue.display(); // Output: Queue elements: 20 30
    return 0;
}



