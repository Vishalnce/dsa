bool checkReduant(string str)
{

  stack<char> s;

  int count = 0;

  for (int i = 0; i < str.size(); i++)
  {

    count = 0;

    if (str[i] == ']' || str[i] == '}' || str[i] == ')')
    {

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
    }
    else
    {
      s.push(str[i]);
    }
  }

  if (count <= 1)
  {
    return true;
  }

  return false;
}
