#include <iostream>
using namespace std;


int fibo(int n){

  if(n ==0 ){
    return 0;
  }

  if( n==1) {
    return 1;

  }

  int s1 = fibo(n-1);

  int s2 = fibo( n-2);

  return  s1 + s2;


}


int main(){
  int arr[] = {2,3,5,65,6};


  cout << fibo(6) <<endl;
  return 0 ;
}