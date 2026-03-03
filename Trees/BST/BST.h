#include "BinaryTreeNode.h"
#include <cstddef>
#include <algorithm>
using namespace std;
#include <climits>

class BST {

  BinaryTreeNode<int> * root;

  public:

  BST(){
    root = NULL;
  }
   
  ~BST(){
    delete root;

  }
  private:

  BinaryTreeNode<int>* helpInsertData(BinaryTreeNode<int>* root ,int data){

    if( root == NULL){
      BinaryTreeNode<int>* temp = new BinaryTreeNode<int>(data);
      return temp;
    }

    if(root->data>data){
        BinaryTreeNode<int>* temp = helpInsertData(root->left,data);
        
        root->left=temp;



        return root;

    }else{  

      BinaryTreeNode<int>* temp = helpInsertData(root->right,data);
      root->right= temp;

      return root;


    }




  }



  int minimum(BinaryTreeNode<int> * root){

  if(root==NULL){
    return INT_MAX;
  }

  int left = minimum(root->left);
  int right = minimum(root->right);

  int rootData = root->data;




  return min(rootData,min(left,right));




}

  BinaryTreeNode<int> * helpDeleteData(BinaryTreeNode<int>*root,int data){

    if( root== NULL){

      return NULL;

    }
    if(data>root->data){
    BinaryTreeNode<int> * rightNode = helpDeleteData(root->right,data);
      root->right = rightNode;

    }else if(data < root->data){
    BinaryTreeNode<int>*  leftNode = helpDeleteData(root->left,data);
      root->left = leftNode;
    }else{

      // Case 1: Leaf
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        if (root->left == NULL) {
            BinaryTreeNode<int>* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == NULL) {
            BinaryTreeNode<int>* temp = root->left;
            delete root;
            return temp;
        }

      


     int temp = minimum(root->right);

     root->data = temp;

     root->right=  helpDeleteData(root->right,temp);



    }

     return root;
    }




  


  public:

  void deleteData(int data ){
     BinaryTreeNode<int>* temp = helpDeleteData(root,data);
    return;

    
  }

  void insertData(int data){

    BinaryTreeNode<int>* temp = helpInsertData(root,data);

    return;

  }
  private:

  bool hasDataHelper(BinaryTreeNode<int> * node,int data){

    if(node==NULL){
      return false;
    }

    if(node->data == data){
      return true;
    }else if(node->data > data){
      return hasDataHelper(node->left,data);
    }else{
      return hasDataHelper(node->right,data);
    }

  }


  public:

  bool hasData(int data){
    return hasDataHelper(root,data);
  }

  









};