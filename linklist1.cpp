#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = nullptr;

void addAtStart(int num){
    Node* newNode = new Node();
    newNode->data = num;
    newNode->next = head;
    head = newNode;
    cout<<"Record added at start.\n";
}

void addAtEnd(int num){
    Node* newNode = new Node();
    newNode->data = num;
    newNode->next = nullptr;

    if(head == nullptr){
        head = newNode;
    }
    else{
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
    cout<<"Record added at end.\n";
}

void addAtPos(int num, int pos){
    if(pos < 1){
        cout<<"Invalid position.\n";
        return;
    }
    Node* newNode = new Node();
    newNode->data = num;

    if(pos == 1){
        newNode->next = head;
        head = newNode;
        cout<<"Record added at position " << pos << ".\n";
        return;
    }
    Node* temp = head;
    for(int i = 1; temp != nullptr && i < pos - 1; i++)
        temp = temp->next;
    if(temp == nullptr){
        cout<<"Position out of range.\n";
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout<<"Record added at position " << pos << ".\n";
}
void delAtStart(){
    if(head == nullptr){
        cout<<"No records to delete.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    cout<<"Record deleted from start.\n";
}
void delAtEnd(){
    if (head == nullptr){
        cout<<"No records to delete.\n";
        return;
    }

    if(head->next == nullptr){
        delete head;
        head = nullptr;
    } 
    else{
        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }
    cout<<"Record deleted from end.\n";
}

void delAtPos(int pos){
    if (head == nullptr){
        cout<<"No records to delete.\n";
        return;
    }
    if(pos < 1){
        cout<<"Invalid position.\n";
        return;
    }
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        cout<<"Record deleted from position " << pos << ".\n";
        return;
    }

    Node* temp = head;
    for(int i = 1; temp != nullptr && i < pos - 1; i++)
        temp = temp->next;

    if(temp == nullptr || temp->next == nullptr){
        cout<<"Position out of range.\n";
        return;
    }
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
    cout<<"Record deleted from position " << pos << ".\n";
}
void findNum(int num){
    Node* temp = head;
    int pos = 1;

    while(temp != nullptr){
        if(temp->data == num){
            cout<<"Record found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout<<"Record not found.\n";
}
void showRecord(){
    if(head == nullptr){
        cout <<"No records to display.\n";
        return;
    }
    Node* temp = head;
    cout <<"Records: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void reverseRecord() {
    Node* prev = nullptr;
    Node* cur = head;
    Node* next = nullptr;

    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    cout << "Records reversed.\n";
}

void countRecord() {
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    cout << "Total records: " << count << "\n";
}
void clearList() {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
void showMenu() {
    cout << "\n Singly Linked List Menu \n";
    cout << "1. Add at Start\n";
    cout << "2. Add at End\n";
    cout << "3. Add at Position\n";
    cout << "4. Delete at Start\n";
    cout << "5. Delete at End\n";
    cout << "6. Delete at Position\n";
    cout << "7. Search Record\n";
    cout << "8. Show Records\n";
    cout << "9. Reverse Records\n";
    cout << "10. Count Records\n";
    cout << "0. Exit\n";
    cout << "Enter option: ";
}
int main() {
    int option, num, pos;

    do {
        showMenu();
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter number: ";
                cin >> num;
                addAtStart(num);
                break;

            case 2:
                cout << "Enter number: ";
                cin >> num;
                addAtEnd(num);
                break;

            case 3:
                cout << "Enter number: ";
                cin >> num;
                cout << "Enter position: ";
                cin >> pos;
                addAtPos(num, pos);
                break;

            case 4:
                delAtStart();
                break;

            case 5:
                delAtEnd();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos;
                delAtPos(pos);
                break;

            case 7:
                cout << "Enter number to search: ";
                cin >> num;
                findNum(num);
                break;

            case 8:
                showRecord();
                break;

            case 9:
                reverseRecord();
                break;

            case 10:
                countRecord();
                break;

            case 0:
                cout<<"Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid option, try again.\n";
        }
    } while (option != 0);

    clearList(); 
}
