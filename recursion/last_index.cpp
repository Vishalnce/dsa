#include <iostream>
using namespace std;



// from start index 

int sol2(int arr[],int size,int x){

  // base case
    if(size ==0 ){
    return -1;
  }  



  // recurison
  int ans = sol2(arr+1,size-1,x);

  // my calcaution
  if(ans == -1){
    if(arr[0]==x){
      return 0;
    }else{
      return -1;
    }
  }else{
      return ans +1;
    }

}



// from last index 
int sol1(int arr[],int size,int x){

  if(size ==0 ){
    return -1;
  }

  int ans  = sol1(arr+1,size-1,x);
  if(ans == -1 ){
    if(arr[0]==x){
      return 0;
    }

    return -1;

    
  }else {
    return ans +1;
  }

}




int main(){

    int arr[] = {2,4,6,7,3,3,4,45,5,5};

  int size = sizeof(arr) / sizeof(arr[0]);
  cout << sol2(arr,size,3)<<endl;
}