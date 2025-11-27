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

    void clearList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        cout << "All data cleared.\n";
    }

    void displayList() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << "ID: " << temp->ID << ", Name: " << temp->NAME << endl;
            temp = temp->next;
        }
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtEnd(1, "ken");
    list.insertAtEnd(2, "jenny");
    list.insertAtEnd(3, "Ren");

    cout << "Before clearing:\n";
    list.displayList();

    list.clearList();

    cout << "\nAfter clearing:\n";
    list.displayList();
}
