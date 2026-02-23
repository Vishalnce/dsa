#include <iostream>
using namespace std;

bool check(char s[],char t[],int a[]){

  bool g =true;
  for(int i=0;i<3;i++){
    int c = s[i];
    a[c]++;
  }

  for(int i=0;i<3;i++){
    int c = t[i];
    a[c]--;
  }
  for(int i=0;i<256;i++){
    if(a[i]!=0){
      g = false;
      break;
    }
  }

  return g;

}


int main(){

  int  a[256]={0};  
  char s[20] = "aba";
  char t[20] = "bab";

  check(s,t,a) ? cout<<"Yes" : cout<<"No";



  return 0;

}