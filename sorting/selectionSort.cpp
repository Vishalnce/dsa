#include<iostream>
using namespace std;



void sel(int a[],int n){

  for(int i = 0 ;i<n-1;i++ ){
  int  min = a[i];
  int minIndex = i;

  for(int j= i+1;j<n;j++){
    if(a[j]<min){
      min = a[j];
      minIndex=j;
    }
  }

  // swap 
  int temp = a[i];
  a[i]= a[minIndex];
  a[minIndex]=temp;

  }



}


int main(){


  int arr[] = {2,4,6,7,3,3,4,45,5,5};
  

  int size = sizeof(arr) / sizeof(arr[0]);
  sel(arr,size);
  for (int i=0 ; i<size;i++){
    cout << arr[i] << " ";
  }

 
  return 0;
}