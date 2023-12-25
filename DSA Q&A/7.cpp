//  write a c++ program to Perform Stack operations using Array implementation. Use Templates

#include <iostream>

const int MAX_SIZE = 100;  // Maximum size of the stack

template <typename T>
class ArrayStack {
private:
    T stackArray[MAX_SIZE];
    int top;

public:
    ArrayStack() : top(-1) {}

    // Function to push a new element onto the stack
    void push(T value) {
        if (top == MAX_SIZE - 1) {
            std::cout << "Stack overflow. Cannot push onto a full stack.\n";
            return;
        }

        stackArray[++top] = value;
        std::cout << value << " pushed onto the stack.\n";
    }

    // Function to pop the top element from the stack
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow. Cannot pop from an empty stack.\n";
            return;
        }

        std::cout << stackArray[top--] << " popped from the stack.\n";
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Function to display the elements of the stack
    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return;
        }

        std::cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i) {
            std::cout << stackArray[i] << " ";
        }
        std::cout << std::endl;
    }

    // Function to get the top element of the stack without removing it
    T peek() const {
        if (isEmpty()) {
            std::cerr << "Error: Stack is empty.\n";
            exit(EXIT_FAILURE);
        }

        return stackArray[top];
    }
};

int main() {
    // Example usage
    ArrayStack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    std::cout << "Top element: " << stack.peek() << std::endl;

    stack.pop();
    stack.display();

    std::cout << "Top element: " << stack.peek() << std::endl;

    stack.pop();
    stack.pop();  // Trying to pop from an empty stack
    stack.display();

    return 0;
}
