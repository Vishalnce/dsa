#include <iostream>

using namespace std;

#include "BinaryTreeNode.h"
#include <queue>
#include "Node.h"
#include <stack>
#include <string>

void printTree(BinaryTreeNode<int> *root)
{

  if (root == NULL)
  {
    return;
  }

  cout << root->data << ":";
  if (root->left)
  {
    cout << "L" << root->left->data;
  }
  if (root->right)
  {
    cout << "R" << root->left->data;
  }

  cout << endl;

  printTree(root->left);
  printTree(root->right);
}

// TODO: print level wise

BinaryTreeNode<int> *takeInput()
{
  int rootData;
  cout << "Enter root data" << endl;
  cin >> rootData;

  if (rootData == -1)
  {
    return NULL;
  }

  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

  BinaryTreeNode<int> *leftChild = takeInput();
  BinaryTreeNode<int> *rightChild = takeInput();

  root->left = leftChild;
  root->right = rightChild;

  return root;
}

BinaryTreeNode<int> *takeInputLevelWise()
{
  int rootData;
  cout << "Enter root data" << endl;
  cin >> rootData;

  if (rootData == -1)
  {
    return NULL;
  }

  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

  queue<BinaryTreeNode<int> *> pendingNodes;

  pendingNodes.push(root);

  while (pendingNodes.size() != 0)
  {

    BinaryTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();

    int leftChildData;
    cout << "Enter left child data of " << front->data << endl;
    cin >> leftChildData;

    if (leftChildData != -1)
    {
      BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
      front->left = leftChild;
      pendingNodes.push(leftChild);
    }

    int rightChildData;
    cout << "Enter right child data of " << front->data << endl;
    cin >> rightChildData;

    if (rightChildData != -1)
    {
      BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
      front->right = rightChild;
      pendingNodes.push(rightChild);
    }
  }

  return root;
}

int numberOfNodes(BinaryTreeNode<int> *root)
{

  if (root == NULL)
  {
    return 0;
  }

  int ans = 1;

  int left = numberOfNodes(root->left);
  int right = numberOfNodes(root->right);

  return ans + left + right;
}

void inOrder(BinaryTreeNode<int> *root)
{

  if (root == NULL)
  {
    return;
  }

  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

BinaryTreeNode<int> *buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{

  if (inS > inE)
  {
    return NULL;
  }

  int rootData = pre[preS];
  int rootIndex = -1;
  for (int i = inS; i <= inE; i++)
  {
    if (in[i] == rootData)
    {
      rootIndex = i;
      break;
    }
  }
  int lInS = inS;
  int lInE = rootIndex - 1;
  int lPreS = preS + 1;
  int lPreE = lInE - lInS + lPreS;
  int rPreS = lPreE + 1;
  int rPreE = preE;
  int rInS = rootIndex + 1;
  int rInE = inE;

  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

  root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
  root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);

  return root;
}

BinaryTreeNode<int> *buildTree(int *in, int *pre, int size)
{

  return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}

pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{

  if (root == NULL)
  {
    pair<int, int> p;
    p.first = 0;
    p.second = 0;
    return p;
  }

  pair<int, int> leftAns = heightDiameter(root->left);
  pair<int, int> rightAns = heightDiameter(root->right);

  int ld = leftAns.second;
  int lh = leftAns.first;
  int rd = rightAns.second;
  int rh = rightAns.first;

  int height = 1 + max(lh, rh);
  int diameter = max(lh + rh, max(ld, rd));

  pair<int, int> p;
  p.first = height;
  p.second = diameter;

  return p;
}

pair<int, bool> helperIsBalanced(BinaryTreeNode<int> *root)
{
  if (root == NULL)
  {
    pair<int, bool> p;
    p.first = -1; // first is  heght
    p.second = true;
    return p;
  }

  pair<int, bool> t1 = helperIsBalanced(root->left);
  pair<int, bool> t2 = helperIsBalanced(root->right);

  pair<int, bool> ans;

  if (t1.second == false || t2.second == false)
  {

    ans.second = false;
  }
  if (t1.second == true && t2.second == true)
  {

    int temp = abs(t1.first - t2.first);

    if (temp <= 1)
    {
      ans.second = true;
    }
    else
    {
      ans.second = false;
    }
  }

  ans.first = max(t1.first, t2.first) + 1;

  return ans;
}

bool isBalanced(BinaryTreeNode<int> *root)
{

  pair<int, bool> p = helperIsBalanced(root);

  return p.second;
}

