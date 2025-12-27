#include <iostream>
using namespace std;

// ===========================================
// 1. NODE CLASS
// ===========================================
class Node {
public:
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// ===========================================
// 2. LINKED LIST CLASS (MANAGES HEAD & TAIL)
// ===========================================
class LinkedList {
private:
    Node* head;
    Node* tail;  
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }
    void insertAtHead(int d) {
        Node* temp = new Node(d);
        
        if (head == NULL) { 
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }
    
    void insertAtTail(int d) {
        Node* temp = new Node(d);
        
        if (tail == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    void insertAtPosition(int position, int d) {
        // Position validation
        if (position <= 0) {
            cout << "Invalid position! Position should be >= 1" << endl;
            return;
        }
        
        // Insert at head (position 1)
        if (position == 1) {
            insertAtHead(d);
            return;
        }
        
        Node* temp = head;
        int count = 1;
        
        // Traverse to position-1
        while (count < position - 1 && temp != NULL) {
            temp = temp->next;
            count++;
        }
        
        // Check if position is beyond list length
        if (temp == NULL) {
            cout << "Position " << position << " is out of bounds!" << endl;
            return;
        }
        
        // If inserting at the end
        if (temp->next == NULL) {
            insertAtTail(d);
            return;
        }
        
        // Insert in middle
        Node* nodeToInsert = new Node(d);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }
    
    // ===========================================
    // 4. DELETION OPERATIONS
    // ===========================================
    
    void deleteNode(int position) {
        // Check if list is empty
        if (head == NULL) {
            cout << "List is empty! Cannot delete." << endl;
            return;
        }
        
        // Position validation
        if (position <= 0) {
            cout << "Invalid position! Position should be >= 1" << endl;
            return;
        }
        
        // Delete first node
        if (position == 1) {
            Node* temp = head;
            head = head->next;
            
            // If list becomes empty, update tail
            if (head == NULL) {
                tail = NULL;
            }
            
            temp->next = NULL;
            delete temp;
            return;
        }
        
        // Delete from middle or end
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        
        // Traverse to position
        while (curr != NULL && count < position) {
            prev = curr;
            curr = curr->next;
            count++;
        }
        
        // Check if position is out of bounds
        if (curr == NULL) {
            cout << "Position " << position << " is out of bounds!" << endl;
            return;
        }
        
        // Update previous node's next pointer
        prev->next = curr->next;
        
        // If deleting last node, update tail
        if (curr->next == NULL) {
            tail = prev;
        }
        
        curr->next = NULL;
        delete curr;
    }
    
    // ===========================================
    // 5. UTILITY FUNCTIONS
    // ===========================================
    
    // Print the linked list
    void print() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    // Get head (for external operations if needed)
    Node* getHead() {
        return head;
    }
    
    // Get tail (for external operations if needed)
    Node* getTail() {
        return tail;
    }
    
    // Get length of list
    int getLength() {
        int length = 0;
        Node* temp = head;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        return length;
    }
    
    // Check if list is empty
    bool isEmpty() {
        return head == NULL;
    }
    
    // Search for a value
    bool search(int value) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    
    // Update value at position
    void update(int position, int newValue) {
        if (position <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        
        Node* temp = head;
        int count = 1;
        
        while (temp != NULL && count < position) {
            temp = temp->next;
            count++;
        }
        
        if (temp == NULL) {
            cout << "Position out of bounds!" << endl;
        } else {
            temp->data = newValue;
        }
    }
};

// ===========================================
// 6. MAIN FUNCTION - TESTING
// ===========================================
int main() {
    // Create linked list (no need to create head/tail in main)
    LinkedList list;
    
    cout << "=== LINKED LIST DEMO ===\n\n";
    
    // Test insertion
    cout << "1. INSERTION TESTS:\n";
    
    cout << "Inserting 10 at head: ";
    list.insertAtHead(10);
    list.print();
    
    cout << "Inserting 20 at tail: ";
    list.insertAtTail(20);
    list.print();
    
    cout << "Inserting 15 at position 2: ";
    list.insertAtPosition(2, 15);
    list.print();
    
    cout << "Inserting 5 at head: ";
    list.insertAtHead(5);
    list.print();
    
    cout << "Inserting 25 at tail: ";
    list.insertAtTail(25);
    list.print();
    
    cout << "\n2. LIST INFORMATION:\n";
    cout << "Length of list: " << list.getLength() << endl;
    cout << "Is list empty? " << (list.isEmpty() ? "Yes" : "No") << endl;
    
    cout << "\n3. SEARCH TESTS:\n";
    cout << "Search for 15: " << (list.search(15) ? "Found" : "Not Found") << endl;
    cout << "Search for 99: " << (list.search(99) ? "Found" : "Not Found") << endl;
    
    cout << "\n4. UPDATE TEST:\n";
    cout << "Updating position 3 to 30: ";
    list.update(3, 30);
    list.print();
    
    cout << "\n5. DELETION TESTS:\n";
    
    cout << "Original list: ";
    list.print();
    
    cout << "Deleting position 1 (head): ";
    list.deleteNode(1);
    list.print();
    
    cout << "Deleting position 3: ";
    list.deleteNode(3);
    list.print();
    
    cout << "Deleting position 4 (out of bounds): ";
    list.deleteNode(4);
    list.print();
    
    cout << "Deleting last node: ";
    list.deleteNode(list.getLength());
    list.print();
    
    // Test edge cases
    cout << "\n6. EDGE CASE TESTS:\n";
    
    LinkedList emptyList;
    cout << "Empty list: ";
    emptyList.print();
    
    cout << "Trying to delete from empty list: ";
    emptyList.deleteNode(1);
    
    cout << "Inserting into empty list: ";
    emptyList.insertAtHead(100);
    emptyList.print();
    
    return 0;
}