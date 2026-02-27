#include <iostream>
using namespace std;

#include <stack>
#include <string>

void revStack(stack<int> &s)
{

  if (s.empty())
    return;

  int n = s.top();

  s.pop();

  revStack(s);

  stack<int> temp;

  while (!s.empty())
  {
    int t1 = s.top();
    s.pop();
    temp.push(t1);
  }

  s.push(n);

  while (!temp.empty())
  {
    int t1 = temp.top();
    temp.pop();
    s.push(t1);
  }
}

void takeInput(stack<int> &s)
{
  int n;
  cout << "Enter the number of ele" << endl;
  cin >> n;
  for (int i = 0; i < n; i++)
  {

    int number;
    cout << "Enter the number" << endl;
    cin >> number;
    s.push(number);
  }
}

void print(stack<int> s)

{
  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}

bool checkReduant(string str)
{

  stack<char> s;

  for (int i = 0; i < str.size(); i++)
  {



    if (str[i] == ']' || str[i] == '}' || str[i] == ')')
    {
          int count = 0;

      char temp = s.top();

      s.pop();

      while (temp != '[' && temp != '{' && temp != '(')

      {
        count++;

        if (s.empty())
          break;

        temp = s.top();
        s.pop();
      }

      if (count <= 1)   // check here
        return true;
    }
    else
    {
      s.push(str[i]);
    }
  }

    return false;
}



int main()
{

  string str;
  cout << "Enter the string" << endl;
  cin >> str;
  if (checkReduant(str))
  {
    cout << "Redundant" << endl;
  }
  else
  {
    cout << "Not Redundant" << endl;
  }

  // stack<int> s;

  // s.push(1);
  // s.push(2);
  // s.push(3);
  // s.push(4);
  // print(s);
  // // takeInput(s);
  // revStack(s);
  // print(s);
}