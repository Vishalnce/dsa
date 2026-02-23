#include <iostream>
using namespace std;



int* sum(int a[],int n,int r[],int m){

  int o = n; 
  if(m>n){
    o=m;
  }

  int i=n-1;
  int j =m -1;
  int k = o;

  int c=0;

  int *p = new int[o+1];

  for(int t =k;t>0;t--){

    int x =0 ;
    int y= 0;

    if( i!=-1){
      x= a[i];
      i--;
    }

    if( j!=-1){
      y= r[j];
      j--;
    }

    int num = x + y+c;

    p[t]= num%10;

    c= num/10;


    
  }

 p[0] = c;

  return p;

 
}
int main(){

  int a[] = {9,9,9};
  int r[] = {1};

  int n = 3;
  int m = 1;

  int *q= sum(a,n,r,m);

  for(int i = 0; i <max(n,m)+1; i++){
    cout << q[i] << " ";
  }

  return 0;

}
