//write a c++ program to perform stack operations using linked list implementation



#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedListStack {
private:
    Node<T>* top;

public:
    LinkedListStack() : top(nullptr) {}

    // Function to push a new element onto the stack
    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
        std::cout << value << " pushed onto the stack.\n";
    }

    // Function to pop the top element from the stack
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow. Cannot pop from an empty stack.\n";
            return;
        }

        Node<T>* temp = top;
        top = top->next;
        std::cout << temp->data << " popped from the stack.\n";
        delete temp;
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // Function to display the elements of the stack
    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return;
        }

        std::cout << "Stack elements: ";
        Node<T>* current = top;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Function to get the top element of the stack without removing it
    T peek() const {
        if (isEmpty()) {
            std::cerr << "Error: Stack is empty.\n";
            exit(EXIT_FAILURE);
        }

        return top->data;
    }
};

int main() {
    // Example usage
    LinkedListStack<int> stack;

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
