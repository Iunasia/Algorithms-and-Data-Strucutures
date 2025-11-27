#include <iostream>
using namespace std;

struct Patient {
    string name;
    int priority;
    Patient* next;
};

class ERQueue {
private:
    Patient* head = nullptr;

public:
    void enqueue(string name, int priority) {
        Patient* newPatient = new Patient{name, priority, nullptr};

        if (!head || priority > head->priority) { // insert at front
            newPatient->next = head;
            head = newPatient;
        } else {
            Patient* t = head;
            while (t->next && t->next->priority >= priority) {
                t = t->next;
            }
            newPatient->next = t->next;
            t->next = newPatient;
        }
        printQueue();
    }

    void dequeue() {
        if (!head) {
            cout << "No patients in queue!" << endl;
            return;
        }
        cout << "current patient: " << head->name << endl;
        Patient* t = head;
        head = head->next;
        delete t;
        printQueue();
    }

    void printQueue() {
        cout << "ER Queue: ";
        if (!head) {
            cout << "empty";
        }
        Patient* t = head;
        while (t) {
            cout << "[" << t->name << ", P:" << t->priority << "] ";
            t = t->next;
        }
        cout << endl;
    }
};

int main() {
    ERQueue er;

    er.enqueue("Alice", 2);
    er.enqueue("Bob", 5);
    er.enqueue("Charlie", 3);

    er.dequeue();
    er.dequeue();
    er.enqueue("Diana", 4);
    er.dequeue();
    er.dequeue();

    return 0;
}
