#include <iostream>
#include <stack>
using namespace std;

bool isequal(string expr) {
    stack<char> s;
    for (char c : expr) {
        // Push left parentheses
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } 
        // Check right parentheses
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) return false;

            char top = s.top();
            s.pop();

            // Check matching pairs
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return s.empty();
}
int main() {
    string expr1 = "(A+B)*(C-D)";
    string expr2 = "(A+B)*(C-D";

    cout << expr1 << " -> " << (isequal(expr1) ? "equal" : "Unequal") << endl;
    cout << expr2 << " -> " << (isequal(expr2) ? "equal" : "Unequal") << endl;

    return 0;
}
