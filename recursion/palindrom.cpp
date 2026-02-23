#include<iostream>
#include <string>
using namespace std;

bool pali(string p,int s,int e){
if(s >= e) return true; 
  if(p.length() == 0 || p.length() == 1 ){
    return true;
  }

  if(p[s] == p[e]){
    bool t = pali(p,s+1,e-1);

    if(t){
      return true;
    }else {
      return false;
    }
  }else{
    return false;
  }



}


int main(){

  string s = "abcba";

  cout << pali(s,0,4);
  return 0;
}