#include<iostream>
using namespace std ;


int knapsack(int * w,int * v , int n ,int m){

  if( n==0  || m == 0){
    return 0;
  }

  if( w[0]>m){
      int a = knapsack(w+1,v+1,n-1,m ); 
      return a ; 
  }

  
  int a = knapsack(w+1,v+1,n-1,m - w[0]) +v[0];
  int b = knapsack(w+1,v+1,n-1,m);

  int ans = max(a,b);
  return ans ;

}






int main (){


  int n =4;
  int w[] = {1,2,4,5}; // if you will take this input then it will nocreate sub overlapping problem but if you tak int w[] = {1, 2, 3, 5}; theis swill creat dsub overlapping problme
  int v[] = {5,4,8,6};

  int m=5;

  cout<<  knapsack(w,v,n,m);



  return 0 ;
}