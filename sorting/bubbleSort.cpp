#include<iostream>
using namespace std;


void bubble(int a[],int n){
  

  for(int i=0;i<n-1;i++){
  
   for(int j=1; j<n-1-i;j++){

    if(a[j]>a[j+1]){
      int temp = a[j];
      a[j]=a[j+1];
      a[j+1]=temp;

    }

  }
  
  
  }



 

}






int main(){


  int arr[] = {2,4,6,7,3,3,4,45,5,5};
  

  int size = sizeof(arr) / sizeof(arr[0]);
  bubble(arr,size);
  for (int i=0 ; i<size;i++){
    cout << arr[i] << " ";
  }

 
  return 0;
}