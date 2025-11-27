#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ofstream outFile("user_inputs.csv"); // create/open file
    int n;
    cout << "How many numbers do you want to write? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cout << "Enter number " << i + 1 << ": ";
        cin >> x;
        outFile << x << endl; // write input to file
    }

    outFile.close();
    return 0;
}
