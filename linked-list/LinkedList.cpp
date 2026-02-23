#include <iostream>
using namespace std;


#include "Node.cpp"


int main(){
  


  Node n1(1);
  Node * head = & n1;

  Node n2(2);



  n1.next = &n2;

}