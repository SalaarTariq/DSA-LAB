#include <iostream>
#include <queue>
using namespace std;

// ======================= Node Structure =======================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// ======================= MAX HEAP =======================
class MaxHeap {
private:
    Node* root;

    // Swap data of two nodes
    void swapData(Node* a, Node* b) {
        int t = a->data;
        a->data = b->data;
        b->data = t;
    }

    // Find parent of a given node using level order
    Node* findParent(Node* child) {
        if (child == root) return nullptr;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->left == child || temp->right == child)
                return temp;

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        return nullptr;
    }

    // Heapify up (bubble up)
    void heapifyUp(Node* node) {
        if (!node || node == root) return;

        Node* parent = findParent(node);

        if (parent && parent->data < node->data) {
            swapData(parent, node);
            heapifyUp(parent);
        }
    }

    // Heapify down (bubble down)
    void heapifyDown(Node* node) {
        if (!node) return;

        Node* largest = node;

        if (node->left && node->left->data > largest->data)
            largest = node->left;

        if (node->right && node->right->data > largest->data)
            largest = node->right;

        if (largest != node) {
            swapData(largest, node);
            heapifyDown(largest);
        }
    }

public:

    MaxHeap() {
        root = nullptr;
    }

    // ======================= INSERT =======================
    void insert(int val) {
        Node* newNode = new Node(val);

        if (!root) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (!temp->left) {
                temp->left = newNode;
                break;
            }
            else if (!temp->right) {
                temp->right = newNode;
                break;
            }
            else {
                q.push(temp->left);
                q.push(temp->right);
            }
        }

        heapifyUp(newNode);
    }

    // ======================= DELETE ROOT =======================
    int deleteRoot() {
        if (!root) return -1;

        int removed = root->data;

        // If single node
        if (!root->left && !root->right) {
            delete root;
            root = nullptr;
            return removed;
        }

        queue<Node*> q;
        q.push(root);

        Node* last = nullptr;
        Node* parentOfLast = nullptr;

        // Find last node
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->left) {
                parentOfLast = temp;
                q.push(temp->left);
            }

            if (temp->right) {
                parentOfLast = temp;
                q.push(temp->right);
            }

            last = temp;
        }

        // Replace root value with last node value
        root->data = last->data;

        // Delete last node
        if (parentOfLast->right == last)
            parentOfLast->right = nullptr;
        else
            parentOfLast->left = nullptr;

        delete last;

        heapifyDown(root);
        return removed;
    }

    // ======================= DISPLAY HEAP =======================
    void display() {
        if (!root) {
            cout << "Heap is EMPTY\n";
            return;
        }

        queue<Node*> q;
        q.push(root);

        cout << "Heap (Level Order): ";
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }
};

// ======================= MAIN =======================
int main() {
    MaxHeap heap;

    heap.insert(20);
    heap.insert(15);
    heap.insert(30);
    heap.insert(5);
    heap.insert(10);
    heap.insert(40);

    heap.display();

    cout << "Deleted root: " << heap.deleteRoot() << endl;
    heap.display();

    return 0;
}
