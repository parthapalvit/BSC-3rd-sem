//write a c++ program to Perform Queues operations using Circular Array implementation. Use Templates.

#include <iostream>

const int MAX_SIZE = 5;  // Maximum size of the circular queue

template <typename T>
class CircularQueue {
private:
    T queueArray[MAX_SIZE];
    int front;
    int rear;

public:
    CircularQueue() : front(-1), rear(-1) {}

    // Function to check if the circular queue is empty
    bool isEmpty() const {
        return front == -1 && rear == -1;
    }

    // Function to check if the circular queue is full
    bool isFull() const {
        return (rear + 1) % MAX_SIZE == front;
    }

    // Function to enqueue (insert) an element into the circular queue
    void enqueue(T value) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        queueArray[rear] = value;
        std::cout << value << " enqueued into the queue.\n";
    }

    // Function to dequeue (remove) an element from the circular queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        std::cout << queueArray[front] << " dequeued from the queue.\n";

        if (front == rear) {
            // Reset front and rear when the last element is dequeued
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    // Function to display the elements of the circular queue
    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }

        std::cout << "Queue elements: ";
        int i = front;
        do {
            std::cout << queueArray[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        std::cout << std::endl;
    }
};

int main() {
    // Example usage
    CircularQueue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);  // This will cause the circular wrap-around

    queue.display();

    queue.dequeue();
    queue.display();

    queue.enqueue(60);
    queue.enqueue(70);  // Trying to enqueue into a full queue
    queue.display();

    return 0;
}
