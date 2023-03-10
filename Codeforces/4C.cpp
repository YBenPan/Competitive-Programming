#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  map<string, int> username;
  string str;
  for (int i = 0; i < n; ++i)
    {
      cin >> str;
      auto it = username.find(str);
      if (it != username.end())
        {
          it->second++;
          cout << it->first << it->second << endl;
        }
      else
        {
          username.insert(make_pair(str, 0));
          cout << "OK" << endl;
        }
    }
  return 0;
}
