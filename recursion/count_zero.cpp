#include <iostream>
using namespace std;

int count(int n){

  // base case
  if(n==0){
    return 0;
  }

  // recursive call

  int a = count(n/10);

  //small calcuation 

  int x = (n%10);

  if(x==0){
    return a+1;
  }else{
    return a;
  }


}


int main(){

  cout << count(102000)<<endl;


}