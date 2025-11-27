#include <iostream>
using namespace std;

// === 1. CORRECTION: Node Class Definition ===
// The class name is 'dllNode', so the constructor must also be 'dllNode'.
// Also fixed the typo 'ddlNode' to 'dllNode*' in the class declaration.
class dllNode {
public:
    int data;
    dllNode* next;
    dllNode* prev;

    // Constructor name must match the class name (dllNode)
    dllNode(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

// === 2. Correction: DLL Class Definition ===
// Added semicolon after class definition
class DLL {
public:
    // Pointers must use the correct Node type: dllNode*
    dllNode* head;
    dllNode* tail;

    DLL() {
        head = nullptr;
        tail = nullptr;
    }

    void addToEnd(int value) {
        // Must use 'new' keyword to allocate memory for the new node
        dllNode* newNode = new dllNode(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            // 1. Link new node back to the old tail
            newNode->prev = tail; 
            
            // 2. Link old tail forward to the new node
            tail->next = newNode; 

            // 3. Update the list's tail pointer
            tail = newNode;
        }
    }


    void printForward() {
        dllNode* current = head;
        while (current != nullptr) {
            cout << current->data << " <-> "; // Using <-> for clarity
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    void printBackward() {
        dllNode* current = tail;
        while (current != nullptr) {
            cout << current->data << " <-> "; // Using <-> for clarity
            current = current->prev;
        }
        cout << "nullptr" << endl;
    }
}; // Semicolon is required here

// === 3. Main Function ===
int main() {
    // Note: The main function uses the corrected classes and methods.
    DLL myDLL;
    myDLL.addToEnd(10);
    myDLL.addToEnd(20);
    myDLL.addToEnd(30);

    cout << "Print Forward: ";
    myDLL.printForward();
    // Expected Output: 10 <-> 20 <-> 30 <-> nullptr

    cout << "Print Backward: ";
    myDLL.printBackward();
    // Expected Output: 30 <-> 20 <-> 10 <-> nullptr

    // NOTE ON MEMORY MANAGEMENT: 
    // In a real C++ program, you would need to implement a destructor 
    // or a dedicated 'deleteList' method to free all allocated memory 
    // (using 'delete' for each Node) to prevent memory leaks.

    return 0;
}