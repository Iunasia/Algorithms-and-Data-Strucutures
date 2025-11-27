#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int id;
    string name;
    vector<Node*> children;

    Node(int i, string n) {
        id = i;
        name = n;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }
};

int main() {
    Node* rootNode = new Node(1, "Root");
    Tree myTree;
    myTree.root = rootNode;

    Node* child1 = new Node(2, "Child 1");
    Node* child2 = new Node(3, "Child 2");

    rootNode->children.push_back(child1);
    rootNode->children.push_back(child2);

    cout << "Root: " << myTree.root->name << endl;
    cout << "First child: " << myTree.root->children[0]->name << endl;
    cout << "Second child: " << myTree.root->children[1]->name << endl;

    return 0;
}
