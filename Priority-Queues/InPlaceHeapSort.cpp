#include <iostream>
using namespace std;

void inplaceHeapSort(int *pq, int n)
{

  // build the heap

  for (int i = 1; i < n; i++)
  {
    int childIndex = 1;

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

  // delete the heap

  int size = n;

  int temp = pq[0];

  pq[0] = pq[n - 1];
  pq[n - 1] = temp;

  size--;

  int p = 0;
  int c1 = 2 * p + 1;
  int c2 = 2 * p + 2;

  while (c1 < size)
  {
    int minIndex = p;
    if (pq[minIndex] > pq[c1])
    {
      minIndex = c1;
    }
    if (c2 < size && pq[minIndex] > pq[c2])
    {

      minIndex = c2;
    }
    if (minIndex == p)
    {
      break;
    }
    int temp = pq[minIndex];
    pq[minIndex] = pq[p];
    pq[p] = temp;

    p = minIndex;
    int c1 = 2 * p + 1;
    int c2 = 2 * p + 2;
  }
}

/// inplace heap sort give the in the desecong ordfer 

int main()
{

  return 0;
}