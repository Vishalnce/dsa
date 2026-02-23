#include <iostream>
using  namespace std;

void print(int a[],int m){

  for(int i  =0;i<m;i++){
    cout<< a[i];
  }
  cout<<endl;
}


void sub( int a[],int n, int* b,int m ,int k){

  if(n==0){
    if(k==0){
      print(b,m);
      return ;
    }else{
      return ;
    }
  }


  m++;

  int *p = new int[m];
  
  p[0]=a[0];

  for(int i =0;i<m-1;i++){
    p[i+1]=b[i];
  }

  sub(a+1,n-1,p,m,k-a[0]);



  sub(a+1,n-1,b,m-1,k);
  delete [] p;

 


}





int main(){

  int a[] = {5,1,2,6,7,4,3};

  int size = sizeof(a)/sizeof(int);

  int k=9;

  int m =0;

  int *b = new int[m];


  sub(a,size,b,m,k);
  delete [] b;
  return 0;
}