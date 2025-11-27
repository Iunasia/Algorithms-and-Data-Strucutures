#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int value){
        data = value;
        next = nullptr;
    }

};

class stack {
    public:
    node* top;
    int size;
    stack(){
        top = nullptr;
        size = 0;
    }

    void push (int value){
        node* newNode = new node(value);
        if (!top){
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
        size++;
    }


    void pop(){
        if (top == nullptr){
            cout << "Stack Underflow" << endl;
            return;
        }
        node *t = top;
        int backupdata = t->data;=
        top = top->next;
        delete t;
        size--;
        return backupdata;

    }

    void display (){
        node* temp = top;
        while(temp){
            cout << temp-> data << " ";
            temp = temp->next;
        }

    }
};

int main(){

    stack obj;

    obj.push(2);
    obj.push(4);
    obj.push(9);
    obj.push(0);

    obj.display();
    return 0;
}


