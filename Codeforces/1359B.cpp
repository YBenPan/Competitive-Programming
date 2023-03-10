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
      int n, m, x, y;
      cin >> n >> m >> x >> y;
      char a[105][1005];
      int cnt = 0;
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
          {
            cin >> a[i][j];
            if (a[i][j] == '.') cnt++;
          }
      if (y >= 2 * x)
        cout << cnt * x << endl;
      else
        {
          long long tot = 0;
          for (int i = 0; i < n; ++i)
            {
              for (int j = 0; j < m - 1; ++j)
                {
                  if (a[i][j] == '.' && a[i][j + 1] == '.')
                    {
                      tot += y;
                      a[i][j] = '*';
                      a[i][j + 1] = '*';
                    }
                  else if (a[i][j] == '.')
                    {
                      tot += x;
                      a[i][j] = '*';
                    }
                }
              if (a[i][m - 1] == '.')
                {
                  tot += x;
                  a[i][m - 1] = '*';
                }
            }
          cout << tot << endl;
        }
    }
  return 0;
}
