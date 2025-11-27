#include<iostream>
using namespace std;

class stack {
private:
    int top;
    int maxSize;
    int* arr;


public:
    stack(int size) {
        maxSize = size;
        arr = new int[maxSize];
        top = -1;
    }

    ~stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top >= maxSize - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top < 0;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is EMPTY." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int peek(stack& s) {
    if (s.isEmpty()) {
        cout << "Stack is EMPTY." << endl;
        return -1;
    }
    int topElement = s.pop();
    s.push(topElement);
    return topElement;
}

int main() {
    stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top element is: " << peek(s) << endl;

    cout << "Popped element: " << s.pop() << endl;
    s.display();

    return 0;
}


