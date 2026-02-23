#include <iostream>
using namespace std;

int multi(int m ,int n){

  if(n==0){
    return 0;

  }

  int a = multi(m,n-1);

  return a+m;


}

int main(){


  cout << multi(3,5)<<endl;

  return 0;
}