void printLevelWise(BinaryTreeNode<int> *root)
{

  if (root == NULL)
  {
    return;
  }
  queue<BinaryTreeNode<int> *> q;

  q.push(root);

  while (!q.empty())
  {

    BinaryTreeNode<int> *temp = q.front();
    q.pop();
    cout << temp->data << ":";

    if (temp->left != NULL)
    {
      cout << "L" << temp->left->data << " ";
      q.push(temp->left);
    }

    if (temp->right != NULL)
    {
      cout << "R" << temp->right->data;
      q.push(temp->right);
    }

    cout << endl;
  }
}

void printLevelWise1(BinaryTreeNode<int> *root) // imporatant
{

  if (root == NULL)
  {
    return;
  }

  queue<BinaryTreeNode<int> *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    BinaryTreeNode<int> *curr = q.front();
    q.pop();

    if (curr == NULL)
    {
      cout << endl;
      if (!q.empty())
        q.push(NULL);
    }
    else
    {
      cout << curr->data << " ";

      if (curr->left != NULL)
        q.push(curr->left);

      if (curr->right != NULL)
        q.push(curr->right);
    }
  }
}

vector<Node<int> *> levelWiseLL(BinaryTreeNode<int> *root)
{

  if (root == NULL)
  {

    vector<Node<int> *> v;

    return v;
  }

  queue<BinaryTreeNode<int> *> q;

  vector<Node<int> *> v;

  Node<int> *head = NULL;
  Node<int> *tail = NULL;

  q.push(root);

  q.push(NULL);

  while (!q.empty())
  {

    BinaryTreeNode<int> *cur = q.front();
    q.pop();

    if (cur == NULL)
    {

      v.push_back(head);

      if (!q.empty())
      {
        q.push(NULL);
      }

      head = NULL;
      tail = NULL;

      //  add null at tail
      //  save to output

      // put null by cheking
    }
    else
    {

      Node<int> *temp = new Node<int>(cur->data);

      if (head == NULL && tail == NULL)
      {
        head = temp;
        tail = temp;
      }
      else
      {
        tail->next = temp;
        tail = tail->next;
      }
      if (cur->left != NULL)
        q.push(cur->left);

      if (cur->right != NULL)
        q.push(cur->right);

      // Create a node

      // update head and tails

      // puhs its childre to queu
    }
  }

  return v;
}

void helperZigZiag(BinaryTreeNode<int> *root)
{

  stack<BinaryTreeNode<int> *> s1;
  stack<BinaryTreeNode<int> *> s2;

  s1.push(root);

  while (!s1.empty() || !s2.empty())
  {
    while (!s1.empty())
    {
      BinaryTreeNode<int> *temp = s1.top();
      s1.pop();

      cout << temp->data;

      if (temp->left != NULL)
      {
        s2.push(temp->left);
      }

      if (temp->right != NULL)
      {
        s2.push(temp->right);
      }
    }

    cout << endl;

    while (!s2.empty())
    {
      BinaryTreeNode<int> *temp = s2.top();
      s2.pop();

      cout << temp->data;

      if (temp->right != NULL)
      {
        s1.push(temp->right);
      }

      if (temp->left != NULL)
      {
        s1.push(temp->left);
      }
    }
  }
}

void zigZagPrint(BinaryTreeNode<int> *root) // imporetant
{

  if (root == NULL)
  {
    return;
  }
  helperZigZiag(root);
}

int minimum(BinaryTreeNode<int> *root)
{

  if (root == NULL)
  {
    return INT_MAX;
  }

  int left = minimum(root->left);
  int right = minimum(root->right);

  int rootData = root->data;

  return min(rootData, min(left, right));
}

int maximum(BinaryTreeNode<int> *root)
{

  if (root == NULL)
  {
    return INT_MIN;
  }

  int left = maximum(root->left);
  int right = maximum(root->right);

  int rootData = root->data;

  return max(rootData, max(left, right));
}

bool isBST(BinaryTreeNode<int> *root)
{

  if (root == NULL)
  {
    return true;
  }

  int leftMax = maximum(root->left);

  int rightMin = minimum(root->right);

  bool output = (root->data > leftMax) && (root->data < rightMin) && isBST(root->left) && isBST(root->right);

  return output;
}

class isBSTReturn
{

public:
  int minimum;
  int maximum;
  bool isBST;
};

