#include <bits/stdc++.h>
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
      int n;
      cin >> n;
      string str;
      cin >> str;
      map<pair<int, int>, int> vis;
      pair<int, int> cur = {0, 0};
      int l = 0, r = 200000;
      bool flag = false;
      vis[cur] = 0;
      for (int i = 0; i < str.size(); ++i)
        {
          if (str[i] == 'L') cur.first--;
          else if (str[i] == 'R') cur.first++;
          else if (str[i] == 'U') cur.second++;
          else cur.second--;
          if (vis.find(cur) != vis.end())
            if (i - vis[cur] + 1 < r - l + 1)
              {
                l = vis[cur];
                r = i;
                flag = true;
              }
          vis[cur] = i + 1;
        }
      if (!flag)
        cout << -1 << endl;
      else
        cout << l + 1 << " " << r + 1 << endl;
    }
  return 0;
}
