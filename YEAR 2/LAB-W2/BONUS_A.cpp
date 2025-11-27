#include <iostream>
#include <string>
using namespace std;

struct Node {
    int ID;
    string NAME;
    Node* next;
};

class SinglyLinkedList {


public:
    Node* head;
    SinglyLinkedList() { head = nullptr; }

    void insertAtEnd(int ID, string NAME) {
        Node* newNode = new Node{ID, NAME, nullptr};
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Last node deleted.\n";
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
        cout << "Last node deleted.\n";
    }

    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "ID: " << temp->ID << ", Name: " << temp->NAME << endl;
            temp = temp->next;
        }
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtEnd(1, "roth");
    list.insertAtEnd(2, "len");
    list.insertAtEnd(3, "nea");

    cout << "Before deletion:\n";
    list.displayList();

    list.deleteAtEnd();

    cout << "\nAfter deletion:\n";
    list.displayList();
}
