#include <iostream>

using namespace std;

#include "BinaryTreeNode.h"
#include <queue>

void printTree(BinaryTreeNode<int> * root){
  
  if(root ==NULL){
    return ; 
  }

    cout<<root->data<<":" ;
  if(root->left ){
    cout << "L" <<root->left->data;
  }
    if(root->right ){
    cout << "R" <<root->left->data;
  }

  cout<<endl;


  printTree(root->left);
  printTree(root->right);


}


// TODO: print level wise


BinaryTreeNode<int>*  takeInput(){
  int rootData;
  cout << "Enter root data" << endl;
  cin >> rootData;

  if(rootData == -1){
    return NULL;
  }

  BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);

  BinaryTreeNode<int> * leftChild = takeInput();
  BinaryTreeNode<int> * rightChild = takeInput();

  root->left = leftChild;
  root->right = rightChild;

  return root;

  


}

BinaryTreeNode<int>*  takeInputLevelWise(){
   int rootData;
  cout << "Enter root data" << endl;
  cin >> rootData;

  if(rootData == -1){
    return NULL;
  }

  BinaryTreeNode<int> * root = new BinaryTreeNode<int> (rootData);

  queue<BinaryTreeNode<int> *> pendingNodes;

  pendingNodes.push(root);

  while (pendingNodes.size() != 0){

    BinaryTreeNode<int> * front = pendingNodes.front();
    pendingNodes.pop();

    int leftChildData;
    cout << "Enter left child data of " << front->data << endl;
    cin >> leftChildData;

    if(leftChildData != -1){
      BinaryTreeNode<int> * leftChild = new BinaryTreeNode<int>(leftChildData);
      front->left = leftChild;
      pendingNodes.push(leftChild);
    }

    int rightChildData;
    cout << "Enter right child data of " << front->data << endl;
    cin >> rightChildData;

    if(rightChildData != -1){
      BinaryTreeNode<int> * rightChild = new BinaryTreeNode<int>(rightChildData);
      front->right = rightChild;
      pendingNodes.push(rightChild);
    }
  }
  

  return root;  
  

}

int numberOfNodes(BinaryTreeNode<int> * root ){

  if( root == NULL){
    return 0;

  }

  int ans = 1;

  int left = numberOfNodes(root->left);
  int right = numberOfNodes(root->right);

  return ans + left + right;

}

void inOrder(BinaryTreeNode<int> * root){

  if(root == NULL){
    return ;
  }

  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);

} 

BinaryTreeNode<int> * buildTreeHelper(int * in,int* pre,int inS,int inE,int preS,int preE){
  
  if(inS>inE){
    return NULL;
  }

  int rootData = pre[preS];
  int rootIndex = -1;
  for(int i=inS;i<=inE;i++){
    if(in[i] == rootData){
      rootIndex = i;
      break;
    }
  }
  int lInS = inS;
  int lInE = rootIndex -1;
  int lPreS = preS + 1;
  int lPreE = lInE - lInS + lPreS;
  int rPreS = lPreE + 1;
  int rPreE = preE;
  int rInS = rootIndex + 1;
  int rInE = inE;

  BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);

  root->left = buildTreeHelper(in,pre,lInS,lInE,lPreS,lPreE);
  root->right = buildTreeHelper(in,pre,rInS,rInE,rPreS,rPreE);

  return root;

   

}



BinaryTreeNode<int>* buildTree( int *in,int *pre,int size){

  return buildTreeHelper(in,pre,0,size-1,0,size-1);



}

pair<int,int> heightDiameter(BinaryTreeNode<int> * root){

  if(root == NULL){
    pair<int,int> p;
    p.first = 0;
    p.second = 0;
    return p;
  }

  pair<int,int> leftAns = heightDiameter(root->left);
  pair<int,int> rightAns = heightDiameter(root->right);

  int ld = leftAns.second;
  int lh = leftAns.first;
  int rd = rightAns.second;
  int rh = rightAns.first;

  int height = 1 + max(lh,rh);
  int diameter = max(lh+rh,max(ld,rd));

  pair<int,int> p;
  p.first = height;
  p.second = diameter;

  return p;
}

//   TODO mirroe binary tree
int main() {

  // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
  BinaryTreeNode<int> * root = takeInputLevelWise()  ;




  printTree(root);
  cout <<numberOfNodes(root);
  delete root;
  return 0;
}

