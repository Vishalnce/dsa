#include <iostream>
using namespace std;
#include<cmath>

// dp



int minCostDp(int **a,int m,int n){
  int ** output = new int*[m];

  for( int i =0 ; i<m;i++){

    output[i]=new int [n];


  }

  // fill the last cell

  output[m-1][n-1] = a[m-1][n-1];

  // fill the last row( tight to left )
  for( int j =n-2;j>=0;j--){

    output[m-1][j] = a[m-1][j]+  output[m-1][j+1]; 

  }

  // fill the last colum( bootom to top )

  for( int i =m-2;i>=0;i--){
    
    output[i][n-1] = a[i][n-1] + output[i+1][n-1] ;

  }

  for( int i =m-2;i>=0;i--){

    for( int j = n-2 ; j>=0;j--){

      output[i][j] = min(output[i][j+1] ,min(output[i+1][j+1],output[i+1][j])) + a[i][j];
    }
  }

  return output [ 0 ][0];

}


int helperMinCostMemo(int **a, int **b, int m, int n, int i, int j)
{
  if (i == m - 1 && j == n - 1)
  {
    return a[i][j];
  }

  if (i >= m || j >= n)
  {

    return INT_MAX;
  }

  if(b[i][j] == -1){

    return  b[i][j];
  }

  int x = helperMinCost(a, m, n, i, j + 1);
  int y = helperMinCost(a, m, n, i + 1, j + 1);
  int z = helperMinCost(a, m, n, i + 1, j);

 int t= min(x, min(y, z)) + a[i][j];


 return t;
}

// memorisation

int minCostMemo(int **a, int m, int n)
{

  int **b = new int *[m];

  for (int i = 0; i < m; i++)
  {

    b[i] = new int[n];
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {

      b[i][j] = -1;
    }
  }

  int temp = helperMinCostMemo(a, b, m, n, 0, 0);

  return temp;
}

// recursive call

int helperMinCost(int **a, int m, int n, int i, int j)
{

  if (i == m - 1 && j == n - 1)
  {
    return a[i][j];
  }

  if (i >= m || j >= n)
  {

    return INT_MAX;
  }

  int x = helperMinCost(a, m, n, i, j + 1);
  int y = helperMinCost(a, m, n, i + 1, j + 1);
  int z = helperMinCost(a, m, n, i + 1, j);

  return min(x, min(y, z)) + a[i][j];
}

int minCost(int **a, int m, int n)
{

  int temp = helperMinCost(a, m, n, 0, 0);

  return temp;
}

int main()
{

  return 0;
}