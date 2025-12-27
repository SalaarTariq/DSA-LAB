
#include <iostream>
using namespace std;

// Node class as requested
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Global front and rear pointers
Node* front = nullptr;
Node* rear  = nullptr;

// Check if queue is empty
bool isempty() {
    return (front == nullptr && rear == nullptr);
}

// Enqueue: insert at rear
void enqueue(int data) {
    Node* ptr = new Node(data);
    if (front == nullptr) {
        // empty queue
        front = ptr;
        rear  = ptr;
    } else {
        rear->next = ptr;
        rear = ptr;
    }
}

// Dequeue: remove from front
void dequeue() {
    if (isempty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    if (front == rear) {
        // single element
        delete front;
        front = nullptr;
        rear  = nullptr;
    } else {
        Node* ptr = front;
        front = front->next;
        delete ptr;
    }
}

// Show front element
void showfront() {
    if (isempty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << front->data << endl;
    }
}

// Display all elements
void display() {
    if (isempty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    Node* ptr = front;
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    // Example usage (you can remove this if you want an empty main)
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();     // 10 20 30
    showfront();   // 10

    dequeue();
    display();     // 20 30
    showfront();   // 20

    dequeue();
    dequeue();
    dequeue();     // Queue is empty

    return 0;
}
