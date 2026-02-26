#include <iostream>
using namespace std;

#include "Node.cpp"

class Pair
{
public:
  Node *head;
  Node *tail;
};

Node *takeInput()
{

  int data;
  cin >> data;

  Node *head = NULL;
  Node *tail = NULL;

  while (data != -1)
  {

    Node *newNode = new Node(data);

    if (head == NULL)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = tail->next;
    }

    cin >> data;
  }

  return head;
}

void print(Node *head)
{

  Node *temp = head;
  while (temp != NULL)
  {

    cout << temp->data << " ";
    temp = temp->next;
  }
}

//  Middle of linked list

Node *middleLL(Node *head)
{

  Node *slow = head;
  Node *fast = head->next;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

Node *mergeTwo(Node *h1, Node *h2) // importan question
{

  Node *fh = NULL;
  Node *ft = NULL;

  if (h1 == NULL)
    return h2;
  if (h2 == NULL)
    return h1;

  if (h1->data <= h2->data)
  {
    fh = h1;
    ft = h1;
    h1 = h1->next;
  }
  else
  {
    fh = h2;
    ft = h2;
    h2 = h2->next;
  }

  while (h1 != NULL && h2 != NULL)
  {

    if (h1->data <= h2->data)
    {
      ft->next = h1;
      ft = h1;
      h1 = h1->next;
    }
    else
    {
      ft->next = h2;
      ft = h2;
      h2 = h2->next;
    }
  }

  if (h2 == NULL)
  {
    ft->next = h1;
  }
  else
  {
    ft->next = h2;
  }

  return fh;
}

Node *mergeSort(Node *head)
{

  if (head == NULL || head->next == NULL)
  {
    return head;
  }

  Node *middle = middleLL(head);

  Node *h1 = head;
  Node *h2 = middle->next;

  middle->next = NULL;

  Node *final1 = mergeSort(h1);
  Node *final2 = mergeSort(h2);

  Node *final = mergeTwo(final1, final2);

  return final;
}

Node *reverseLL(Node *head)
{

  if (head == NULL || head->next == NULL)
  {
    return head;
  }

  Node *temp = reverseLL(head->next);
  Node *a = temp;
  while (a->next != NULL)
  {
    a = a->next;
  }
  a->next = head;

  a->next->next = NULL;

  return temp;
}

Pair reverseLL2(Node *head)
{

  if (head == NULL || head->next == NULL)
  {
    Pair ans;
    ans.head = head;
    ans.tail = head;
    return ans;
  }

  Pair temp = reverseLL2(head->next);

  temp.tail->next = head;
  head->next = NULL;
  Pair ans;
  ans.head = temp.head;
  ans.tail = head;

  return ans;
}



Node *evenOdd(Node *head)
{

  Node *oh = NULL;
  Node *ot = NULL;
  Node *eh = NULL;
  Node *et = NULL;

  while (head != NULL)
  {

    if ((head->data) % 2 == 0)
    {
      if (oh == NULL)
      {
        oh = head;
        ot = head;
        head = head->next;
      }
      else
      {
        ot->next = head;
        ot = ot->next;
        head = head->next;
      }
    }
    else
    {
      if (eh == NULL)
      {
        eh = head;
        et = head;
        head = head->next;
      }
      else
      {
        et->next = head;
        et = et->next;
        head = head->next;
      }
    }
  }

  if (ot != NULL)
    ot->next = NULL;
  if (et != NULL)
    et->next = NULL;

  if (ot != NULL && eh != NULL)
  {
    ot->next = eh;
    return oh;
  }

  if (ot == NULL)
  {
    return eh;
  }

  if (eh == NULL)
  {
    return oh;
  }

  return NULL;
}


void skipMandNNode(Node* head,int m,int n){  // Important question

    if(head == NULL || m <= 0) return;


  Node *t1 =head;
  Node *t2 =NULL;


  while(t1!=NULL ){
     for(int i =1 ; i<m && t1!=NULL;i++){
    t1=t1->next;
  }

   if(t1 == NULL) break;
  t2= t1->next;
  
 

  for(int i =0 ; i<n && t2!=NULL;i++){
    Node * a = t2;
    t2=t2->next;
    delete a;
  }

 

  t1->next=t2;
  t1=t2;




  }
 


}


Node* kRev(Node* head,int k){ // good question 

  if(head == NULL || head->next  ==NULL || k<=1){
    return head ;
  }


  Node * h = head;
  Node * a =head;;
  Node * t = NULL;

   for(int i =1;i<k && a!=NULL;i++){
    a= a->next;

   }

   if(a == NULL)    // importanta
    return head;
   t=a;

  
   Node * h2 = t->next;
   t->next =NULL;

   Pair temp = reverseLL2(h);

   Node * temp1 = kRev(h2,k);

   temp.tail->next= temp1;


   return temp.head;






}





int main()
{

  Node *head = takeInput();

  // skipMandNNode(head, 2, 3);

  print(kRev(head,3));

  //  Node *head2 = takeInput();

  //  print(mergeTwo(head, head2));

  // print(mergeSort(head));

  // cin >> i >> data;
  //  Node* head1 = eleDup(head);
}