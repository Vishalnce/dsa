#include<iostream>
using namespace std;


void flip(int a[],int x,int s){
  int t = a[s+x];
   a[s+x] = a[s];

   a[s]= t;

}


int partition(int a[],int s,int e){

  int smallerNum =0;

   int pivoti = a[s];

for(int i = s + 1; i <= e; i++) {
    if(a[i] <= pivoti) {
        smallerNum++;
    }
}

    flip(a,smallerNum,s);

    // we have to swap 

    int pivotIndex = s + smallerNum;
    int pivot = a[pivotIndex];

    int i = s;
    int j =e;
    while (i < pivotIndex&& j>pivotIndex){

      if(a[i]>pivot){
        if(a[j]<pivot){
          int t = a[j];
          a[j]=a[i];
          a[i]=t;
          i++;
          j--;
        }else{
          j--;
        }
      }else{
        i++;
      }
    }

    return pivotIndex;


}

void quick(int a[],int s,int e){

  if(s>=e){
    return ;
  }

  int c = partition(a,s,e);

  quick(a,s,c-1);
  quick(a,c+1,e);


}


int main() {


     int arr[] = {2,4,6,7,3,3455,45,45,452,45,5,5};

  int size = sizeof(arr) / sizeof(arr[0]);

quick(arr,0,size-1);

  for (int i=0 ; i<size;i++){
    cout << arr[i] << " ";
  }


  return 0;
}