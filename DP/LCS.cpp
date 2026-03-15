#include <iostream>
using namespace std;

#include <string>


// dp 

int LCSDp(string s,string t){

  int m  = s.size();
  int n = t.size();

  int ** output = new int*[m+1];

  for( int i = 0;i<=m ;i++){
    output[i] = new int [n+1];


  }


  // firll first row

  for( int i=0 ;i <=n;i++){
    output[0][i]=0;
  }

  
  for( int i=0 ;i <=m;i++){
    output[i][0]=0;
  }


  for( int i =1;i<=m;i++){
    for( int j=1;j<=n;j++){

      if(s[m-i] == t[n-j]){  // thisis important line 

        output[i][j] = 1+ output[i-1][j-1];

      }
      else{
        int a = output[i-1][j];
        int b = output[i][j-1];

        int c = output[i-1][j-1];

        output[i][j] = max(a,max(b,c));


      }


    }
  }
  

  return output[m][n];


}


// memorisation

int helperLCS(string s, string t, int **o)
{

  if (s.length() == 0 || t.length() == 0)
  {
    return 0;
  }

  int m = s.size();
  int n = t.size();
  if (o[m][n] != -1)
  {
    return o[m][n];
  }

  int ans;
  if (s[0] == t[0])
  {

    int temp = helperLCS(s.substr(1), t.substr(1), o);
    ans = temp + 1;
  }
  else
  {

    int t1 = helperLCS(s, t.substr(1), o);
    int t2 = helperLCS(s.substr(1), t, o);
    int t3 = helperLCS(s.substr(1), t.substr(1), o);

    int temp = max(t1, max(t2, t3));

    ans = temp;
  }
  o[m][n] = ans;
  return ans;
}

int LCSmemo(string s, string t)
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

  int temp = helperLCS(s, t, b);

  return temp;
}

//  incelusing recusrion

int LCS(string s, string t)
{

  if (s.length() == 0 || t.length() == 0)
  {
    return 0;
  }

  if (s[0] == t[0])
  {
    int temp = LCS(s.substr(1), t.substr(1));
    return temp + 1;
  }
  else
  {

    int t1 = LCS(s, t.substr(1));
    int t2 = LCS(s.substr(1), t);
    int t3 = LCS(s.substr(1), t.substr(1));

    int temp = max(t1, max(t2, t3));

    return temp;
  }
}

int main()
{

  string s = "abc";
  string t = "dbc";

  cout << LCSmemo(s, t);
  return 0;
}