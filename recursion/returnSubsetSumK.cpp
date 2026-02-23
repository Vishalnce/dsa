#include<iostream>
using namespace std;


int sub(int a[],int n,int k,int o[10][10] ){

  if(n==0){
    if(k==0){
      o[0][0]=0;
      return 1;
    }else{
      return 0;
    }
  }

  // s1 is the number of row return 
  int o1[10][10] ={0};
  int o2[10][10] ={0};


  int s1 = sub(a+1,n-1,k-a[0],o1);
  int s2 = sub(a+1,n-1,k,o2);

  for(int i=0;i<s1;i++){
    
      int j =1;
    for(;j<o1[i][0] ;j++){

      o[i][j]=o1[i][j];


    }
    o[i][0]=o1[i][0];
    o[i][j] = a[0]; 
    o[i][0]++;
    
  }


    for(int i=s1;i<s2+s1;i++){
    
    int j =1;
    for(;j<=o2[i-s1][0] ;j++){

      o[i][j]=o2[i-s1][j];


    }
    o[i][0] = o2[i-s1][0];
    
  }



  return s1 +s2;


}

void print(int o[10][10], int rows){

    for(int i = 0; i < rows; i++){

        int len = o[i][0];   // size of subset

        for(int j = 1; j <= len; j++){
            cout << o[i][j] << " ";
        }

        cout << endl;
    }
}




int main(){

  int a[] = {3,2,5,1,4,6};

  int size = sizeof(a)/sizeof(int);
  int  k=8;

  int o[10][10] = {0};

   int rows = sub(a,size,k,o);
    print(o,rows);

  return 0;
}