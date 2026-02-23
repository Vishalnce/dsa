#include<iostream>
using namespace std;


int sec(int a[],int n){




  int l=-1;
  int s=-1;

  for (int i=0; i<n;i++){

    if (a[i]>l){
      
      s=l;
      l=a[i];
    }else if(a[i]<l && a[i]>s) {
      s=a[i];
    }
    

  }

  return s;


}





int main(){


  int arr[] = {2,4,6,7,3,3,4,45,5,5,9};
  

  int size = sizeof(arr) / sizeof(arr[0]);
  //   sec(arr,size);
  // for (int i=0 ; i<size;i++){
  //   cout << arr[i] << " ";
  // }

  cout<< sec(arr,size) << endl;



 
  return 0;
}