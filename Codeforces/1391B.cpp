#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
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
      int n, m;
      cin >> n >> m;
      char g[105][105];
      int cnt = 0;
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
          {
            cin >> g[i][j];
            if (i == n - 1 && g[i][j] == 'D') cnt++;
            if (j == m - 1 && g[i][j] == 'R') cnt++;
          }
      cout << cnt << endl;
    }

  return 0;
}
