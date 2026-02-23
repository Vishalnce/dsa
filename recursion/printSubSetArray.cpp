#include <iostream>
using  namespace std;

void print(int a[],int m){

  for(int i  =0;i<m;i++){
    cout<< a[i];
  }
  cout<<endl;
}


void sub( int a[],int n, int* b,int m ){

  if(n==0){
    print(b,m);
    return ;
  }


  m++;

  int *p = new int[m];
  
  p[0]=a[0];

  for(int i =0;i<m-1;i++){
    p[i+1]=b[i];
  }

  sub(a+1,n-1,p,m);



  sub(a+1,n-1,b,m-1);
  delete [] p;

 


}





int main(){

  int a[] = {1,2,3};

  int size = sizeof(a)/sizeof(int);



  int m =0;

  int *b = new int[m];


  sub(a,size,b,m);
  delete [] b;
  return 0;
}