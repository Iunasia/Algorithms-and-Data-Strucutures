#include <iostream>
#include <queue>
using namespace std;

// Function to print the current queue
void print(queue<int> q) {
    cout << "Current queue: ";
    if (q.empty()) {
        cout << "empty";
    } else {
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
    }
    cout << endl;
}

int main() {
    queue<int> bank;

    // Enqueue customers
    bank.push(101);  // Customer ID 101
    cout << "Customer 101 entered the queue." << endl;
    print(bank);

    bank.push(102);
    cout << "Customer 102 entered the queue." << endl;
    print(bank);

    bank.push(103);
    cout << "Customer 103 entered the queue." << endl;
    print(bank);

    // Dequeue (serve) customers
    cout << "Serving customer: " << bank.front() << endl;
    bank.pop();
    print(bank);

    cout << "Serving customer: " << bank.front() << endl;
    bank.pop();
    print(bank);

    // Add another customer
    bank.push(104);
    cout << "Customer 104 entered the queue." << endl;
    print(bank);

    return 0;
}
