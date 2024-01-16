//Write a c++ program to display Fibonacci series (i) using recursion, (ii) using iteration

#include <iostream>

// Function to generate Fibonacci series using recursion
int fibonacciRecursive(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }
}

// Function to generate Fibonacci series using iteration
void fibonacciIterative(int n) {
    int a = 0, b = 1, nextTerm;
    std::cout << "Fibonacci series using iteration: ";

    for (int i = 0; i < n; ++i) {
        std::cout << a << " ";
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    }

    std::cout << std::endl;
}

int main() {
    int terms;

    // Input from the user
    std::cout << "Enter the number of terms for Fibonacci series: ";
    std::cin >> terms;

    // Generate Fibonacci series using recursion
    std::cout << "Fibonacci series using recursion: ";
    for (int i = 0; i < terms; ++i) {
        std::cout << fibonacciRecursive(i) << " ";
    }
    std::cout << std::endl;

    // Generate Fibonacci series using iteration
    fibonacciIterative(terms);

    return 0;
}
