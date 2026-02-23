#include <iostream>
using namespace std;

int binary(int a[],int s,int e,int key){

  while(s<=e){

    int mid = (s +e)/2;

    if( a[mid] == key){
      return mid;
    }

    if( key> a[mid]){
       s = mid+1;
    }else{
       e = mid-1;
    }



  }

  return -1;
  

}




int main(){

  int arr[] = {1,2,3,4,5,6,7,8,9,10};
  int n = sizeof(arr)/sizeof(arr[0]);


  cout << binary(arr,0,9,14);


  return 0;
}