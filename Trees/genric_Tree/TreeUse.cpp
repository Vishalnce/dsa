#include <iostream>
using namespace std;

#include "TreeNode.h"
#include <queue>
#include "Pair.h"

void printTree(TreeNode<int> *root)
{

  if (root == NULL)
  {
    return;
  }
  cout << root->data << ":";
  for (int i = 0; i < root->children.size(); i++)
  {
    cout << root->children[i]->data << ",";
  }
  cout << endl;
  for (int i = 0; i < root->children.size(); i++)
  {
    printTree(root->children[i]);
  }
}

// level order printing

void printTreeLevelWise(TreeNode<int> *root)
{

  if (root == NULL)
  {
    return;
  }

  queue<TreeNode<int> *> pendingNodes;

  cout << root->data << ":";

  for (int i = 0; i < root->children.size(); i++)
  {
    cout << root->children[i]->data << ",";
    pendingNodes.push(root->children[i]);
  }
  cout << endl;

  while (pendingNodes.size() != 0)
  {
    TreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();

    cout << front->data << ":";
    for (int i = 0; i < front->children.size(); i++)
    {
      cout << front->children[i]->data << ",";
      pendingNodes.push(front->children[i]);
    }

    cout << endl;
  }
}


void preOrder(TreeNode<int> *root)
{

  if (root == NULL)
  {
    return;
  }

  cout << root->data << " ";

  for (int i = 0; i < root->children.size(); i++)
  {
    preOrder(root->children[i]);
  }
}

void postOrder(TreeNode<int> *root)
{

  if (root == NULL)
  {
    return;
  }

  for (int i = 0; i < root->children.size(); i++)
  {
    postOrder(root->children[i]);
  }

  cout << root->data << " ";
}

void deleteTree(TreeNode<int> * root){
  for(int i = 0 ;i<root->children.size();i++ ){

    deleteTree(root->children[i]);


  }
  delete root;
}

Pair<int> nodeWithMax(TreeNode<int> * root){

  if( root ==NULL ){
    Pair <int> ans;
    ans.ptr =NULL;
    ans.sum=0;
  
    return ans;
  }


  Pair<int> temp;

  temp.ptr = root;
  temp.sum=0;

  for(int i =0;i<root->children.size();i++){
    temp.sum =temp.sum + (root->children[i])->data;
  }
  temp.sum += root->data;

  for(int i =0;i<root->children.size();i++){
    Pair<int> t1=  nodeWithMax(root->children[i]);

    if(t1.sum>temp.sum){
      temp.sum = t1.sum;
      temp.ptr = t1.ptr;
    }

  }

  

  return temp;




}



TreeNode<int> *takeInputLevelWise()
{
  int rootData;
  cout << "Enter root data" << endl;
  cin >> rootData;

  TreeNode<int> *root = new TreeNode<int>(rootData);

  queue<TreeNode<int> *> pendingNodes;

  pendingNodes.push(root);

  while (pendingNodes.size() != 0)
  {
    TreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    cout << "Enter number of children of " << front->data << endl;
    int numChild;
    cin >> numChild;
    for (int i = 0; i < numChild; i++)
    {
      int childData;
      cout << "Enter " << i << "th child data of node " << front->data << endl;
      cin >> childData;
      TreeNode<int> *child = new TreeNode<int>(childData);
      front->children.push_back(child);
      pendingNodes.push(child);
    }
  }

  return root;
}

int countNodes(TreeNode<int> *root)
{
  if (root == NULL)
  {
    return 0;
  }

  int ans = 1;

  for (int i = 0; i < root->children.size(); i++)
  {
    ans = countNodes(root->children[i]) + ans;
  }

  return ans ;
}


int height(TreeNode<int> *root)
{
  if (root == NULL)
  {
    return 0;
  }

  int ans = 0;

  for (int i = 0; i < root->children.size(); i++)
  {
    int t=  height(root->children[i]) ;
    if(t>ans){
      ans=t;
    }
  }

  return ans+1 ;
}

void printAtLevelK(TreeNode<int> *root,int k ){

  if(root == NULL){
    return;
  }
  if( k==0){
    cout<< root->data;
    return;
  }

  for(int i =0 ; i<root->children.size();i++){
    printAtLevelK(root->children[i],k-1);
  }



}

int countLeaf( TreeNode<int> *root){
  if(root == NULL){
    return 0;

  }

  if(root->children.size() == 0){
    return 1;
  }

  int ans =0;

  for(int i = 0 ; i< root->children.size();i++){
   ans = countLeaf(root->children[i])+ans;
  }

  return ans;

}


int main()
{

  TreeNode<int> *root = takeInputLevelWise();

  Pair<int> temp = nodeWithMax(root);

  cout<<temp.ptr->data<<endl;
  cout<<temp.sum<<endl;


  // cout << countNodes(root);
  // printAtLevelK(root,2);
  // cout<< height(root);
  // cout<<countLeaf(root);

  // delete Root // THis alos waorks as it will call the destructor
  return 0;
}
