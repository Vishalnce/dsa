#include <iostream>
using namespace std;
#include <queue>



int main(){

  priority_queue<int> pq ; //  max prioeirty queue

  pq.push(16);
  pq.push(1);

  pq.push(45);
  pq.push(5);
  pq.push(2);
  pq.push(89);
  pq.push(8);

  cout<< " Size "<< pq.size() <<endl;
  cout<< " Top"<< pq.size() <<endl;

  while(!pq.empty()){

    cout<<pq.top()<<endl;
    pq.pop();
  }


  return 0;
}