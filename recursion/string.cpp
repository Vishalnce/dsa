#include <iostream>
using namespace std;


void removeX(char s[]){

  if(s[0] == '\0'){
    return ;
  }

  if(s[0]!='x'){
    removeX(s+1);

  }else{
    int i=0;
    for(;s[i]!= '\0';i++){
      s[i]=s[i+1];
    }
    s[i]='\0';
    removeX(s);
  }





}

// for count length 
int length(char s[]){
  if( s[0] == '\0'){
    return 0;
  }

  int smalllen= length(s+1);

  return smalllen+1;

}

int main(){

  char str[100];

  cin>> str;

  // int l = length(str);

  // cout << l <<endl;

  removeX(str);

  cout<<str<<endl;

  return 0;
}