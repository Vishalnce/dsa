#include <iostream>
using namespace std;


#include "Node.cpp"


void print( Node* head){

  Node * temp = head;
  while( temp != NULL){

    cout <<  temp->data << " ";
      temp = temp -> next;
  }

}



Node* takeInput(){

  int data;
  cin >> data;

  Node * head = NULL;
  Node * tail = NULL;


  while( data != -1){
    
    Node* newNode = new Node(data);

    if( head == NULL){
      head = newNode;
      tail = newNode;

    } else {
      tail -> next = newNode;
      tail = tail-> next;
    }

    cin >> data;


  }

  return head;


}

Node* insertNode(Node* head ,int i,int data){

  Node* newNode = new Node(data);

  int count =0;

  Node* temp = head;
  if(i==0){
    newNode->next = head;
    head= newNode;
    return head;
  }

  while (temp!= NULL && count < i-1){

    temp = temp->next;
    count ++;
  }

  if(temp!=NULL){
  Node * a =  temp -> next;
  temp->next = newNode;
  newNode -> next=a;

  }


  return head;


}

Node* deleteNode( Node* head,int i){


  Node * temp = head;
  if(i ==0){
    Node *a = head;
    head= head->next;
    delete a;
    return head;
  }
  int count=0;

  while( temp!= NULL &&  count<i-1){

    temp = temp-> next;

    count++;
  }

  if( temp != NULL){
    
  Node * a = temp->next;

  temp->next =temp->next->next;

  delete a;
  }


  return head;


}

Node* insertNodeRec(Node* head, int i,int data ){

  if( head == NULL){

    return head;
 

  }

  if(i==0){
    Node * temp = new Node(data);

    temp -> next = head;
    head = temp;

    return head;
  }

  // recursive call

  Node*ptr = insertNodeRec(head->next,i-1,data);


   head-> next = ptr;

   return head;






}

Node* deleteNodeRec(Node* head, int i ){

  if( head == NULL){

    return head;
 

  }

  if(i==0){
    Node * temp = head ;

    head = head ->next;
    delete temp;
    return head;
  }

  // recursive call

  Node*ptr = deleteNodeRec(head->next,i-1);


   head-> next = ptr;

   return head;






}

Node* eleDup(Node* head  ){

  if( head == NULL){
    return head;
  } 

  Node* t1 = head;
  Node* t2 = head->next;
  while(t2!=NULL){

    if(t1->data == t2->data){
       Node * a = t2;
 
       t2 = t2->next;
       t1->next=t2;
     
      delete a;
    

    }else{
      t1 =t2;
      
      t2 = t2->next;
    }

  }
 

  t1->next = NULL;
  return head;


}

void printRev(Node * head){

  if( head == NULL){

   return  ;
  }

  printRev(head->next);

  cout<<head->data ;



}


int main(){
  



  Node * head = takeInput();

  print(head);

  int i ,data ;

  // cin >> i >> data;
 Node* head1 = eleDup(head);
  printRev(head1);



 

  // Dynamics
  /* 
  Node * n3 = new Node(10);

  Node* headDynamically = n3;
  Node* n4= new Node(12);

  n3->next = n4;

  */
}