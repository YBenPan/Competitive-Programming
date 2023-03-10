#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--)
    {
      string str;
      cin >> str;
      bool flag = true;
      char first = str[0];
      for (int i = 1; i < str.size() && flag; ++i)
        if (str[i] != first)
          flag = false;
      if (flag || str.size() == 1 || str.size() == 2)
        {
          for (auto i : str)
            cout << i;
          cout << endl;
          continue;
        }

      cout << str[0];
      for (int i = 1; i < str.size(); ++i)
        {
          if (str[i] == str[i - 1])
            if (str[i - 1] == '0')
              cout << 1;
            else
              cout << 0;
          cout << str[i];
        }
      cout << endl;
    }
  return 0;
}
