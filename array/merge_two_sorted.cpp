#include <iostream>
using namespace std;

void merge(int a[],int m, int b[],int n, int* p) {

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
 
int main() {

  int a[] ={1,3,5,7};

  int m = sizeof(a) / sizeof(a[0]);

  int b[] = {2,4,6,8};

  int n = sizeof(b) / sizeof(b[0]);




  int*p = new int[m+n];

  merge(a,m,b,n,p);

  for (int i=0 ; i<(m+n);i++){
    cout << p[i] << " ";
  }

  delete [] p;
  return 0;
}