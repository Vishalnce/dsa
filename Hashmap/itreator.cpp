#include<iostream>
#include<unordered_map>
using namespace std;
#include <vector>





int main(){
  unordered_map<string, int> ourmap;

  ourmap["abc"] = 1;
  ourmap["abc2"] = 2;
  ourmap["abc3"] = 3;

  ourmap["abc4"] = 4;

  ourmap["abc5"] = 5;
  ourmap["abc6"] = 6;


  unordered_map<string,int> :: iterator it = ourmap.begin();

  while(it != ourmap.end()){
    cout << "Key: " << it->first << " Value: " << it->second << endl;
    it++;
  }

  //find 
  // find -> it reurn the iterator 

  unordered_map<string,int> :: iterator it2 = ourmap.find("abc2");
  ourmap.erase(it2); // it does not support  erase the element from it2 to it2+2

  vector<int> v;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);

  vector<int>:: iterator it3 = v.begin();

  while(it3 != v.end()){
    cout << *it3 << endl;
    it3++;
  }


 




  return 0;
}