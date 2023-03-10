#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str;
  cin >> str;
  vector<int> AB;
  vector<int> BA;
  for (int i = 0; i < (int)str.size() - 1; ++i)
    {
      if (str[i] == 'A' && str[i + 1] == 'B')
        {
          for (auto j : BA)
            if (j < i - 1)
              {
                cout << "YES" << endl;
                return 0;
              }
          AB.push_back(i);
        }
      else if (str[i] == 'B' && str[i + 1] == 'A')
        {
          for (auto j : AB)
            if (j < i - 1)
              {
                cout << "YES" << endl;
                return 0;
              }
          BA.push_back(i);
        }
    }
  cout << "NO" << endl;
  return 0;
}
