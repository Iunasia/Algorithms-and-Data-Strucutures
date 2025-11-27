#include <iostream>
using namespace std;

// CLL and delete head node and search

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* head;
    CircularLinkedList() {
        head = nullptr;
    }

    void addEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void deleteHead() {
        if (!head) return;

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        Node* oldHead = head;
        temp->next = head->next;
        head = head->next;
        delete oldHead;
    }

    void print() {
        if (!head) {
            cout << "Empty CLL" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to start)" << endl;
    }
};

// DLL with add begin and delete end

class DLLNode {
public:
    int data;
    DLLNode* next;
    DLLNode* prev;

    DLLNode(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DLL {
public:
    DLLNode* head;
    DLLNode* tail;
    DLL() {
        head = nullptr;
        tail = nullptr;
    }

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

    void addEnd(int value) {
        DLLNode* newNode = new DLLNode(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print() {
        if (!head) {
            cout << "Empty DLL" << endl;
            return;
        }
        DLLNode* temp = head;
        cout << "DLL: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~DLL() {
        while (head) {
            DLLNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// playlist music use CLL

class PlayNode {
public:
    string URL;
    PlayNode* next;
    PlayNode(string url) : URL(url), next(nullptr) {}
};

class MP3Playlist {
public:
    PlayNode* head;
    MP3Playlist() : head(nullptr) {}

    void addSong(string url) {
        PlayNode* newNode = new PlayNode(url);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            PlayNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void displayPlaylist() {
        if (!head) {
            cout << "Playlist is EMPTY." << endl;
            return;
        }
        PlayNode* temp = head;
        do {
            cout << temp->URL << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to start)" << endl;
    }

    string next() {
        if (!head) {
            return "Playlist is EMPTY.";
        }
        head = head->next;
        return head->URL;
    }

    void printlist() {
        if (!head) {
            cout << "Playlist is EMPTY." << endl;
            return;
        }
        PlayNode* temp = head;
        do {
            cout << temp->URL << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to start)" << endl;
    }

    ~MP3Playlist() {
        if (!head) return;
        PlayNode* current = head->next;
        while (current != head) {
            PlayNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete head;
        head = nullptr;
    }
};

// Browser History using DLL

class DLLNodePage {
public:
    string URL;
    DLLNodePage* next;
    DLLNodePage* prev;

    DLLNodePage(string url) : URL(url), next(nullptr), prev(nullptr) {}
};

class DLLHistory {
public:
    DLLNodePage* head;
    DLLNodePage* tail;

    DLLHistory() {
        head = nullptr;
        tail = nullptr;
    }

    void addEnd(string URL) {
        DLLNodePage* newNode = new DLLNodePage(URL);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printForward() {
        DLLNodePage* current = head;
        while (current != nullptr) {
            cout << current->URL << " <-> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    void printBackward() {
        DLLNodePage* current = tail;
        while (current != nullptr) {
            cout << current->URL << " <-> ";
            current = current->prev;
        }
        cout << "nullptr" << endl;
    }

    ~DLLHistory() {
        DLLNodePage* current = head;
        while (current != nullptr) {
            DLLNodePage* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }
};

// Commands UNDO and REDO using DLL

class CommandNode {
public:
    string action;
    CommandNode* prev;
    CommandNode* next;
    CommandNode(string a) : action(a), prev(nullptr), next(nullptr) {}
};

class UndoRedoSystem {
private:
    CommandNode* current;

public:
    UndoRedoSystem() : current(nullptr) {}

    void execute(string action) {
        CommandNode* newCmd = new CommandNode(action);
        if (!current) {
            current = newCmd;
        } else {
            current->next = newCmd;
            newCmd->prev = current;
            current = newCmd;
        }
        cout << "Executed: " << action << endl;
    }

    string undo() {
        if (!current || !current->prev) {
            cout << "Nothing to undo!" << endl;
            return "";
        }
        string undone = current->action;
        current = current->prev;
        cout << "Undid: " << undone << endl;
        return undone;
    }

    string redo() {
        if (!current || !current->next) {
            cout << "Nothing to redo!" << endl;
            return "";
        }
        current = current->next;
        cout << "Redid: " << current->action << endl;
        return current->action;
    }

    string current_state() {
        return current ? current->action : "No actions";
    }

    ~UndoRedoSystem() {
        CommandNode* temp = current;
        if (!temp) return;
        while (temp->prev) {
            temp = temp->prev;
        }
        while (temp) {
            CommandNode* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

// test main function
int main() {
    CircularLinkedList cll;
    cll.addEnd(10);
    cll.addEnd(20);
    cll.addEnd(30);
    cout << "Circular Linked List after adding 10, 20, 30:" << endl;
    cll.print();
    cll.deleteHead();
    cout << "Circular Linked List after deleting head:" << endl;
    cll.print();

    DLL dll;
    dll.addbegin(5);
    dll.addbegin(15);
    dll.addEnd(25);
    cout << "Doubly Linked List after added 15 at beginning and 25 at end:" << endl;
    dll.print();

    MP3Playlist playlist;
    playlist.addSong("song1.mp3");
    playlist.addSong("song2.mp3");
    playlist.addSong("song3.mp3");
    cout << "MP3 Playlist:" << endl;
    playlist.printlist();
    cout << "Next song: " << playlist.next() << endl;

    DLLHistory history;
    history.addEnd("www.example1.com");
    history.addEnd("www.example2.com");
    history.addEnd("www.example3.com");
    cout << "Browser History Forward:" << endl;
    history.printForward();
    cout << "Browser History Backward:" << endl;
    history.printBackward();

    UndoRedoSystem urs;
    urs.execute("Type 'Hello'");
    urs.execute("Type 'World'");
    urs.undo();
    urs.redo();
    cout << "Current action: " << urs.current_state() << endl;

    return 0;
}
