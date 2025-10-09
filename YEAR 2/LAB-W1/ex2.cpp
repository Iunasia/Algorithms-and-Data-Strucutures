#include <iostream>

int main() {
    using namespace std;

    const int SIZE = 10;
    int numbers[SIZE];
    int evenCount = 0;

    cout << "Enter " << SIZE << " integers:\n";
    for (int i = 0; i < SIZE; ++i) {
        cin >> numbers[i];
        if (numbers[i] % 2 == 0) {
            evenCount++;
        }
    }

    cout << "\nNumbers in reverse order:\n";
    for (int i = SIZE - 1; i >= 0; --i) {
        cout << numbers[i] << " ";
    }
    cout << "\n";

    cout << "\nTotal even numbers: " << evenCount << "\n";

    return 0;
}
