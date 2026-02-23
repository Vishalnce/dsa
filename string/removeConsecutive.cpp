#include <iostream>
using namespace std;


void print(char a[],int n){


  // int j= a[0];

  int j =0;

  for(int i =1;i<n;i++){

    if(a[j] != a[i]){
      j++;
      a[j]= a[i];
    }
    a[j+1] = '\0';


  }



}





int main (){


  char a[20]= "aaabbccdddeee";
  


  print(a,15);

  cout<<a;





  return 0; 
}