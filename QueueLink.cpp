#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

// Queue class
class myStack {
private:
    int currSize;
    Node* rear;
    Node* front;

public:
    myStack() {
        currSize = 0;
        front = rear= nullptr;
    }

    // Check if empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue
  int push(){
    Node* newRear = rear ->next;
    int newdata = rear -> data;

  }

    // Dequeue
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        
        Node* temp = rear;
        int removedData = temp->data;
        
        
        if (front == nullptr) rear = nullptr;
        delete temp;
        
        currSize--;
        return removedData;
    }

    // Get front element
    int peek() {
        if (isEmpty()) {
            cout << "stack is empty" << endl;
            return -1;
        }
        return rear->data;
    }

    // Get size
    int size() {
       return currSize;
    }
};

int main() {
    myStack s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(69);


    cout << "Popped " << s.pop() << "\n";
    cout << "Size: " << s.size() << endl;

    return 0;
}