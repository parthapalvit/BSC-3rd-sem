//write a c++ program to implement linked using template. 
//Include function for deletion, insertion,and search of number , reverse the list and concatenate two linked lists. ( include a function and also overload operator +) 


#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert a new element at the end of the list
    void insert(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (!head) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to delete a specific element from the list
    void remove(T value) {
        Node<T>* current = head;
        Node<T>* prev = nullptr;

        while (current && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (current) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
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

    // Function to reverse the linked list
    void reverse() {
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    // Function to concatenate two linked lists
    LinkedList<T> concatenate(const LinkedList<T>& other) const {
        LinkedList<T> result = *this;  // Copy the current list

        Node<T>* current = other.head;
        while (current) {
            result.insert(current->data);
            current = current->next;
        }

        return result;
    }

    // Overloading the + operator for concatenation
    LinkedList<T> operator+(const LinkedList<T>& other) const {
        return concatenate(other);
    }

    // Function to display the linked list
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
    LinkedList<int> list1;
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);

    LinkedList<int> list2;
    list2.insert(4);
    list2.insert(5);

    std::cout << "Original list 1: ";
    list1.display();

    std::cout << "Original list 2: ";
    list2.display();

    // Concatenate lists using the + operator
    LinkedList<int> concatenatedList = list1 + list2;
    std::cout << "Concatenated list: ";
    concatenatedList.display();

    // Reverse the concatenated list
    concatenatedList.reverse();
    std::cout << "Reversed list: ";
    concatenatedList.display();

    // Search for an element in the list
    int searchValue = 3;
    if (concatenatedList.search(searchValue)) {
        std::cout << searchValue << " found in the list.\n";
    } else {
        std::cout << searchValue << " not found in the list.\n";
    }

    // Remove an element from the list
    int removeValue = 2;
    concatenatedList.remove(removeValue);
    std::cout << "After removing " << removeValue << ": ";
    concatenatedList.display();

    return 0;
}
