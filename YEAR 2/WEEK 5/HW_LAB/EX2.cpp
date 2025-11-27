#include <iostream>
using namespace std;

class Node {
public:
    int id;
    string name;
    Node* left;
    Node* right;

    Node(int i, string n) {
        id = i;
        name = n;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    Node* insert(Node* root, int id, string name) {
        if (root == nullptr)
            return new Node(id, name);
        if (id < root->id)
            root->left = insert(root->left, id, name);
        else
            root->right = insert(root->right, id, name);
        return root;
    }

    void addNode(int id, string name) {
        root = insert(root, id, name);
    }

    void inorder(Node* root) {
        if (root == nullptr) return;
        inorder(root->left);
        cout << "ID: " << root->id << " | Name: " << root->name << endl;
        inorder(root->right);
    }

    void preorder(Node* root) {
        if (root == nullptr) return;
        cout << "ID: " << root->id << " | Name: " << root->name << endl;
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root) {
        if (root == nullptr) return;
        postorder(root->left);
        postorder(root->right);
        cout << "ID: " << root->id << " | Name: " << root->name << endl;
    }

    void displayInorder() {
        inorder(root);
    }

    void displayPreorder() {
        preorder(root);
    }

    void displayPostorder() {
        postorder(root);
    }
};

int main() {
    BST tree;
    tree.addNode(10, "Root");
    tree.addNode(5, "Left");
    tree.addNode(15, "Right");
    tree.addNode(3, "Left.Left");
    tree.addNode(7, "Left.Right");
    tree.addNode(12, "Right.Left");
    tree.addNode(18, "Right.Right");

    cout << "In-order traversal:\n";
    tree.displayInorder();+
    cout << "\nPre-order traversal:\n";
    tree.displayPreorder();

    cout << "\nPost-order traversal:\n";
    tree.displayPostorder();

    return 0;
}
