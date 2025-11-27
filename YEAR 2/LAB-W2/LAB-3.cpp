#include <iostream>
using namespace std;

//Curcular Singly Linked List Node with delete node

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
}

class ClinkedList {
    public:
    Node* head;
    circularLinkedList() {
        head = nullptr;

    }

    void  addEnd (int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // Point to itself to make it circular
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; 
        }
    }

    //for delete head node

    void deleteHead() {
        if (!head){
            return; // List is empty
        }
    }

    if (head->next == head) {
        delete head;
        head = nullptr; // List had one node
        return;
    }
        //find last node
        Node* temp = head;
     while (temp->next != head) {
         temp = temp->next;
     }
        Node* oldHead = head;
        temp->next = head->next;
        head = head->next;
        delete oldHead;
// search value
    bool search(int value) {
    if (!head) {
        return false; // List is empty
    }
    Node* temp = head;
    do {
        if (temp->data == value) {
            return true; // Value found
        }
        temp = temp->next;
    } while (temp != head);
    return false; // Value not found
}

    void print(){
    if (!head) {
        //EMPTY
        return;
    }
    Node* temp = head;
    do {   
         cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }

    //destructor
~CircularLinkedList() {
        if (!head) return;
        Node* temp = head->next;
        while (temp != head) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        delete head;
    }
};

//DLL with add begin and delete end

class DLLNode {
public:
    string URL;
    DLLNode* next;
    DLLNode* prev;

    DLLNode(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    };
}

class DLL { 
    public:
    DLLNode* head;
    DLLNode* tail;  

    void addbegin(int value) {
        DLLNode* newNode = new DLLNode(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    //delete end

    void deleteEnd() {
        if (!head) {
            return; //EMPTY
        }
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr; // List had one node
            return;
        }
        DLLNode* oldTail = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete oldTail;
    }
}

void print () {
    if (!head) {
            cout << "Empty DLL" << endl;
            return;
        }
        DNode* temp = head;
        cout << "DLL: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
}   

    ~DoublyLinkedList() {
        while (head) {
            DNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
}
