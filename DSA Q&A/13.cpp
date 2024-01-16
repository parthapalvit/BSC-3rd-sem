//Write a c++  dsa programe to calculate GCD(Greatest Common Divisor) of 2 number (i) with recursion (ii) without recursion

#include <iostream>

// Function to calculate GCD using recursion
int gcdRecursive(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcdRecursive(b, a % b);
    }
}

// Function to calculate GCD without recursion (using iteration)
int gcdIterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    // Input from the user
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    // Calculate GCD using recursion
    int gcdRec = gcdRecursive(num1, num2);
    std::cout << "GCD using recursion: " << gcdRec << std::endl;

    // Calculate GCD without recursion (using iteration)
    int gcdIte = gcdIterative(num1, num2);
    std::cout << "GCD without recursion (using iteration): " << gcdIte << std::endl;

    return 0;
}
