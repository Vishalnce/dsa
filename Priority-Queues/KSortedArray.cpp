#include <iostream>
using namespace std;
#include <queue>

void kSortedArray(int *a, int n, int k)
{

  priority_queue<int> pq;

  for (int i = 0; i < k; i++)
  {
    pq.push(a[i]);
  }

  int j = 0;
  for (int i = k; i < n; i++)
  {
    a[j] = pq.top();
    pq.pop();
    pq.push(a[i]);
    j++;
  }

  while (!pq.empty())
  {
    a[j] = pq.top();
    pq.pop();
    j++;
  }
}

int main()
{

  int a[] = {10, 15, 6, 4, 5};
  int k = 3;
  kSortedArray(a, 5, k);

  for (int i = 0; i < 5; i++)
  {

    cout << a[i] << " ";
  }

  return 0;
}