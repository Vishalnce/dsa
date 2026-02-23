#include <iostream>
using namespace std;


bool is_sorted(int a[],int size){
  if (size == 0 && size == 1){
    return true;

  }

  if(a[0] > a[1]){
    return false;
  }

  bool isSamallerSoreted = is_sorted(a+1,size-1);
    if(isSamallerSoreted){
      return false;

    }else{
      return true;
    }
  

}

int main (){

  int arr[] = {2,3,4,45,5,5};

  int size = sizeof(arr) / sizeof(arr[0]);

   if (is_sorted(arr, size)) {
        cout << "Array is sorted" << endl;
    } else {
        cout << "Array is not sorted" << endl;
    }
    return 0;
}