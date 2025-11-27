#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
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

    Node* insert(Node* root, string name) {
        if (root == nullptr) {
            return new Node(name);
        }

        if (name < root->name)
            root->left = insert(root->left, name);
        else
            root->right = insert(root->right, name);

        return root;
    }

    void addStudent(string name) {
        root = insert(root, name);
    }

    Node* search(Node* root, string name) {
        if (root == nullptr || root->name == name)
            return root;

        if (name < root->name)
            return search(root->left, name);
        else
            return search(root->right, name);
    }

    void findStudent(string name) {
        Node* result = search(root, name);

        if (result == nullptr) {
            cout << "Student " << name << " not found!\n";
        } else {
            cout << "Student found: " << result->name << "\n";
        }
    }

    void inorder(Node* root) {
        if (root == nullptr) return;

        inorder(root->left);
        cout << root->name << endl;
        inorder(root->right);
    }

    void display() {
        inorder(root);
    }
};

int main() {
    BST students;

    students.addStudent("Ren");
    students.addStudent("Panha");
    students.addStudent("Cheang");
    students.addStudent("Sovan");
    students.addStudent("Lenz");

    cout << "Student list (in alphabetical order):\n";
    students.display();

    cout << "\nSearching:\n";
    students.findStudent("Lenz");
    students.findStudent("Ren");

    return 0;
}
