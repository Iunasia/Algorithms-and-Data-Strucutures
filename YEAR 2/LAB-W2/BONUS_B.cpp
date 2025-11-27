#include <iostream>
#include <string>
using namespace std;

struct Node {
    int ID;
    string NAME;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

public:
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

    void deleteByID(int ID) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->ID == ID) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted student with ID " << ID << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->ID != ID)
            temp = temp->next;

        if (temp->next == nullptr) {
            cout << "ID not found.\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "Deleted student with ID " << ID << endl;
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
    list.insertAtEnd(2, "ren");
    list.insertAtEnd(3, "reach");

    cout << "Before deletion:\n";
    list.displayList();

    list.deleteByID(2);

    cout << "\nAfter deletion:\n";
    list.displayList();
}
