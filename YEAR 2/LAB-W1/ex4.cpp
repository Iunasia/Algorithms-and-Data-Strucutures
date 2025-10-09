#include <iostream>
using namespace std;
float computeA(int A){
    int result = 0;
      for( int i = 0; i < A; i++)
    {
        result += i;
    }
    ;
    return result;
}

float computeB(int A){
  return A*(A+1)*(2*A + 1)/ 6.0f;
}

float computeC(int A){ 
    float sum = 0.0;
    for (int i = 1; i <= A; i++) {
        sum += 1.0 / i;
    }
    return sum;
}


int main(){

    cout << computeA(10) <<endl;
    cout << computeB(7) <<endl;;
    cout << computeC(5) <<endl;;

return 0;
}
