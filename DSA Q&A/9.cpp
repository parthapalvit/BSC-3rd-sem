//write a c++ program to Create and perform different operations on Double-ended Queues using Linked List implementation.

#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Deque {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}

    // Function to check if the deque is empty
    bool isEmpty() const {
        return front == nullptr && rear == nullptr;
    }

    // Function to insert an element at the front of the deque
    void insertFront(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        std::cout << value << " inserted at the front of the deque.\n";
    }

    // Function to insert an element at the rear of the deque
    void insertRear(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }

        std::cout << value << " inserted at the rear of the deque.\n";
    }

    // Function to delete an element from the front of the deque
    void deleteFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Cannot delete from the front.\n";
            return;
        }

        Node<T>* temp = front;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }

        std::cout << temp->data << " deleted from the front of the deque.\n";
        delete temp;
    }

    // Function to delete an element from the rear of the deque
    void deleteRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Cannot delete from the rear.\n";
            return;
        }

        Node<T>* temp = rear;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }

        std::cout << temp->data << " deleted from the rear of the deque.\n";
        delete temp;
    }

    // Function to display the elements of the deque
    void display() const {
        if (isEmpty()) {
            std::cout << "Deque is empty.\n";
            return;
        }

        std::cout << "Deque elements: ";
        Node<T>* current = front;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Example usage
    Deque<int> deque;

    deque.insertFront(10);
    deque.insertRear(20);
    deque.insertFront(5);

    deque.display();

    deque.deleteFront();
    deque.display();

    deque.insertRear(15);
    deque.deleteRear();
    deque.display();

    return 0;
}
