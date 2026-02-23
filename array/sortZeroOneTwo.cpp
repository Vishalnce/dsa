#include<iostream>
using namespace std;

void swap(int a[],int i,int s){
  int temp=a[i];
  a[i]=a[s];
  a[s]=temp;
}


void sort(int a[],int n){

  int s=0;
  int e= n-1;


  for(int i =0;i<=e;i++){
    if(a[i]==0){
      swap(a,i,s);
      s++;
    }else if (a[i]==2){
      swap(a,i,e);
      e--;
      i--;
    }

  }


}




int main(){


  int arr[] = {0,1,1,2,0,1,0,2,2};
  

  int size = sizeof(arr) / sizeof(arr[0]);
     sort(arr,size);
  for (int i=0;i<size;i++){
    cout << arr[i] << " ";
  }


  return 0;
}