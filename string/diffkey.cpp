#include<iostream>
using namespace std;
#include<string>


const string letters[10] = {
    "", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};


void print(int i,string o){

  if(i==0){
    cout<<o<<endl;
    return;
  }

  int num = i%10;

  for(int k = 0; k < letters[num].size(); k++)
{
    print(i/10,o +letters[num][k]);
}




}



int main(){

  int input;
  cin >> input;
  
  string output = "";



  print(input,output);





return 0;
}
