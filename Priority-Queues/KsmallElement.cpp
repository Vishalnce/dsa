#include <iostream>
using namespace std;
#include <queue>

void KSmallEle(int *a, int n, int k)
{

  priority_queue<int> pq;

  for (int i = 0; i < k; i++)
  {
    pq.push(a[i]);
  }
  for (int i = k; i < n; i++)
  {
    int temp = pq.top();
    if (temp > a[i])
    {
      pq.pop();
      pq.push(a[i]);
    }
  }

  while (!pq.empty())
  {
    cout << pq.top() << endl;
    pq.pop();
  }
}

int main()
{

  int a[] = {10, 14, 6, 4, 5};
  int k = 3;
  KSmallEle(a, 5, k);

  return 0;
}