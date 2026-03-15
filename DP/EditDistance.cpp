#include <iostream>
#include <future>
using namespace std;
#include <string>

// dp

int editDistanceDP(string s, string t)
{
  int m = s.size();
  int n = t.size();

  int **o = new int *[m + 1];

  for (int i = 0; i <= m; i++)
  {

    o[i] = new int[n + 1];

    for (int j = 0; j <= n; j++)
    {

      o[i][j] = -1;
    }
  }

  o[0][0] = 0;

  // fill trhe firs tcol

  for (int i = 1; i <= n; i++)
  {
    o[0][i] = i;
  }

  for (int i = 1; i <= m; i++)
  {
    o[i][0] = i;
  }

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (s[m - i] == t[n - j])
      {
        o[i][j] = o[i - 1][j - 1];
      }
      else
      {

        int a = o[i - 1][j];
        int b = o[i][j - 1];
        int c = o[i - 1][j - 1];
        o[i][j] = min(a, min(b, c)) + 1;
      }
    }
  }

  return o[m][n];
}

int helperEditDistMemo(string s, string t, int **o)
{

  int m = s.size();
  int n = t.size();
  if (s.length() == 0 || t.length() == 0)
  {

    return max(s.length(), t.length());
  }

  int ans = 0;

  if (o[m][n] != -1)
  {
    return o[m][n];
  }
  if (s[0] == t[0])
  {
    int temp = helperEditDistMemo(s.substr(1), t.substr(1), o);
    ans = temp;

    o[m][n] = ans;
    return ans;
  }
  else
  {
    int x = helperEditDistMemo(s.substr(1), t, o);
    int y = helperEditDistMemo(s, t.substr(1), o);
    int z = helperEditDistMemo(s.substr(1), t.substr(1), o);

    int temp = min(x, min(y, z));

    ans = temp + 1;

    o[m][n] = ans;
    return ans;
  }
}

// using memo
int editDisMemo(string s, string t)
{

  int m = s.size();
  int n = t.size();

  int **b = new int *[m + 1];

  for (int i = 0; i <= m; i++)
  {

    b[i] = new int[n + 1];

    for (int j = 0; j <= n; j++)
    {

      b[i][j] = -1;
    }
  }

  int temp = helperEditDistMemo(s, t, b);

  return temp;
}

// using recursion

int editDis(string s, string t)
{

  if (s.length() == 0 || t.length() == 0)
  {

    return max(s.length(), t.length());
  }

  int ans = 0;
  if (s[0] == t[0])
  {
    int temp = editDis(s.substr(1), t.substr(1));
    ans = temp;
    return ans;
  }
  else
  {
    int x = editDis(s.substr(1), t);
    int y = editDis(s, t.substr(1));
    int z = editDis(s.substr(1), t.substr(1));

    int temp = min(x, min(y, z));

    ans = temp + 1;
    return ans;
  }
}

int main()
{

  string s = "abcsdddddddwsdfdsdfdsfsdfsdfsdfsfqweqwesdfsd";
  string t = "dxxdd";

  auto f1 = async(launch::async, editDis, s, t);
  auto f2 = async(launch::async, editDisMemo, s, t);
  auto f3 = async(launch::async, editDistanceDP, s, t);

  cout << "Recursion: " << f1.get() << endl;
  cout << "Memo: " << f2.get() << endl;
  cout << "DP: " << f3.get() << endl;

  return 0;

}