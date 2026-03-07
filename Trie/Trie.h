#include "TrieNode.h"
#include <string>
using namespace std;
class Trie
{

  TrieNode *root;

public:
  Trie()
  {
    root = new TrieNode('\0');
  }

  void helperInsertWord(TrieNode *root, string word)
  {
    if (word.size() == 0)
    {
      root->isTerminal = true;

      return;
    }

    // small calculation

    int index = word[0] - 'a';

    TrieNode *child;
    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }
    else
    {
      child = new TrieNode(word[0]);
      root->children[index] = child;
    }

    // Recursive call
    helperInsertWord(child, word.substr(1));
  }

  void insertWord(string word)
  {
    helperInsertWord(root, word);
  }

  bool helperSerachWord(TrieNode *root, string word)
  {

    if (word.length() == 0)
    {
      bool temp = root->isTerminal;
      return temp;
    }

    int index = word[0] - 'a';
    TrieNode *child = root->children[index];

    if (child == NULL)
    {

      return false;
    }

    bool temp = helperSerachWord(root->children[index], word.substr(1));

    return temp;
  }

  bool searchWord(string word)


  {

    bool temp = helperSerachWord(root, word);

    return temp;
  }

  void helperDeleteWord(TrieNode* root,string word){

    if(word.length() == 0){
      root->isTerminal = false;
      return;
    }

    // 
    int index =  word[0]- 'a';

    TrieNode * child ;


    if( root->children[index] != NULL){
      child = root->children[index];
  
    }else{
       
       return;
    }

    helperDeleteWord(child,word.substr(1));
    
    if(child->isTerminal == false){
      for(int i=0 ; i< 26;i++){

        return ;
      }
    }

    delete child;
    root->children[index] = NULL;

  }


  void deleteWord(string word){

    helperDeleteWord(root,word);
  }


};