#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node {
    int ID;
    string NAME;
    string MAJOR;
    Node* next;

    Node(int id, string name, string major) {
        ID = id;
        NAME = name;
        MAJOR = major;
        next = nullptr;
    }
};

// Singly Linked List class
class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int ID, string NAME, string MAJOR) {
        Node* newNode = new Node(ID, NAME, MAJOR);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int ID, string NAME, string MAJOR) {
        Node* newNode = new Node(ID, NAME, MAJOR);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    // Delete a node by ID
    void deleteByID(int ID) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->ID == ID) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Student with ID " << ID << " deleted.\n";
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->ID != ID) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Student with ID " << ID << " not found.\n";
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Student with ID " << ID << " deleted.\n";
    }

    // Display the list
    void displayList() {
        if (head == nullptr) {
            cout << "List is EMPTY.\n";
            return;
        }

        Node* temp = head;
        cout << "\n=== Student List ===\n";
        while (temp != nullptr) {
            cout << "ID: " << temp->ID << ", Name: " << temp->NAME 
                 << ", Major: " << temp->MAJOR << endl;
            temp = temp->next;
        }
        cout << "====================\n";
    }
};

// Main function
int main() {
    SinglyLinkedList myStudent;

    myStudent.insertAtEnd(1, "Vibol", "Computer Science");
    myStudent.insertAtEnd(2, "Ren", "Telecom and Networking");
    myStudent.insertAtEnd(3, "Oudom", "Software Engineering");

    myStudent.displayList();

    myStudent.insertAtBeginning(0, "lenz", "Cybersecurity");
    myStudent.displayList();

    myStudent.deleteByID(2);
    myStudent.displayList();

    return 0;
}
