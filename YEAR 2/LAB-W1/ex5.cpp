#include <iostream>
using namespace std;

int main(){
    
  int arr[3];
  cout << "Enter 3 numbers:" << endl;

  for (int i = 0 ; i < 3 ; i ++){
    cin >> arr[i];
  }

  float avg = (arr[0] + arr[1] + arr[2]) / 3.0;

  cout << "Average of 3 numbers =" << avg << endl;

  cout << "Display all data in array:";

  for (int i = 0 ; i < 3 ; i ++){
    cout <<" "<< arr[i] ;
  }

  int max = arr[0];

  for (int i = 0 ; i < 3 ; i ++){
    if (arr[i] >= max) max = arr[i];
  }

  cout << "\nThe maximum number is:" << max << endl;

  cout << "Array element at position 3:" << arr[2] << endl;

  cout << "Reverse data from an array:";
  for (int i = 2 ; i >= 0 ; i--){
    cout << " " << arr[i];
  }

  return 0;
}


/*
ANALYSIS:
a. it is used O(1) time complexity
b. it is used O(N) time complexity
c. it is used O(1) time complexity
d. it is used O(1) time complexity
e. it is used O(N) time complexity
*/ 
