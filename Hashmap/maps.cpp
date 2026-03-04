#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;



int main(){

  unordered_map<string, int> myMap;

  //insert 
  pair<string, int> p1("apple", 10);
  myMap.insert(p1);
  myMap["banana"] = 20;

  // find or access
  cout << myMap["apple"] << endl; // 10
  cout << myMap.at("banana") << endl; // 20

  // cout<< myMap.at("orange") << endl; // throws an exception

  cout << "Size of map: " << myMap.size() << endl; // 2
  cout<< myMap["orange"] << endl; // orange is not present, it will be inserted with default value 0 otherwise it will give 0;

  cout<< " size :" << myMap.size() << endl; // 3

  // check presence
  if( myMap.count("apple") > 0){
    cout << "apple is present" << endl;
  } 

  // erase

  myMap.erase("banana");

  if( myMap.count("banana") > 0){
    cout << "banana is  present" << endl;
  }else{
    cout << "banana is not present" << endl;
  }

  return 0;
}