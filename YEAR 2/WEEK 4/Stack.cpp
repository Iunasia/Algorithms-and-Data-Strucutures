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


    int pop(){
        if (top == nullptr){
            cout << "Stack Underflow" << endl;
            return 1;
        }
        node *t = top;
        int backupdata = t->data;
        top = top->next;
        delete t;
        size--;
        return backupdata;

    }

    void display (){
        node* temp = top;
        while(temp){
            cout << temp-> data << " "<< endl;
            temp = temp->next;
        }

    }

    int peek(){
        if (top == nullptr){
            return 1;
        } else
        return top->data;
    }

    bool IsEmp(){
        if(top == nullptr) {return true;}
        else return false;
    }

    int search(int n){

        node* temp = top;
        int position = 1;               
       void search(int n) {
        node* temp = top;

        while (temp != nullptr) {
            if (temp->data == n) {
                cout << "Found" << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Not found" << endl;
        


    }
};

int main(){ 

    stack obj;

    obj.push(2);
    obj.push(4);
    obj.push(9);
    obj.push(0);
    obj.display();

    cout << "removed 0 and 9" << endl;
    obj.pop();
    obj.pop();
    obj.display();
    cout << "Top Data in stack is: " << obj.peek() << endl;
    //search function
    obj.search(4);
    obj.search(7);
    obj.search(99);


    return 0;
}


