#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }

};


class SLL {
public:
    Node* head;
    Node* tail;



    SLL() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    
    void print(){
        Node* current;
        current = head;
        while(current != nullptr){ 
            cout << current->data << " ";
            current = current->next;    
        }
        cout <<" nullptr"<< endl;
    }
};

int main(){
    SLL newList;
    newList.insertAtEnd(10);
    newList.insertAtEnd(20);
    newList.insertAtEnd(30);   
    new
    newList.print();
    return 0;
}
