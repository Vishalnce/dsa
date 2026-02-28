#include <iostream>
using namespace std;

#include <vector>

template <typename T>
class TreeNode {

  public:

  T data;
  vector<TreeNode*> children; // okay we have not mentioned the <TreeNode <int> * > as if parent will be int the its child also be int 

  TreeNode(T data){
    this->data = data;
  }

  ~TreeNode(){
    for(int i =0;i<children.size();i++){
      delete children[i];
    }
  }


};
