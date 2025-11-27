#include <iostream>
#include<stack>
using namespace std;

// part 1
//stack reverse

string reverse(string hello){
    stack<char> hellostack;
    for(char c:hello){
        hellostack.push(c);
    }

    string reversed="";
    while(!hellostack.empty()){
        reversed += hellostack.top();
        hellostack.pop();
    }
    
    return reversed;
}


int main(){

    string hello = "hello";
    cout << reverse(hello);

    return 0;
}