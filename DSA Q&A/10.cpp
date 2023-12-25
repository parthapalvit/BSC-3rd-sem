//write a c++ program to Write a program to scan a polynomial using linked list and add two polynomial.


#include <iostream>

class Node {
public:
    int coefficient;
    int exponent;
    Node* next;

    Node(int coeff, int exp) : coefficient(coeff), exponent(exp), next(nullptr) {}
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() : head(nullptr) {}

    // Function to insert a term into the polynomial
    void insertTerm(int coeff, int exp) {
        Node* newNode = new Node(coeff, exp);

        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to add two polynomials
    Polynomial addPolynomials(const Polynomial& poly2) const {
        Polynomial result;
        Node* current1 = head;
        Node* current2 = poly2.head;

        while (current1 && current2) {
            if (current1->exponent == current2->exponent) {
                result.insertTerm(current1->coefficient + current2->coefficient, current1->exponent);
                current1 = current1->next;
                current2 = current2->next;
            } else if (current1->exponent > current2->exponent) {
                result.insertTerm(current1->coefficient, current1->exponent);
                current1 = current1->next;
            } else {
                result.insertTerm(current2->coefficient, current2->exponent);
                current2 = current2->next;
            }
        }

        // Append the remaining terms from the first polynomial
        while (current1) {
            result.insertTerm(current1->coefficient, current1->exponent);
            current1 = current1->next;
        }

        // Append the remaining terms from the second polynomial
        while (current2) {
            result.insertTerm(current2->coefficient, current2->exponent);
            current2 = current2->next;
        }

        return result;
    }

    // Function to display the polynomial
    void display() const {
        Node* current = head;

        while (current) {
            std::cout << current->coefficient << "x^" << current->exponent;
            current = current->next;

            if (current) {
                std::cout << " + ";
            }
        }

        std::cout << std::endl;
    }
};

int main() {
    Polynomial poly1, poly2, result;

    // Input for Polynomial 1
    int terms1;
    std::cout << "Enter the number of terms in Polynomial 1: ";
    std::cin >> terms1;

    for (int i = 0; i < terms1; ++i) {
        int coeff, exp;
        std::cout << "Enter coefficient and exponent for term " << i + 1 << ": ";
        std::cin >> coeff >> exp;
        poly1.insertTerm(coeff, exp);
    }

    // Input for Polynomial 2
    int terms2;
    std::cout << "Enter the number of terms in Polynomial 2: ";
    std::cin >> terms2;

    for (int i = 0; i < terms2; ++i) {
        int coeff, exp;
        std::cout << "Enter coefficient and exponent for term " << i + 1 << ": ";
        std::cin >> coeff >> exp;
        poly2.insertTerm(coeff, exp);
    }

    // Add the two polynomials
    result = poly1.addPolynomials(poly2);

    // Display the polynomials and their sum
    std::cout << "Polynomial 1: ";
    poly1.display();

    std::cout << "Polynomial 2: ";
    poly2.display();

    std::cout << "Sum of the polynomials: ";
    result.display();

    return 0;
}
