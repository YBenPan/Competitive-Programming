#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  int sx[205], sy[205], fx[205], fy[205];
  int max_x = 0;
  int max_y = 0;
  for (int i = 0; i < k; ++i)
    {
      cin >> sx[i] >> sy[i];
      max_x = max(max_x, sx[i]);
      max_y = max(max_y, sy[i]);
      sx[i] = 1;
      sy[i] = 1;
    }
  for (int i = 0; i < k; ++i)
    {
      cin >> fx[i] >> fy[i];
    }
  if (m == 1 && n == 1)
    {
      cout << 0 << endl;
      return 0;
    }
  string ans;
  for (int i = 0; i < max_x; ++i)
    ans.push_back('U');
  for (int i = 0; i < max_y; ++i)
    ans.push_back('L');
  for (int i = 1; i <= n; ++i)
    {
      for (int j = 1; j <= m - 1; ++j)
        if (i % 2 == 1)
          ans.push_back('R');
        else ans.push_back('L');
      if (i < n) ans.push_back('D');
    }
  cout << ans.length() << endl;
  for (char i : ans)
    cout << i;
  cout << endl;
  return 0;
}
