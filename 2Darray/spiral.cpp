#include <iostream>
using namespace std;


void print(int a[][5],int r,int c){


  int cs=0;
  int ce=c-1;

  int rs=0;
  int re=r-1;



  while (rs <= re && cs <= ce){

   for(int i = cs; i <= ce; i++){
      cout<<a[rs][i]  << " " ;
    
    }
    rs++;


    for(int i = rs; i <= re; i++){
      cout<< a[i][ce]  << " ";

    }
    ce--;

    for(int i=ce;i>=cs;i--){
      cout<< a[re][i]  << " ";

    }
    re--;

    for(int i=re;i>=rs;i--){
      cout<< a[i][cs]  << " ";

    }
    cs++;
    
   
   



  }

}





int main(){

  int a[4][5]= {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};


  print(a,4,5);

  return 0;
}