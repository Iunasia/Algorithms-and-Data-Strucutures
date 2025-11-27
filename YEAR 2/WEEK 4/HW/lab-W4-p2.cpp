#include <iostream>
#include <queue>
using namespace std;

//part 2

void printQ(queue<int> q){
    cout << "In queue: ";
    if(q.empty()){
        return;
    } else {
        while(!q.empty()){
            cout << q.front() << " ";
            q.pop();
        }
    }
    cout << endl;
}   

int main(){
    
    queue<int> customer;

    customer.push(1);
    cout << "enqueue 1" << endl;
    printQ(customer);

    customer.push(2);
    cout << "enqueue 2" << endl;
    printQ(customer);
    
    customer.push(3);
    cout << "enqueue 3" << endl;
    printQ(customer);

    customer.push(4);
    cout << "enqueue 4" << endl;
    printQ(customer);

    //deq
    cout << "dequeued: " << customer.front() << endl;
    customer.pop();


    return 0;
}

