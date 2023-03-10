#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    {
      int n0, n1, n2;
      cin >> n0 >> n1 >> n2;
      vector<char> ans;
      if (n1 == 0 && n2 == 0)
        {
          for (int i = 1; i <= n0 + 1; ++i)
            cout << 0;
          cout << endl;
          continue;
        }
      else if (n0 == 0 && n1 == 0)
        {
          for (int i = 1; i <= n2 + 1; ++i)
            cout << 1;
          cout << endl;
          continue;
        }
      char cur;
      if (n1 % 2 == 0)
        cur = '1';
      else
        cur = '0';
      ans.push_back(cur);
      for (int i = 1; i <= n1 - 1; ++i)
        {
          if (cur == '0') cur = '1'; else cur = '0';
          ans.push_back(cur);
        }
      for (int i = 1; i <= n0; ++i)
        ans.push_back('0');
      for (int i = 1; i <= n2 + 1; ++i)
        ans.push_back('1');
      for (char i : ans)
        cout << i;
      cout << endl;
    }

  return 0;
}
