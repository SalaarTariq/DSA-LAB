#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int data){
        this -> data =data;
        this -> next =NULL;
    }
};

void InsertAtHead(Node* &head,int d){
Node* temp=new Node(d);
temp ->next=head;
head=temp;
};

void InsertAtTail(Node* &tail,int d){
Node* temp=new Node(d);
tail ->next=temp;
tail =temp;
};

void InsertAtPosition(Node* &tail,Node* &head,int position,int d){
   if(position==1){
    InsertAtHead(head,d);
    return;
   }  
    Node* temp=head;
    int ctr =1;
while(ctr <position){
    temp=temp->next;
    ctr++;
}
if(temp -> next=NULL){
    InsertAtTail(tail,d);
    return;
}
    Node* nodeToInsert = new Node(d);

    nodeToInsert ->next = temp->next;
    temp->next=nodeToInsert; 

};

void DeleteNode(int position, Node* &head){
    if(position == 1){
        Node* temp=head;
        head =head->next;
        temp ->next=NULL;
        delete temp;
    }
    else{
        Node* curr =head;
        Node* prev =NULL;

        int ctr =1;
        while(ctr<position){
            prev=curr;
            curr=curr->next;
            ctr++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp = head;
    while(temp !=NULL){
        cout<<temp ->data<<" ";
        temp = temp ->next;
    }
    cout<<endl;
};



int main(){

    Node* node1 =new Node(10);
    Node* head=node1;
    Node* tail=node1;

print(head);
    InsertAtHead(head,12);
print(head);
    InsertAtTail(tail,15);
print(head);
    InsertAtPosition(tail,head,4,22);
print(head);
    DeleteNode(4,head);
print(head);
}