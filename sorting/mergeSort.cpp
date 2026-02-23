#include <iostream>
using namespace std;


void merge_help(int a[],int m, int b[],int n, int* p) {

  int i =0;
  int j =0;
  int k =0;

while(i < m && j < n) {
        if(a[i] <= b[j]) {
            p[k++] = a[i++];
        } else {
            p[k++] = b[j++];
        }
    }


   while(i < m) {
        p[k++] = a[i++];
    }

    while(j < n) {
        p[k++] = b[j++];
    }



}


void merge(int a[],int s,int e){


  //base case 
  if(s>=e){

    return ;
  }

  //
  int mid = (s+e)/2;

  merge(a,s,mid);

  merge(a,mid+1,e);

  int t = e - s + 1;

  int * p =new int[t];

merge_help(a + s, mid - s + 1, a + mid + 1, e - mid, p);


for(int i = 0; i < t; i++){
    a[s + i] = p[i];
}


  delete [] p;
  


}


int main(){


   int arr[] = {2,4,6,7,3,3,4,45,5,5};

  int size = sizeof(arr) / sizeof(arr[0]);

  merge(arr,0,size-1);

  for (int i=0 ; i<size;i++){
    cout << arr[i] << " ";
  }


  return 0;
}