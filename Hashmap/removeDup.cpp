#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;


vector<int> removeDuplicates(int* a,int n) {
    unordered_map<int, bool> seen;
    vector<int> result;

    for (int i = 0; i < n; i++) {
        if(seen.count(a[i] )> 0){
          continue;

        }
        seen[a[i]] = true;
        result.push_back(a[i]);

    }

    return result;
}

int main(){

  int a[] = {1, 2, 3, 2, 4, 1, 5};
  int n = sizeof(a) / sizeof(a[0]);

  vector<int> uniqueElements = removeDuplicates(a, n);

  for(int i =0;i< uniqueElements.size(); i++){
    cout << uniqueElements[i] << " ";
  } 

  return 0;
}