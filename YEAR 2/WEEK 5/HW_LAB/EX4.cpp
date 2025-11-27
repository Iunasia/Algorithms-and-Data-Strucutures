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
        if (root == nullptr) {
            return new Node(id, name);
        }

        if (id < root->id)
            root->left = insert(root->left, id, name);
        else
            root->right = insert(root->right, id, name);

        return root;
    }

    void addProduct(int id, string name) {
        root = insert(root, id, name);
    }

    // Search product by ID
    Node* search(Node* root, int id) {
        if (root ==nullptr || root->id == id)
            return root;   // found or empty

        if (id < root->id)
            return search(root->left, id);
        else
            return search(root->right, id);
    }

    void findProduct(int id) {
        Node* result = search(root, id);

        if (result == nullptr) {
            cout << "Product with ID " << id << " not found!\n";
        } else {
            cout << "Product found:\n";
            cout << "ID: " << result->id << "\n";
            cout << "Name: " << result->name << "\n";
        }
    }

    // Inorder traversal to display product list
    void inorder(Node* root) {
        if (root == nullptr) {
        return;
        }
        inorder(root->left);
        cout << "ID: " << root->id << " | Name: " << root->name << endl;
        inorder(root->right);
    }

    void display() {
        inorder(root);
    }
};

int main() {
    BST store;

    // Add products
    store.addProduct(10, "Keyboard");
    store.addProduct(52, "Mouse");
    store.addProduct(20, "Monitor");
    store.addProduct(15, "USB Cable");
    store.addProduct(30, "Laptop");

    cout << "Product list (in order):\n";
    store.display();

    cout << "\nSearch test:\n";
    store.findProduct(15);   // exists
    store.findProduct(21);   // does not exist

    return 0;
}