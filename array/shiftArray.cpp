#include <iostream>
using namespace std;


void reverse(int a[],int s,int e){


  while(s<e){
    int temp = a[s];
    a[s]=a[e];
    a[e]=temp;
    s++;
    e--;
  }




}



void sol3(int a[],int n,int d){
  
reverse(a,0,n-1);

 reverse(a,0,n-d-1);
 reverse(a,n-d,n-1);



}



void sol2(int a[],int n,int s){

  int *p = new int[s];

  for (int i =0;i<s;i++){

    p[i]=a[i];

  }
  

  for(int i=0;i<n-s;i++){

    a[i]=a[i+s];

  }
  for(int i =0;i<s;i++){
    a[(n-s)+i]=p[i];
  }


   
}



void sol1(int a[],int n,int s){

  for (int j =1;j<=s;j++){
      
  int  temp =a[0];
  for(int i =0 ; i<n;i++){

    a[i]=a[i+1];

  }

  a[n-1]=temp; 
    
  }



}




int main(){


  int arr[] = {2,4,6,7,3,3,4,45,5,5};
  

  int size = sizeof(arr) / sizeof(arr[0]);
    sol2(arr,size,3);
  for (int i=0 ; i<size;i++){
    cout << arr[i] << " ";
  }



 
  return 0;
}