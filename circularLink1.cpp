#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;

    Node(int val){
        data = val;
        prev =nullptr;
        next = nullptr;
    }
};
int main(){

    head = Node(10);

}
