#include <iostream>
using namespace std;
#include <queue>

// BFS 0 connected components
void printBFS(int **edge, int n, int sv,bool *visited)
{

  queue<int> q;

 
  q.push(sv);
  visited[sv] = true;

  while (!q.empty())
  {

    int t = q.front();
    q.pop();

    cout << t << endl;

    for (int i = 0; i < n; i++)
    {
      if (i == t)
      { // we are asking if there is ege from  0 to  0
        continue;
      }
      if (edge[t][i] == 1)
      {
        int temp = i;
        if (!visited[temp])
        {
          q.push(temp);
          visited[temp] = true;
        }
      }
    }
  }
}

//  ( DFS for 0 connected component
void printDFS(int **edge, int n, int sv, bool *visited)
{

  cout << sv << endl;
  visited[sv] = true;
  for (int i = 0; i < n; i++)
  {
    if (i == sv)
    {
      continue;
    }
    if (edge[sv][i] == 1)
    {
      if (visited[i])
      {
        continue;
      }
      printDFS(edge, n, i, visited);
    }
  }
}

// DFS
void DFS(int **edges, int n)
{

  bool *visited = new bool[n];
  for (int i = 0; i < n; i++)
  {
    visited[i] = false;
  }
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      printBFS(edges, n, i, visited);
    }
  }


  delete[] visited;
}


// BFS 


void BFS(int **edges, int n)
{

  bool *visited = new bool[n];
  for (int i = 0; i < n; i++)
  {
    visited[i] = false;
  }
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      printBFS(edges, n, i, visited);
    }
  }


  delete[] visited;
}

int main()
{

  int n;

  int e;
  cout << "Enter the number of vertices";

  cin >> n;

  cout << "Enter the edge";
  cin >> e;

  int **edge = new int *[n];

  for (int i = 0; i < n; i++)
  {

    edge[i] = new int[n];

    for (int j = 0; j < n; j++)
    {

      edge[i][j] = 0;
    }
  }

  // take graph input

  for (int i = 0; i < e; i++)
  {

    int f, s;
    cin >> f >> s;
    edge[f][s] = 1;
    edge[s][f] = 1;
  }

  // making array for marking visted or not

  bool *visited = new bool[n];
  for (int i = 0; i < n; i++)
  {

    visited[i] = false;
  }

 
  for (int i = 0; i < n; i++)
  {

    delete[] edge[i];
  }

  delete[] edge;

  delete[] visited;
  return 0;
}