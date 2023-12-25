//write a c++ program to implement circular linked list using templates .
// include functions for insertion, deletion and search of a number , reverse the list.



#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class CircularLinkedList {
private:
    Node<T>* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Function to insert a new element at the end of the circular list
    void insert(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (!head) {
            head = newNode;
            head->next = head;  // Point to itself for circularity
        } else {
            Node<T>* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            tail->next = newNode;
            newNode->next = head;  // Make the new node point to the head for circularity
        }
    }

    // Function to delete a specific element from the circular list
    void remove(T value) {
        if (!head) {
            return;
        }

        Node<T>* current = head;
        Node<T>* prev = nullptr;

        do {
            if (current->data == value) {
                if (prev) {
                    prev->next = current->next;
                    if (current == head) {
                        head = current->next;
                    }
                } else {
                    // If the node to be deleted is the head, update head
                    if (current->next == head) {
                        head = nullptr;
                    } else {
                        // Update head and find the new tail
                        head = current->next;
                        Node<T>* tail = head;
                        while (tail->next != current) {
                            tail = tail->next;
                        }
                        tail->next = head;
                    }
                }

                delete current;
                return;
            }

            prev = current;
            current = current->next;

        } while (current != head);
    }

    // Function to search for an element in the circular list
    bool search(T value) const {
        if (!head) {
            return false;
        }

        Node<T>* current = head;

        do {
            if (current->data == value) {
                return true;
            }
            current = current->next;

        } while (current != head);

        return false;
    }

    // Function to reverse the circular linked list
    void reverse() {
        if (!head) {
            return;
        }

        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;

        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;

        } while (current != head);

        head = prev;
    }

    // Function to display the circular linked list
    void display() const {
        if (!head) {
            return;
        }

        Node<T>* current = head;

        do {
            std::cout << current->data << " ";
            current = current->next;

        } while (current != head);

        std::cout << std::endl;
    }
};

int main() {
    // Example usage
    CircularLinkedList<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    std::cout << "Original circular list: ";
    list.display();

    // Search for an element in the list
    int searchValue = 2;
    if (list.search(searchValue)) {
        std::cout << searchValue << " found in the circular list.\n";
    } else {
        std::cout << searchValue << " not found in the circular list.\n";
    }

    // Remove an element from the list
    int removeValue = 2;
    list.remove(removeValue);
    std::cout << "After removing " << removeValue << ": ";
    list.display();

    // Reverse the circular linked list
    list.reverse();
    std::cout << "Reversed circular list: ";
    list.display();

    return 0;
}
