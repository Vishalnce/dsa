#include<iostream>
using namespace std;
#include<string>


const string letters[10] = {
    "", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};

int key(int input, string p[]) {

  int d = input%10;

  int nextNum = input/10;

  if(input ==0 ){
    p[0]="";
    return 1;

  }

 

 int temp = key(nextNum,p);
  string old[1000];
    for(int i = 0; i < temp; i++){
        old[i] = p[i];
    }
 for(int i = 0; i < letters[d].length(); i++){
    for(int j = 0; j < temp; j++){

    p[j + (temp*i)]  = old[j]+letters[d][i];


  }

 
      
}

 return temp*letters[d].length();


}



int main(){

  int input;

  cin >> input;

  string*p = new string[1000];




int count = key(input, p);
for(int i = 0; i < count; i++) {
    cout << p[i] << endl;
}
delete[] p;  // Memory cleanup






return 0;
}
