#include <vector>
using namespace std;

class PriorityQueue
{

  vector<int> pq;

public:
  PriorityQueue()
  {
  }

  bool isEmpty()
  {

    return pq.size() == 0;
  }

  int getSize()
  {

    return pq.size();
  }

  int getMin()
  {

    if (isEmpty())
    {
      return 0;
    }

    return pq[0];
  }

  void insert(int ele)
  {

    pq.push_back(ele);
    int childIndex = pq.size() - 1;

    while (childIndex > 0)
    {
      int parentIndex = (childIndex - 1) / 2;

      if (pq[childIndex] < pq[parentIndex])
      {
        int temp = pq[childIndex];
        pq[childIndex] = pq[parentIndex];
        pq[parentIndex] = temp;
      }
      else
      {

        break;
      }
      childIndex = parentIndex;
    }
  }

  int remove()
  {

    if (isEmpty())
    {

      return 0;
    }

    int temp = pq[0];

    pq[0] = pq[pq.size() - 1];

    pq.pop_back();

    int p = 0;
    int c1 = 2 * p + 1;
    int c2 = 2 * p + 2;

    while (c1< pq.size())
    {
      int minIndex = p;
      if (pq[minIndex] > pq[c1])
      {
        minIndex = c1;
      }
      if (c2<pq.size()&&pq[minIndex] > pq[c2])
      {

        minIndex = c2;
      }
      if(minIndex == p){
        break;
      }
      int temp = pq[minIndex];
      pq[minIndex] = pq[p];
      pq[p] = temp;

      p = minIndex;
      int c1 = 2 * p + 1;
      int c2 = 2 * p + 2;
    }

      return temp ;
  }


};