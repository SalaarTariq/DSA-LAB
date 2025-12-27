#include <iostream>
using namespace std;

// Structure for a node
struct Node {
    int data;
    Node* next;
};

// Class for Linked List
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } 
        else{
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Function to delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        // If head node holds the value
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted successfully!" << endl;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Value not found!" << endl;
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Node deleted successfully!" << endl;
    }

    // Function to display all nodes
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        int i =0;
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
            i++;
        }
        cout << "NULL" << endl;
        cout<<"The total nodes are "<<i;
    }


};

// Main function
int main() {
    LinkedList list;
    int choice, value;

    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete Node\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;

            case 4:
                list.display();
                break;

            case 5:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}