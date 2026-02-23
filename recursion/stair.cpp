#include<iostream>
using namespace std;


int steps(int n){

   if(n == 0) return 1;
    if(n < 0) return 0;
  int x = steps(n-1);
  int y = steps(n-2);

  int z = steps(n-3);

  return x + y+z;
}



int main (){

  int n ;

  cin>>n;

  cout << steps(n);

  return 0;
}