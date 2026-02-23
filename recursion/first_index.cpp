#include <iostream>
using namespace std;


// arrr from backeward
int sol2(int a[] , int size,int x){

  // base case 
  if(size==0){
    return -1;
  }

  // recursion
  int ans = sol2(a+1,size-1,x);

  
// my calculation - AFTER recursion
   if(ans == -1){
    
    if(a[0]==x){ 
        return 0; 
    }
    return -1;
  }else{
    return ans + 1;
  }

  // my calcuation


}


// arr from forward
int sol1(int a[],int size ,int x ){

  // base case 
  if(size==0){
    return -1;
  }

  // small calcualtion
  if(a[0]==x){
      return 0; 
  }

  // recursion
  int ans = sol1(a+1,size-1,x);

  if(ans == -1){
    return -1; 
  
  }else{
   return ans +1;
  }

}
 



int main ( ) {


  int arr[] = {2,4,6,23,43,45};
  int size = sizeof(arr) / sizeof(arr[0]);
  cout << sol2(arr,size,4);


  return 0; 
}