#include <iostream>
using namespace std;

#include "Node.cpp"

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

Node *mergeTwo(Node *h1, Node *h2)  // importan question
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

int main()
{

  Node *head = takeInput();

   Node *head2 = takeInput();

   print(mergeTwo(head, head2));

  // print(mergeSort(head));

  // cin >> i >> data;
  //  Node* head1 = eleDup(head);
}