#include <iostream>
#include <fstream>

using namespace std;

int main (){
    fstream thefile;

    thefile.open("data.csv", ios::out);
    thefile << "Hello, World!" << endl;
    for (int i = 0; i <= 100; i++) {
        thefile << i <<", the ren, 20 \n";
    }
    thefile.close();
}