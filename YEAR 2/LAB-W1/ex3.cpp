#include <iostream>
using namespace std;
int main(){

    int arr[]= {10, 20, 0,-5, 9,7}; 
    int size = sizeof(arr)/4;
    
    int min = arr[0];
    int max = arr[0];

    for (int i = 0; i < size; i++)
    {
        if ((arr[i]) < min)
        {
           min = arr[i];
        }
        
        if ((arr[i])>max)
        {
            max = arr[i];
        }
        
    }
    
    cout << "min is " << min << endl;
    cout << "max is " << max << endl;


    return 0;
}
