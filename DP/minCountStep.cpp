#include <iostream>
using namespace std;

// dp

int minStepCountDp(int n)
{

  int *arr = new int[n + 1];

  arr[0] = 0;
  arr[1] = 1;

  for (int i = 2; i <= n; i++)
  {

    int j = 1;

    int minDp = INT_MAX;

    while (j * j <= i)
    {

      int temp = 1 + arr[i - j * j];

      minDp = min(temp, minDp);

      
      j++;
    }

    arr[i] = minDp;
  }

  return arr[n];
}

int helperMinStepCount2(int n, int *arr)
{

  if (n <= 0)
  {
    return 0;
  }

  int i = 1;

  int minRec = INT_MAX;

  // if(arr[n] != -1)  this can optimise furhter
  //   return arr[n];

  while (i * i <= n)
  {

    if (arr[n - i * i] != -1)
    {
      minRec = min(minRec, arr[n - i * i]);
    }
    else
    {
      int temp = helperMinStepCount2(n - i * i, arr);
      minRec = min(minRec, temp);
    }

    i++;
  }

  arr[n] = minRec + 1;

  return minRec + 1;
}

// memorisation
int minStepCount2(int n)
{

  int *arr = new int[n + 1];

  for (int i = 0; i <= n; i++)
  {

    arr[i] = -1;
  }

  int temp = helperMinStepCount2(n, arr);
  return temp;
}

// normal recusrion
int minStepCount(int n)
{

  if (n <= 0)
  {
    return 0;
  }

  if (n == 1)
  {
    return 1;
  }

  int i = 1;

  int minRec = INT_MAX;

  while (i * i <= n)
  {

    int temp = minStepCount(n - i * i);
    minRec = min(minRec, temp);
    i++;
  }

  return minRec + 1;
}

int main()
{

  return 0;
}