isBSTReturn isBST2(BinaryTreeNode<int> *root)
{

  if (root == NULL)
  {
    isBSTReturn b;
    b.maximum = INT_MIN;
    b.minimum = INT_MAX;
    b.isBST = true;

    return b;
  }

  isBSTReturn t1 = isBST2(root->left);
  isBSTReturn t2 = isBST2(root->right);

  int minimum = min(root->data, min(t1.minimum, t2.minimum));
  int maximum = min(root->data, min(t1.maximum, t2.maximum));

  bool isBSTFinal = (root->data > t1.maximum) && (root->data < t2.minimum) && t1.isBST && t2.isBST;

  isBSTReturn output;

  output.isBST = isBSTFinal;
  output.maximum = maximum;
  output.minimum = minimum;

  return output;
}

bool isBST3(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{ // importanta

  if (root == NULL)
  {

    return true;
  }

  if (root->data < min || root->data > max)
  {

    return false;
  }

  bool t1 = isBST3(root->left, min, root->data - 1);
  bool t2 = isBST3(root->right, max, root->data);

  return t1 && t2;
}

Node<int> *BSTToLL(BinaryTreeNode<int> *root)
{ // it is O(n square make it O(n) using pari

  if (root == NULL)
  {
    return NULL;
  }

  Node<int> *leftNode = BSTToLL(root->left);

  Node<int> *rightNode = BSTToLL(root->right);

  Node<int> *rootNode = new Node<int>(root->data);

  // connetcing right part

  rootNode->next = rightNode;

  // connecting left

  Node<int> *temp = leftNode;

  if (temp == NULL)
  {
    return rootNode;
  }
  else
  {

    while (temp->next != NULL)
    {

      temp = temp->next;
    }

    temp->next = rootNode;

    return leftNode;
  }
}

vector<int> *getRootToNodePath(BinaryTreeNode<int> *root, int data)
{

  if (root == NULL)
  {
    return NULL;
  }

  if (root->data == data)
  {
    vector<int> *output = new vector<int>();
    output->push_back(root->data);
    return output;
  }

  vector<int> *leftOutput = getRootToNodePath(root->left, data);

  if (leftOutput != NULL)
  {
    leftOutput->push_back(root->data);
    return leftOutput;
  }

  vector<int> *rightOutput = getRootToNodePath(root->right, data);

  if (rightOutput != NULL)
  {
    rightOutput->push_back(root->data);
    return rightOutput;
  }
  else
  {
    return NULL;
  }
}

BinaryTreeNode<int> *addDup(BinaryTreeNode<int> *root)
{

  if (root == NULL)
  {
    return NULL;
  }

  BinaryTreeNode<int> *leftNode = addDup(root->left);
  BinaryTreeNode<int> *rightNode = addDup(root->right);

  BinaryTreeNode<int> *temp = new BinaryTreeNode<int>(root->data);

  root->left = temp;
  temp->left = leftNode;
  root->right = rightNode;

  return root;
}

int search(BinaryTreeNode<int> *root, int x)
{

  if (root == NULL)
  {
    return -1;
  }

  if (root->data == x)
  {

    root->data = INT_MIN;

    return x;
  }

  int left = search(root->left, x);

  int right = search(root->right, x);

  if (left == -1)
  {
    return right;
  }
  else
  {
    return left;
  }
}

void printPairSum(BinaryTreeNode<int> *root, int s)
{

  if (root == NULL)
  {
    return;
  }

  if (root->data != INT_MIN)
  {

    int r = s - root->data;

    int leftNode = search(root->left, r);
    int rightNode = search(root->right, r);

    if (leftNode == -1 && rightNode == -1)
    {
    }
    else
    {
      if (leftNode != -1)
      {
        cout << root->data << " " << leftNode << endl;
      }
      else
      {
        cout << root->data << " " << rightNode << endl;
      }
    }
  }

  printPairSum(root->left, s);

  printPairSum(root->right, s);
}

int LCA(BinaryTreeNode<int> *root, int n1, int n2)
{

  if (root == NULL)
  {
    return -1;
  }

  if (root->data == n1 || root->data == n2)
  {
    return root->data;
  }

  int leftNode = LCA(root->left, n1, n2);
  int rightNode = LCA(root->right, n1, n2);

  if (leftNode != -1 && rightNode != -1)
  {
    return root->data;
  }

  if (leftNode == -1 && rightNode == -1)
  {
    return -1;
  }

  if (leftNode == -1)
  {
    return rightNode;
  }
  else
  {
    return leftNode;
  }
}

class LBST
{

public:
  int minimum;
  int maximum;
  bool isBST;
  int height;
};

LBST helperLBST(BinaryTreeNode<int> *root)
{

  if (root == NULL)
  {
    LBST temp;
    temp.height = -1;
    temp.isBST = true;
    temp.maximum = INT_MAX;
    temp.minimum = INT_MIN;

    return temp;
  }

  LBST leftNode = helperLBST(root->left);

  LBST rightNode = helperLBST(root->right);

  LBST rootNode;

  if (leftNode.isBST && rightNode.isBST && root->data > leftNode.maximum && root->data < rightNode.minimum)
  {
    rootNode.isBST = true;
    rootNode.minimum = leftNode.minimum;
    rootNode.maximum = rightNode.maximum;
    rootNode.height = max(leftNode.height, rightNode.height) + 1;
  }
  else
  {
    rootNode.isBST = false;
    rootNode.height = max(leftNode.height, rightNode.height);
  }

  return rootNode;
}

int largestBST(BinaryTreeNode<int> *root)
{

  LBST temp = helperLBST(root);

  return temp.height;
}


void printPath(BinaryTreeNode<int> * root,int k,string s=""){

  if(root == NULL){

    return;

  }

  s = s+to_string(root->data) + " ";

  if(root->left == NULL && root->right == NULL && k== root->data){

      cout << s << endl;

    return;
  }

  printPath(root->left,k-root->data,s);
  printPath(root->right,k-root->data,s);



}


int helperSumOfGreaterNode(BinaryTreeNode<int> * root,int s){

  if( root == NULL){

    return 0;
  }

  int rightNode =  helperSumOfGreaterNode(root->right,s);

  int temp = root->data;
  root->data = root->data + rightNode;

  int leftNode = helperSumOfGreaterNode(root->left,root->data);

  root->data = root->data+s;

  return rightNode + temp + leftNode;


}

// IMPORtnatn

void replaceSumOfGreaterNode(BinaryTreeNode<int> * root){


  int temp = helperSumOfGreaterNode(root,0);

  return ;


}

void printRootToLeaf(BinaryTreeNode<int> * root,int k,string s= "" ){  // IMportant

  if(root== NULL){
    return ;
  }

  
  s = s + to_string(root->data) + " ";

  if( root->data == k && root->left == NULL && root->right ==NULL){
  
    cout<<s;
  }

  
  


  printRootToLeaf(root->left,k-root->data,s);
  printRootToLeaf(root->right,k-root->data,s);



} 


BinaryTreeNode<int>* searchNode(BinaryTreeNode<int> *root, int x)
{

  if (root == NULL)
  {
    return NULL;
  }

  if (root->data == x)
  {

    return root;
  }

  BinaryTreeNode<int>* left = searchNode(root->left, x);

   BinaryTreeNode<int>* right = searchNode(root->right, x);

  if (left == NULL)
  {
    return right;
  }
  else
  {
    return left;
  }
}


void printNodeAtK(BinaryTreeNode<int> * root,int k){

  if( root==NULL){
    return ;
  }

  if( k==0 ){
    cout<< root->data<<endl;
    return;
  }


  printNodeAtK(root->left,k-1);
  printNodeAtK(root->right,k-1);

}

int printNodeFromKNode(BinaryTreeNode<int>* root,int data ,int k ){  //impoertanta too much

  if(root == NULL){
    return -1;
  }

  if( root->data == data){
    printNodeAtK(root,k);

    return 0;

  }

  int leftNode = printNodeFromKNode(root->left,data,k);
  int rightNode = printNodeFromKNode(root->right,data,k);

   if(leftNode != -1){

    if(leftNode + 1 == k){
      cout << root->data << endl;
    }else{
      int rightPath = k - leftNode - 2;
      printNodeAtK(root->right,rightPath);
    }

    return leftNode + 1;
  }

  if(rightNode != -1){

    if(rightNode + 1 == k){
      cout << root->data << endl;
    }else{
      int leftPath = k - rightNode - 2;
      printNodeAtK(root->left,leftPath);
    }

    return rightNode + 1;
  }

  return -1;

   
  

  










}


//   TODO mirroe binary tree
int main()
{

  // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
  BinaryTreeNode<int> *root = takeInputLevelWise();

  cout << isBST3(root) << endl;
  // cout << numberOfNodes(root);
  delete root;
  return 0;
}
