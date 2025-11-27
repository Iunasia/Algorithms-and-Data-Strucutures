#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> undoS;
    stack<string> redoS;
    string text = "";

    undoS.push(text);
    text += "Hello";
    undoS.push(text);
    text += " Ren";
    undoS.push(text);
    cout << "Current text: " << text << endl;
    if (!undoS.empty()) {
        redoS.push(text);
        undoS.pop();
        text = undoS.top();
    }
    cout << "After Undo: " << text << endl;
    redoS.push(text);
    undoS.pop();
    text = undoS.top();
    cout << "After Undo: " << text << endl;
    if (!redoS.empty()) {
        undoS.push(text);
        text = redoS.top();
        redoS.pop();
    }
    cout << "After Redo: " << text << endl;

    return 0;
}
