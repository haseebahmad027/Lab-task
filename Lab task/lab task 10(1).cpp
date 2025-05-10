#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class ArrayStack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    ArrayStack() : top(-1) {}

    void push(int value) {
        if (top >= MAX_SIZE - 1) {
             cout << "Stack overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (top < 0) {
            std::cout << "Stack underflow! Cannot pop." << std::endl;
            return;
        }
        top--;
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display(); // Output: Stack elements: 10 20 30
    stack.pop();
    stack.display(); // Output: Stack elements: 10 20
    return 0;
}

