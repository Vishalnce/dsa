#include<iostream>
using namespace std;


int helperMinStempDP(int n,int * arr){

  arr[0]=0;
  arr[1]=0;
  arr[2]=1;
  arr[3]=1;

  for(int i =4;i<=n;i++){

    int a = i;

    int x = 1 + arr[a-1];


    int y = INT_MAX;
    int z = INT_MAX;

    if(a%2==0){
      y = 1 + arr[a/2];
 
    }

     if(a%3==0){
      z = 1+ arr[a/3];

      
    }

    arr[i] = min(x , min(y,z));


  

  }

  
    return arr[n];

}

int minStempDP(int n ){
  int * arr = new int[n+1];

  for(int i =0 ;i<=n-1;i++){
    arr[i] = -1;


  }

  int ans = helperMinStempDP( n,arr); 

    return ans ;  

}


int minStepMemo(int n,int * arr){

  if( n<=1){
    return 0;

  }


  if(arr[n] != -1)
    return arr[n];
  
  int x = minStepMemo(n-1,arr);
   int y = INT_MAX;
   int z = INT_MAX;

  if((n%2==0)){

    y = minStepMemo(n/2,arr);
  }

  
  if((n%3==0)){

    z= minStepMemo(n/3,arr);
  }

  int output = min(x,min(y,z)) +1;

  arr[n]=output;
return output;



}

int  minSteps(int n){
  if(n<=1){
    return 0;
  }


  int x = minSteps(n-1);
   int y = INT_MAX;
   int z = INT_MIN;

  if((n%2==0)){

    y = minSteps(n/2);
  }

  
  if((n%3==0)){

    z= minSteps(n/3);
  }

  int output = min(x,min(y,z)) +1;

 
return output;

}


int main(){


  int n ; 
  cin >> n;

  cout<< minSteps(n)<<endl;

  return 0 ;
}