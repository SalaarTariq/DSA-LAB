#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class LinkedListBinaryTree {
public:
    Node* root;

    LinkedListBinaryTree() {
        root = NULL;
    }

    Node* createNode(int value) {
        Node* n = new Node();
        n->data = value;
        n->left = n->right = NULL;
        return n;
    }

    Node* insert(Node* root, int value) {
        if (root == NULL) {
            cout << "Inserted: " << value << endl;
            return createNode(value);
        }
        if (root->left == NULL)
            root->left = insert(root->left, value);
        else
            root->right = insert(root->right, value);

        return root;
    }

    void preorder(Node* root) {
        if (root == NULL) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void postorder(Node* root) {
        if (root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};

int main() {
    LinkedListBinaryTree t;

    cout << "\n=== TASK 2: LINKED LIST BINARY TREE ===\n";

    t.root = t.insert(t.root, 10);
    t.root = t.insert(t.root, 20);
    t.root = t.insert(t.root, 30);
    t.root = t.insert(t.root, 40);

    cout << "\nPreorder: ";
    t.preorder(t.root);

    cout << "\nInorder: ";
    t.inorder(t.root);

    cout << "\nPostorder: ";
    t.postorder(t.root);

    return 0;
}   