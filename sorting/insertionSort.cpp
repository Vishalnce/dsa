#include<iostream>
using namespace std;

void ins(int a[],int n){

  for(int i=0;i<n;i++){
      int current = a[i];
      int j;
    for ( j=i-1;j>=0;j--){
      
      if(current<a[j]){
        a[j+1]=a[j];
      }else{
        break;
      }




    }

          a[j+1]=current;




  }


  
}


int main(){


  int arr[] = {2,4,6,7,3,3,4,45,5,5};
  

  int size = sizeof(arr) / sizeof(arr[0]);
   ins(arr,size);
  for (int i=0 ; i<size;i++){
    cout << arr[i] << " ";
  }

 
  return 0;
}