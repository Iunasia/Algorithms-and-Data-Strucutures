#include <iostream>
#include <queue>
using namespace std;

struct Job {
    int id;
    int pages;
};

void printQueue(queue<Job> q) {
    cout << "Queue: ";
    if (q.empty()) cout << "empty";
    while (!q.empty()) {
        cout << "[ID:" << q.front().id << ", Pages:" << q.front().pages << "] ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<Job> printerQueue;

    // Enqueue jobs
    printerQueue.push({101, 10});
    printerQueue.push({102, 5});
    printerQueue.push({103, 12});

    printQueue(printerQueue);

    // Print jobs (dequeue)
    while (!printerQueue.empty()) {
        Job current = printerQueue.front();
        cout << "Printing Job ID " << current.id << " (" << current.pages << " pages)" << endl;
        printerQueue.pop();
        printQueue(printerQueue);
    }

    return 0;
}
