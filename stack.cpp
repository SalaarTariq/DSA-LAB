#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
private:
    Node* top;

public:
    Stack(){
        top = NULL;
    }

    void push(int d){
        Node* temp = new Node(d);
        temp->next = top;  // New node points to current top
        top = temp;        // Update top to new node
        cout << d << " pushed to stack\n";
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;   // Store current top
        top = top->next;    // Move top to next node
        cout << temp->data << " popped from stack\n";
        delete temp;        // Delete old top
    }

    int peek(){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty(){
        return top == NULL;
    }

    void display(){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Stack s;
    int choice, value;
    
    do{
        cout << "\nStack Operations:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << "Top element: " << s.peek() << endl;
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 5);
    
    return 0;
}