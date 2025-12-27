#include <iostream>
using namespace std;

class ArrayQueue{
private:
    int front, rear, size;
    int *arr;
public:
    ArrayQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;    
    }
    bool isFull(){ 
        return rear == size - 1;
    }
    bool isEmpty(){
        return front == -1 || front > rear;
    }
    void enqueue(int val){
        if(isFull()){
            cout<<"Queue Overflow\n";
            return;
        }
        if(front == -1){
            front = 0;
        }
        arr[++rear] = val;
    }
    void printReverse(){
        if(isEmpty()){
            cout<<"Queue Empty\n";
            return;
        }
        cout<<"Reverse Queue: ";
        for(int i = rear; i >= front; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Node {
public:
    int data;
    Node* next;
    Node(int v) { data = v; next = NULL; }
};

class LinkedListQueue{
private:
    Node *front, *rear;
public:
    LinkedListQueue(){
        front = rear = NULL;
    }
    bool isEmpty(){ 
        return front == NULL; 
    }
    void enqueue(int val){
        Node* temp = new Node(val);
        if(rear == NULL){
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void printReverseHelper(Node* node){
        if(node == NULL) return;
        printReverseHelper(node->next);
        cout << node->data << " ";
    }
    void printReverse(){
        if(isEmpty()){
            cout<<"Queue Empty\n";
            return;
        }
        cout<<"Reverse Queue: ";
        printReverseHelper(front);
        cout<<endl;
    }
};

int main() {
    int choice;
    cout<<"1. Queue Using Array\n";
    cout<<"2. Queue Using Linked List\n";
    cout<<"Enter choice: ";
    cin>>choice;
    
    int val, operation;
    
    if (choice == 1){
        int n;
        cout<<"Enter queue capacity: ";
        cin >> n;
        ArrayQueue q(n);
        
        do{
            cout<<"\nChoose operation:\n";
            cout<<"1. Enqueue\n";
            cout<<"2. Print Reverse\n";
            cout<<"3. Exit\n";
            cout<<"Enter option: ";
            cin>>operation;
            
            switch(operation) {
                case 1:
                    cout<<"Enter value: ";
                    cin>>val;
                    q.enqueue(val);
                    break;
                case 2:
                    q.printReverse();
                    break;
                case 3:
                    cout<<"Exiting\n";
                    break;
                default:
                    cout << "Invalid operation\n";
            }
        } while(operation != 3);
    }
    else if (choice == 2){
        LinkedListQueue q;
        
        do{
            cout << "\nChoose operation:\n";
            cout << "1. Enqueue\n";
            cout << "2. Print Reverse\n";
            cout << "3. Exit\n";
            cout << "Enter option: ";
            cin >> operation;
            
            switch(operation) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    q.enqueue(val);
                    break;
                case 2:
                    q.printReverse();
                    break;
                case 3:
                    cout<<"Exiting...\n";
                    break;
                default:
                    cout<<"Invalid operation\n";
            }
        }while(operation != 3);
    }
    else {
        cout<<"Invalid Choice\n";
    }
}