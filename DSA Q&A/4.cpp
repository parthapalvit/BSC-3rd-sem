//write a c++ program to implement doubly linked list using templates .
// Include functions for insertion , deletion and search a number , reverse the lis

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
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to insert a new element at the end of the list
    void insert(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (!head) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Function to delete a specific element from the list
    void remove(T value) {
        Node<T>* current = head;

        while (current) {
            if (current->data == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }

                delete current;
                return;
            }
            current = current->next;
        }
    }

    // Function to search for an element in the list
    bool search(T value) const {
        Node<T>* current = head;

        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    // Function to reverse the doubly linked list
    void reverse() {
        Node<T>* temp = nullptr;
        Node<T>* current = head;

        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp) {
            head = temp->prev;
        }
    }

    // Function to display the doubly linked list
    void display() const {
        Node<T>* current = head;

        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }
};

int main() {
    // Example usage
    DoublyLinkedList<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    std::cout << "Original list: ";
    list.display();

    // Search for an element in the list
    int searchValue = 2;
    if (list.search(searchValue)) {
        std::cout << searchValue << " found in the list.\n";
    } else {
        std::cout << searchValue << " not found in the list.\n";
    }

    // Remove an element from the list
    int removeValue = 2;
    list.remove(removeValue);
    std::cout << "After removing " << removeValue << ": ";
    list.display();

    // Reverse the doubly linked list
    list.reverse();
    std::cout << "Reversed list: ";
    list.display();

    return 0;
}
