#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
public:
    Node* root;

    BST() { root = NULL; }

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

        if (value < root->data)
            root->left = insert(root->left, value);
        else
            root->right = insert(root->right, value);

        return root;
    }

    bool search(Node* root, int value) {
        if (root == NULL) return false;
        if (root->data == value) return true;

        if (value < root->data)
            return search(root->left, value);
        return search(root->right, value);
    }

    int minValue(Node* root) {
        while (root->left != NULL)
            root = root->left;
        return root->data;
    }

    int maxValue(Node* root) {
        while (root->right != NULL)
            root = root->right;
        return root->data;
    }

    int countNodes(Node* root) {
        if (root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    void levelOrder(Node* root) {
        if (root == NULL) return;

        queue<Node*> q;
        q.push(root);

        cout << "Level Order: ";

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        cout << endl;
    }
};

int main() {
    BST tree;

    cout << "\n=== TASK 3: BINARY SEARCH TREE (BST) ===\n";

    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 70);
    tree.root = tree.insert(tree.root, 60);
    tree.root = tree.insert(tree.root, 80);

    int val = 40;
    if (tree.search(tree.root, val))
        cout << "Search: " << val << " FOUND\n";
    else
        cout << "Search: " << val << " NOT FOUND\n";

    cout << "Minimum Value: " << tree.minValue(tree.root) << endl;
    cout << "Maximum Value: " << tree.maxValue(tree.root) << endl;

    cout << "Total Nodes: " << tree.countNodes(tree.root) << endl;
    tree.levelOrder(tree.root);

    return 0;
}    