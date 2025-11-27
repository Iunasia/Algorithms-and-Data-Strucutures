#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;

    node(int newdata){

        data = newdata;
        left = nullptr;
        right = nullptr;

    }

};

class tree {
    node *root;
    Tree(){ 
        root = nullptr;

    }

    node* insert (node, *root, int data){
        if(root == nullptr){
             new Node(data);
        } else if(data <root->data){
            root->left = insert(root->left, data);
        } else if (data > root->data){
            root->right = insert (root->right, data);
        }

        return root;
    }

    void inorder(node* root){
        
        if(root != nullptr){
            inorder(root->left);
            cout << root->data << " ";
            inorder (root->right);
        }
    }

    void add(int data){
        root = insert (root, data);
    }

    void preorder(node* root){
        if(root != nullptr){
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }

    }

    bool search(int data){
        if(root == nullptr){
            return false;
        } else if (root->data == data){
            return true;
        } else if (data < root->data){
            return search (root->left, data);
        } else {
            return search (root->right, data);

    }
};




int main() {

    tree t;
    t.add(5);
    t.add(3);
    t.add(7);


    return 0;
}
