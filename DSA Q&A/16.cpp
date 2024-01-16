//Write a c++ program to reverse the order of the elements in the stack using additional stack.

#include <iostream>
#include <stack>

// Function to reverse the order of elements in a stack using an additional stack
void reverseStack(std::stack<int>& originalStack) {
    std::stack<int> auxiliaryStack;

    // Push elements from the original stack to the auxiliary stack
    while (!originalStack.empty()) {
        auxiliaryStack.push(originalStack.top());
        originalStack.pop();
    }

    // Pop elements from the auxiliary stack back to the original stack
    while (!auxiliaryStack.empty()) {
        originalStack.push(auxiliaryStack.top());
        auxiliaryStack.pop();
    }
}

int main() {
    std::stack<int> myStack;

    // Push some elements onto the stack
    for (int i = 1; i <= 5; ++i) {
        myStack.push(i);
    }

    // Display the original stack
    std::cout << "Original Stack: ";
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    // Push the elements back onto the stack
    for (int i = 1; i <= 5; ++i) {
        myStack.push(i);
    }

    // Reverse the order of elements in the stack
    reverseStack(myStack);

    // Display the reversed stack
    std::cout << "Reversed Stack: ";
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    return 0;
}
